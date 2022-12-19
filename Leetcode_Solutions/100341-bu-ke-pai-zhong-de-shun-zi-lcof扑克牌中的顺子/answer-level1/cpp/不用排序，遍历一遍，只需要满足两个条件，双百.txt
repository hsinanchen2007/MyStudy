满足两个条件：
1. 除0之外没有相同的数
2. 除0之外最大值和最小值之差小于等于4
同时满足这两个条件就是顺子，不满足就不是顺子

代码里建立了一个哈希表用于判断是否有除0之外的重复数字。

```
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        //数组中除零之外的其他值，没有重复的，且最大值减去最小值<=4，那么就为顺子
        unordered_map<int ,bool> numsmap;
        int maxnum=-1, minnum=14;
        for(int num:nums)
        {
            if(num!=0) 
            {
                if(numsmap.find(num)!=numsmap.end()) return false;
                numsmap[num]=true;
                maxnum=max(maxnum,num);
                minnum=min(minnum,num);
            }
        }
        return (maxnum-minnum<=4);
    }
};
```
