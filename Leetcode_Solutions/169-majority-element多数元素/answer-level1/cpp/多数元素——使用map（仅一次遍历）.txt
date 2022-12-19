### 解题思路
1. 首先初始化一个多数—_max=0及其出现次数cnt=0
2. 遍历nums中的元素，map用来记录每个元素出现的次数，
3. 同时将每个元素的出现次数与cnt的当前值比较，若比当前值大，则更新_max为当前值，cnt为当前值的出现次数；
4. 该方法比上一种可以少遍历一次map映射表；

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
    if(nums.size() < 0) return -1;
    map<int,int> res;
    int _max = 0;
    int cnt = 0;
    
    for(auto i : nums)
    {
       res[i]++;
       if(res[i] > cnt)
       {
           _max = i;
           cnt = res[i];
       }     
    }
     return _max;
    }
};
```