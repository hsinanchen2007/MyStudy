### 解题思路
自定义一种新的大小比较标准，即通过比较两个数字m和n拼接成的数字mn和nm的相对大小来定义m和n的大小。
e.g. if(mn > nm) -> m > n 

最后将然后按照该比较标准升序排列即可。

该算法的正确性需要证明：
	1. 该大小比较标准是有效的，满足自反性，对称性和传递性
    2. 排序之后拼接所得数字就是最小的数字（可借助于反证法）

### 代码

```cpp
class Solution {
public:
    string minNumber(vector<int>& nums) {
        // cmp函数中，如果返回True，表示要把序列(X,Y)中X放Y前
        sort(nums.begin(), nums.end(), cmp);
        string res;
        for(auto n:nums)
            res += to_string(n);
        return res;
    }
    static bool cmp(int a, int b){
        string A = to_string(a) + to_string(b);
        string B = to_string(b) + to_string(a);
        return A < B;
    }
};
```
### 复杂度
时间复杂度O(nlogn)
