![TIM截图20200210211310.jpg](https://pic.leetcode-cn.com/7f5f7e200188155a79016a4843d50ab26ce68ead5ac437a6b30cada98eedba16-TIM%E6%88%AA%E5%9B%BE20200210211310.jpg)


很明显，这道题可以通过两层循环来暴力破解，但这样就不符合使用栈的要求。

首先，我们设立一个存储链表节点数据的栈st, 这个栈用来存储一个节点以及之后小于它节点的数据，再设立一个存储结果的数组res，一个front指针，该指针作用之后会说到；遍历链表，同时将一个0插入数组res中用来占位，之后当栈为空并且当前链表的节点数值大于栈顶元素时，就要进行相关操作，反之继续将该链表数值压栈。

我们栈中存储的数据是要最终放到数组res中，因此如何定位相关数据对应的位置，这时front指针的作用就体现出来。 当要存储的位置不为0时，也就说明该位置已经有下一个最大的元素，此次front指针继续向数组左端运动；而当front前一处res的值为0时，说明该位置还未被发现它的下一个最大元素，此时将链表的当前节点数值赋给该front位置的res元素，之后出栈一次。

当链表遍历结束之后，res数组也就完成。总体时间复杂度为O(N)。

- 设立栈st, 数组res, 指示数组和链表对应位置的指针 i
- 遍历链表
- 每次遍历一个节点，就在数组res中添加一个元素，同时刷新front指针
- 当栈不为空，栈顶元素大于等于当前链表元素大小时，将当前链表元素压入栈st中
- 否则，当数组res[front - 1] 不为0时，front 指针继续向左前进；当数组res[front - 1] 为0时，将res[front-1] 赋值为当前链表节点数值


```
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        ListNode *node = head;
        stack<int> st;
        int i = 0;
        while(node){
            res.push_back(0);
            int front = i;
            while(!st.empty() && st.top() < node->val){
                if(res[front - 1] == 0){
                    res[--front] = node->val;
                    st.pop();
                }
                else{
                    --front;
                }
            }
            st.push(node->val);
            i++;
            node = node->next;
        }

        return res;
    }
};
```
