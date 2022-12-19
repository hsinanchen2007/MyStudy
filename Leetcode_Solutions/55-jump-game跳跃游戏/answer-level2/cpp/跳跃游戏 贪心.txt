解题思路：
1.设一个变量为可以到达的最远距离（从零开始），从数组的第一个位置开始;
2.若变量的值大于等于数组的长度-1，则返回true，否则看数组的下一位;
3.直到数组的位置大于变量的值，说明永远不可能到达最后的位置，所有返回false;

```
    class Solution {
        public:
            bool canJump(vector<int>& nums) {
            int tp = nums.size() - 1;
            int y = 0;
            for(int i = 0; i <= y; i++)
            {
                if(nums[i] + i >= tp)
                    return true;
                y = max(y,nums[i] + i);
            }
            return false;
            }
    };
```

