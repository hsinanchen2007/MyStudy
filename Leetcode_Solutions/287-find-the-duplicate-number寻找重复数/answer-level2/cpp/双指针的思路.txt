### 解题思路
仿照链表判断有还的思路，使用快慢指针

### 代码

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[0];
        int slow = nums[0];
        do 
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
        }while(fast!=slow);

        slow = nums[0];

        while(slow!=fast) 
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
       
    }
};
```