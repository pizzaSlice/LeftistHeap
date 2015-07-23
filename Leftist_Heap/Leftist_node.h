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

#ifndef LEFTIST_NODE_H
#define LEFTIST_NODE_H

#include <algorithm>
// You may use std::swap and std::min

#ifndef nullptr
#define nullptr 0
#endif

template <typename Type>
class Leftist_node {
	private:
		Type element;
		Leftist_node *left_tree;
		Leftist_node *right_tree;
		int heap_null_path_length;

	public:
		Leftist_node( Type const & );

		Type retrieve() const;
		bool empty() const;
		Leftist_node *left() const;
		Leftist_node *right() const;
		int count( Type const & ) const;
		int null_path_length() const;

		void push( Leftist_node *, Leftist_node *& );
		void clear();
};

template <typename Type>
Leftist_node<Type>::Leftist_node( Type const &obj ):
element( obj ),
left_tree( nullptr ),
right_tree( nullptr ),
heap_null_path_length( 0 ) {
	// does nothing
}

// You may need this

template <typename Type>
bool Leftist_node<Type>::empty() const {
	return ( this == nullptr );
}

template <typename Type>
Type Leftist_node<Type>::retrieve() const {
	return element;
}

template <typename Type>
Leftist_node<Type> * Leftist_node<Type>::left() const {
	return left_tree;
}

template <typename Type>
Leftist_node<Type> * Leftist_node<Type>::right() const {
	return right_tree;
}

template <typename Type>
int Leftist_node<Type>::count(Type const & input) const {
	return 0;
}

template <typename Type>
int Leftist_node<Type>::null_path_length() const {
	return heap_null_path_length;
}

template <typename Type>
void Leftist_node<Type>::push(Leftist_node * new_heap, Leftist_node * & ptr_to_this) {
	if(ptr_to_this == nullptr){
		ptr_to_this = new_heap;
		return;
	}else if(element <= new_heap->retrieve()){
		right_tree -> push(new_heap, right_tree);

		if(left_tree){
			if(right_tree->null_path_length() > left_tree->null_path_length()){
				Leftist_node * temp = left_tree;
				left_tree = right_tree;
				right_tree = temp;
				heap_null_path_length = 1 + left_tree->null_path_length();
			}else{
				heap_null_path_length = 1 + right_tree->null_path_length();
			}
		}else{
				heap_null_path_length = 0;
				Leftist_node * temp = left_tree;
				left_tree = right_tree;
				right_tree = temp;
		}
	}else{
		ptr_to_this = new_heap;
		new_heap -> push(this, new_heap);
	}
}

template <typename Type>
void Leftist_node<Type>::clear() {
	if(this == nullptr)
		return;
	else{
		left_tree ->clear();
		right_tree ->clear();
		delete this;
	}
}

// You must implement everything

#endif