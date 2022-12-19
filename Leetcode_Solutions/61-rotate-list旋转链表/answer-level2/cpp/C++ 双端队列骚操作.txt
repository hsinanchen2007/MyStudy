我是一个十分之不喜欢造轮子的人。。。所以能用STL现成的东西我就不自己写了。。。这可以用双端队列来做，每次拿一个队尾的放到队头就是了。。虽然空间复杂度很高但是好想啊哈哈哈哈
```
class Solution {
public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head) {
      return NULL;
    }
    deque<int>q;
    ListNode* p = head;
    int length = 0;
    while (p != NULL) {
      q.push_back(p->val);
      p = p->next;
      length++;
    }
    k = k % length; //减少操作次数
    while (k != 0) {
      int val = q.back();
      q.pop_back();
      q.push_front(val);
      k--;
    }
    p = head;
    while (p != NULL)
    {
      p->val = q.front();
      q.pop_front();
      p = p->next;
    }
    return head;
  }
};
```
