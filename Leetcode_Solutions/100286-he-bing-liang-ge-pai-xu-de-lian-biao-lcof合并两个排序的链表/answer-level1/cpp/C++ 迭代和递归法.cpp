### 解题思路
迭代法的思路，参考了[@huwt](/u/huwt/)
递归法的思路，参考自剑指offer课本
### 代码

#### 迭代法
```cpp
 class Solution {
 public:
	 ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		 if (l1 == nullptr) return l2;//特殊情况处理
		 if (l2 == nullptr) return l1;//特殊情况处理
		 ListNode* mergeHead = new ListNode(5);//定义头节点
		 ListNode* cur=mergeHead;//指向当前节点
		 while (l1!=nullptr&&l2!=nullptr)//循环进行，直到有一者出现null
		 {
			 if (l1->val<l2->val)//l1指向的节点值<l2指向的节点值
			 {
				 cur->next = l1;
				 l1 = l1->next;
			 }
			 else
			 {
				 cur->next = l2;
				 l2 = l2->next;
			 }
			 cur = cur->next;
		 }
		 cur->next = l1 == nullptr ? l2 : l1;
		 return mergeHead->next;
	 }
 };
```

#### 递归法

```cpp
class Solution {
public:
       ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
              //如果l1为空，则返回l2,如果l2为空，则返回l1
              if (l1==nullptr)
              {
                     return l2;
              }
              else if (l2 == nullptr)
              {
                     return l1;
              }
              ListNode* mergeHead=nullptr;
			 //将小的节点接在mergeHead后面
              if (l1->val<l2->val)
              {
                     mergeHead = l1;
                     mergeHead->next = mergeTwoLists(l1->next, l2);
              }
              else
              {
                     mergeHead = l2;
                     mergeHead->next = mergeTwoLists(l1, l2->next);
              }
              return mergeHead;
       }
};
```