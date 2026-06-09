### 解题思路
数字的位数是偶数，即数字对应的字符串的长度是偶数，使用to_string函数

### 代码

```cpp
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int num: nums)
        {
            if(to_string(num).size()%2 == 0)//字符串的长度是偶数即可
                ans++;
        }
        return ans;

    }
};
```