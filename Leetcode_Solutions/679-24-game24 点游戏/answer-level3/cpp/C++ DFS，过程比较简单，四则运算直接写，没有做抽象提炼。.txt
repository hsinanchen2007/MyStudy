### 解题思路
使用深度遍历。
遍历的结束条件，只剩下两个数。
这时候不管能否计算出24点，都要结束递归调用。
判断是否能生成24，四则运算都试一遍，能成功 is24 = true。

Dfs()思路：
1）判断数组长度是否为2，如果是2：计算两个数是否生成24点，退出Dfs函数。
2）判断是否已经生成24点，如果已经生成，没有比较继续计算，直接返回。
3）从数组中每次挑选两个数，把+-*/都计算一遍。
4）不参与计算的数，和计算的结果，合成数组，递归调用Dfs()。
5）在计算的时候，不用考虑括号。

结果：4ms，7.8M


### 代码

```cpp
class Solution {
public:
    void IsOk(vector<double>& nums)
    {      
        if (fabs(nums[0] + nums[1] - TWOFOUR) < minValue) {            
            is24 = true;            
        } else if (fabs(nums[0] - nums[1] - TWOFOUR) < minValue || fabs(nums[1] - nums[0] - TWOFOUR) < minValue) {            
            is24 = true;            
        } else if (fabs(nums[0] * nums[1] - TWOFOUR) < minValue) {            
            is24 = true;            
        } else if ((nums[1] != 0 && fabs(nums[0] - nums[1] * TWOFOUR) < minValue) || (nums[1] != 0 && fabs(nums[1] - nums[0] * TWOFOUR) < minValue)) {             is24 = true;
        }        
    }
    void Dfs(vector<double>& nums)
    {
        if (nums.size() == 2) {
            IsOk(nums);
            return ;
        }        
        if (is24) {
            return ;
        }
        vector<double>nextnums;
        vector<double>secondnums;
        double nextValue, value1, value2;
        for (int i = 0; i < nums.size(); i++) {
            nextnums = nums;
            value1 = nums[i];
            nextnums.erase(nextnums.begin() + i);
            for (int j = 0; j < nextnums.size(); j++) {
                secondnums = nextnums;
                value2 = nextnums[j];
                secondnums.erase(secondnums.begin() + j);
                nextValue = value1 + value2;           // 加法
                secondnums.push_back(nextValue);
                Dfs(secondnums);
                secondnums.pop_back();
                nextValue = value1 - value2;           // 减法， 循环时Value1， Value2会互换
                secondnums.push_back(nextValue);
                Dfs(secondnums);
                secondnums.pop_back();
                nextValue = value1 * value2;           // 乘法
                secondnums.push_back(nextValue);
                Dfs(secondnums);
                secondnums.pop_back();
                if (value2 == 0) break;                // 除法， 循环时value1， value2会互换
                nextValue = value1 / value2;
                secondnums.push_back(nextValue);
                Dfs(secondnums);
                secondnums.pop_back();
            }
        }
    }
    bool judgePoint24(vector<int>& nums) 
    {
        if (nums.size() != 4) return false;
        for (int i = 0; i < nums.size(); i++) {
            ser.push_back(nums[i]);
        }        
        Dfs(ser);
        if (is24) {
            return true;
        }
        return false;
    }
private:
    bool is24 = false;
    const int TWOFOUR = 24;
    vector<double>ser;
    const double minValue = 0.0000001;
};
```