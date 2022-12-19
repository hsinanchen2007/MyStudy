### 解题思路
双指针，循环了两遍，竟然击败了100%的用户
![WX20200321-214712.png](https://pic.leetcode-cn.com/564575011939fd62ba54a95181c22d38c5ba308120d32484364adc78f2ed052e-WX20200321-214712.png)


### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty())
            return 0;

        int count = 0;
        for(auto t:nums){
            if(t==val)
                ++count;
        }

        int start = 0;
        int end = nums.size() - 1;
        while(start != end){
            while(start != end && nums[end] == val){
                --end;
            }

            while(start != end && nums[start] != val){
                ++start;
            }

            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
        }
        return nums.size() - count;
    }
};
```