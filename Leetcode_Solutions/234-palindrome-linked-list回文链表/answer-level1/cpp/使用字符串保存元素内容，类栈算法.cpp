### 解题思路
因为受制于空间复杂度为常数，所以不能去考虑哈希表的方式或者栈的方式来处理回文链表；然后又想到了双指针，尾和头同时开始，但是又因为是单向链表，又失败；
最后考虑使用一个string 去保存，前半部分的元素，然后扫描后半部分的元素，与string尾部元素进行匹配，如果匹配，删除string尾部元素，继续匹配下一个，如果不匹配，直接返回false； 
算法其中使用了string的rfind()，目的是找到一个空格也就是最后一个元素的位置；
substr是分离出元素的值；

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
    bool isPalindrome(ListNode* head) {
        //空间复杂度被限制为常数，不允许使用哈希表
        //那么只考虑到使用双指针，但是又是单向链表
        //考虑使用一个string去保存前一半的整数
        if(head==nullptr) return true;
        if(head->next==nullptr) return true;
        string res="";
        int count=0;
        ListNode* start=head;
        ListNode* end=head;
        while(end!=nullptr)//计算总长度
        {
            ++count;
            end=end->next;
        }
        int half=count/2;//前进长度的一半步
        while(half)//前面一半的数字加到字符串中
        {
            --half;
            res.append(" ");
            res+=to_string(start->val);
            start=start->next;
        }
        //如果是奇数，再走一步，因为中间是什么数都不影响回文结构
        if(count%2==1) start=start->next;
        while(start!=nullptr)
        {
            int index=res.rfind(" ");
		    string value = res.substr(index+1);
            if(value == to_string(start->val))
            {
                res.erase(index);//删除最后一个元素
                start=start->next;
            }
            else return false;
        }
        return true;
    }
};
```