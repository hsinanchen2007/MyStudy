### 分享一个递归方法
1. 首先扫描求出链表长度。
2. 然后套入递归函数：
  函数接受参数：当前检查的链表长度，当前头节点，内递归函数对应的链表尾节点。  **注意我的代码中这三个都是引用**
  返回当前是否是回文链表

3. 递归结束条件即为：当前长度<=2 （应当考虑到可能题目输入链表的空的情况哦）

```cpp
class Solution {
private:
    //递归方法
    //参数：length当前链表长度，这是个引用，直接内部修改
    //preNode当前链表头节点，这是个引用，直接内部修改
    //rightNode: 内递归对应的链表尾节点，这是个指针引用，递归函数内部会将其修改为当前链表尾节点

    //返回：是否是回文链表
    bool isPalindromeWithLength(int& length, ListNode*& preNode, ListNode*& rightNode){
        if (length <= 1){
            rightNode = preNode;
            return true;
        }
        else if (length == 2){
            rightNode = preNode->next;
            return (preNode->val == preNode->next->val);
        }
        else{
            length-=2;
            bool innerRet = isPalindromeWithLength(length, preNode->next, rightNode);
            rightNode = rightNode->next;
            return (innerRet && preNode->val == rightNode->val);
        }
    }
public:
    bool isPalindrome(ListNode* head) {
        //先求长度
        int length = 0;
        ListNode* pre = head;
        while(pre){
            pre = pre->next;
            length++;
        }
        //然后套递归
        ListNode* mid;
        pre = head;
        return isPalindromeWithLength(length, pre, mid);
    }
};
```


