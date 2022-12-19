### 直接法
将链表的值复制到数组中，再使用双指针进行比较

```cpp
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector <int> nums;
        ListNode* p=head;
       
        while(p)     
        {
            nums.push_back(p->val);            //将链表的值全部赋值到数组中
            p=p->next;
        }
        int len=nums.size();
        for(int i=0;i<len/2;i++)
            if(nums[i]!=nums[len-1-i])
                return false;
        
        return true;
    }
};
```