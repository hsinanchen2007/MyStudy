### 解题思路
此处撰写解题思路
![268.jpg](https://pic.leetcode-cn.com/e7c11fbf0a4848fc5c19d2ec7e0c600d37807ae46a725b11b69dfbaadee86123-268.jpg)

### 代码

```cpp
//method 2:位运算
//两种情况：
//（1）连续的，结果在末尾（特殊情况）
//（2）结果在中间


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int max = 0;
        int ans = 0;
        for(vector<int>::iterator ite = nums.begin(); ite != nums.end(); ++ite)
        {
            ans ^= *ite;
            if(*ite > max)
            {
                max = *ite;
            }
        }
        for(int i = 0; i <= max; ++i)
        {
            ans ^= i;
        }

        if(max < nums.size())
        {
            return (max+1);
        }
        else
        {
            return ans;
        }
    }
};








```