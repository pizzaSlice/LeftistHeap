/*****************************************
 * Instructions
 *  - Replace 'uwuserid' with your uWaterloo User ID
 *  - Select the current calendar term and enter the year
 *  - List students with whom you had discussions and who helped you
 *
 * uWaterloo User ID:  uwuserid @uwaterloo.ca
 * Submitted for ECE 250
 * Department of Electrical and Computer Engineering
 * University of Waterloo
 * Calender Term of Submission:  (Winter|Spring|Fall) 201N
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *
 * The following is a list of uWaterloo User IDs of those students
 * I had discussions with in preparing this project:
 *    -
 *
 * The following is a list of uWaterloo User IDs of those students
 * who helped me with this project (describe their help; e.g., debugging):
 *    -
 *****************************************/

#ifndef DYNAMIC_QUEUE_H
#define DYNAMIC_QUEUE_H

#ifndef nullptr
#define nullptr 0
#endif

#include <algorithm>
#include "ece250.h"
#include "Exception.h"

template <typename Type>
class Dynamic_queue {
	private:
		int initial_capacity;
		int array_capacity;
		Type * array;
		int ihead;
		int itail;
		int entry_count;
		int arrsize;

	public:
		Dynamic_queue( int = 10 );
		Dynamic_queue( Dynamic_queue const & );
		~Dynamic_queue();

		Type head() const;
		int size() const;
		bool empty() const;
		int capacity() const;

		void swap( Dynamic_queue & );
		Dynamic_queue &operator=( Dynamic_queue );
		void enqueue( Type const & );
		Type dequeue();
		void clear();

	// Friends

	template <typename T>
	friend std::ostream &operator<<( std::ostream &, Dynamic_queue<T> const & );
};

template <typename Type>
Dynamic_queue<Type>::Dynamic_queue( int n ):
initial_capacity( std::max( n, 1 ) ),
array_capacity( initial_capacity ),
array( new Type[initial_capacity] ),
ihead( 0 ),
itail( 0),
entry_count( 0 ) {
	arrsize = 0;

}

template <typename Type>
Dynamic_queue<Type>::Dynamic_queue( Dynamic_queue const &queue ):
initial_capacity( queue.initial_capacity ),
array_capacity( queue.array_capacity ),
array( new Type[array_capacity] ),
ihead( queue.ihead ),
itail( queue.itail ),
entry_count( queue.entry_count ) {
	/*std::cout << ihead<<std::endl;
	std::cout << itail;*/
	arrsize = queue.arrsize + 1;
	std::cout << arrsize;
	for(int i = ihead; i < itail; i++){
		array[i % array_capacity] = queue.array[i % array_capacity];
		std::cout << array[i % array_capacity];
	}
}
template <typename Type>
Dynamic_queue<Type>::~Dynamic_queue() {
	delete [] array;
}

template <typename Type>
int Dynamic_queue<Type>::size() const {
	return arrsize;
}

template <typename Type>
int Dynamic_queue<Type>::capacity() const {
	return array_capacity;
}

template <typename Type>
bool Dynamic_queue<Type>::empty() const {
	if(arrsize==0)
		return true;
	else 
		return false;
}

template <typename Type>
Type Dynamic_queue<Type>::head() const {
	Type toreturn = 0;
	//try{
		//if(arrsize == 0){
			//throw underflow();
		//}
		//else
			toreturn = array[ihead];
	//}catch(underflow u){
		//std::cout << "Underflow error";
	//}
	return toreturn;
}

template <typename Type>
void Dynamic_queue<Type>::swap( Dynamic_queue<Type> &queue ) {
	std::swap( initial_capacity, queue.initial_capacity );
	std::swap( array_capacity, queue.array_capacity );
	std::swap( array, queue.array );
	std::swap( ihead, queue.ihead );
	std::swap( itail, queue.itail );
	std::swap( entry_count, queue.entry_count );
}

template <typename Type>
Dynamic_queue<Type> &Dynamic_queue<Type>::operator=( Dynamic_queue<Type> rhs ) {
	swap( rhs );

	return *this;
}

template <typename Type>
void Dynamic_queue<Type>::enqueue( Type const &obj ) {
	if(arrsize == array_capacity){
		Type * temp = new Type[array_capacity * 2];
		for(int i = 0; i < arrsize; i ++)
			temp[i] = array[(ihead + i) % array_capacity];
		delete [] array;
		array = temp;
		ihead = 0;
		itail = arrsize;
		array_capacity = array_capacity * 2;
	}
	arrsize++;
	array[itail % array_capacity] = obj;
	itail ++;
}

template <typename Type>
Type Dynamic_queue<Type>::dequeue() {
	/*try{*/
		Type toreturn = array[ihead % array_capacity];
		ihead ++;
		/*if(arrsize < array_capacity/4){
			Type * temp = new Type[array_capacity / 2];
			for(int i = 0; i < arrsize; i ++)
				temp[i] = array[(ihead + i) % array_capacity];
			delete [] array;
			array = temp;
			ihead = 0;
			itail = arrsize;
			array_capacity = array_capacity/2;
		}*/
		/*if(arrsize == 0)
			throw underflow();*/
		arrsize--;
		return toreturn;
	/*}catch(underflow u){
			std::cout << "underflow error";
	}*/
}

template <typename Type>
void Dynamic_queue<Type>::clear() {
	Type * temp = new Type[initial_capacity];
	delete [] array;
	ihead = 0;
	itail = 0;
}

// You can modify this function however you want:  it will not be tested

template <typename Type>
std::ostream &operator<<( std::ostream &out, Dynamic_queue<Type> const &queue ) {
	// I don't know how you are implementing your queue so I cannot print it.
	// If you want, you can print whatever you want here and then call cout
	// in the driver.

	// Remember to redirect to out, e.g.,
	//      out << "Hello!";

	return out;
}

// Is an error showing up in ece250.h or elsewhere?
// Did you forget a closing '}' ?

#endif