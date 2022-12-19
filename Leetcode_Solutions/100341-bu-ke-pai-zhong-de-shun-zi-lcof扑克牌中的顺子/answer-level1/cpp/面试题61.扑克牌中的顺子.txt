### 解题思路
- 核心要点：设置bool型数组，检测有无出现重复牌；计算牌中最大和最小牌（除大小王），判断差值是否小于5
- 执行用时：8 ms, 在所有 C++ 提交中击败了22.39%的用户
- 内存消耗：10.3 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        vector<bool>check(14,false);
        int minval=14,maxval=0;
        for(int num:nums){
            if(num==0)continue;
            if(check[num]==true)return false;
            check[num]=true;
            minval=min(minval,num);
            maxval=max(maxval,num);
        }
        return maxval-minval+1<=5?true:false;
    }
};
```