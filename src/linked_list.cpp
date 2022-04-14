#include "assignment/linked_list.hpp"

#include <utility> // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    if (size_ <=  1){
      return;
    }

    Node* current = front_;
    Node* prev  = nullptr;
    while (current != back_) {
      Node* node = current->next;
      current->next = prev;
      prev = current;
      current = node;
    }
    current->next = prev;
    Node* node = back_;
    back_ = front_;
    front_ = node;
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    reverse_recursive_helper(front_, nullptr);
    Node* node = front_;
    front_ = back_;
    back_ = node;
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    if (curr == nullptr) {
      return;
    }
    reverse_recursive_helper(curr->next, curr);
    curr->next = prev;
  }

}  // namespace assignment
