### 解题思路
参考别人
总体思路就是建立一个栈，把链表中的元素依次放入栈中，如果放入时栈非空，就把当前元素与栈中所有元素比大小（从栈顶开始），直到栈中元素比当前元素大，如果当前元素大于栈顶元素，就填写栈顶元素对应的res数组并把栈顶元素弹出。可以看出，栈中元素从底部到栈顶top单调递减

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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>res;
        stack<pair<int,int>>s;            //first是下标，second是值
        int count = 0;                    //记录下标
        while(head){
            res.push_back(0);             //占位，同时如果链表没有比当前元素大的元素话那就要在res中写0
            while(!s.empty() && head->val > s.top().second){  //将当前元素与栈内元素比大小
                res[s.top().first] = head->val;               //大于栈内元素的话就填写栈内元素对应的res
                s.pop();                                      //栈top对应的res已填，同时推动内层的while循环
            }
            s.push(make_pair(count++,head->val));             //把当前元素也写入栈       
            head = head->next;
        }
        return res;
    }
};
```