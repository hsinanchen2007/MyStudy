![TIM截图20200119174845.png](https://pic.leetcode-cn.com/b358c4af329a68d79a88bd04e32a9106fdbeef43cc635ace94c7fb516744924b-TIM%E6%88%AA%E5%9B%BE20200119174845.png)

#### 解题思路
通过画图如下：
![两两交换节点思路.jpg](https://pic.leetcode-cn.com/e424b2aa54462d9aad1dc7c7d931641da2fe7b54fa9c57765253a79b302cc4cb-%E4%B8%A4%E4%B8%A4%E4%BA%A4%E6%8D%A2%E8%8A%82%E7%82%B9%E6%80%9D%E8%B7%AF.jpg)


### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode * pre_head = new ListNode(0);
        pre_head->next = head;
        ListNode * pre = pre_head;

        while(head && head->next){
        	head = head->next;
        	
        	pre->next->next = head->next;

        	head->next = pre->next;

        	pre->next = head;

            //注意设置新的pre和head位置，
        	pre = pre->next->next;

        	head = pre->next;   
        }

        ListNode * res = pre_head->next;
        delete pre_head;
        return res;
    }
};
```