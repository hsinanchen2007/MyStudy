```
class Solution {
public:
  ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr) return head; // empty
    if (head->next == nullptr) return head; // one node
    // at least 2 nodes
    ListNode* oddHead = head;
    ListNode* oddTail = oddHead;
    ListNode* evenHead = head->next;
    ListNode* evenTail = evenHead;
    ListNode* Next = evenTail;
    while (Next != nullptr) {
      Next = Next->next;
      oddTail->next = Next;
      if (Next == nullptr) {
        evenTail->next = nullptr;
        break;
      } else {
        oddTail = Next;
        Next = Next->next;
        evenTail->next = Next;
        evenTail = Next; 
      }
    } 
    oddTail->next = evenHead;
    return oddHead;
  }
};
```