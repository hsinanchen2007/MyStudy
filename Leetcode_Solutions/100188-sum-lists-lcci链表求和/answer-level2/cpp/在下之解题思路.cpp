// 菜鸡第一次写题解

跟传统小学学的手算加法一样。既然链表表示的数已被翻转，那么每次对两个数进行相加，然后存大于10的部分，将个位数设为答案的一个数。

此题跟另一题[两数相加](https://leetcode-cn.com/problems/add-two-numbers/)一模一样，那边比这边题解和代码都多很多，而且有些有图，简洁易明。

以下是我的代码：
执行用时: 28   ms, 在所有 C++ 提交中击败了 34.78% 的用户
内存消耗: 10.5 MB, 在所有 C++ 提交中击败了100.00% 的用户
  ```
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode *sum, *cur, *prev;
      int sur = 0;
      int dig;

      dig = l1->val + l2->val;
      sur = dig / 10;
      sum = new ListNode(dig % 10);
      cur = sum;

      l1 = l1->next;
      l2 = l2->next;

      while (l1 != NULL || l2 != NULL){
          dig = sur;
          if (l1 != NULL) dig += l1->val;
          if (l2 != NULL) dig += l2->val;
          
          sur = dig / 10;
          prev = cur;
          cur = new ListNode(dig % 10);
          prev->next = cur;
          
          if (l1 != NULL) l1 = l1->next;
          if (l2 != NULL) l2 = l2->next;
      }

      if (sur > 0){
          prev = cur;
          cur = new ListNode(sur);
          prev->next = cur;
      }
      return sum;
}
```
