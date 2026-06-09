```
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) 
    {
       vector<vector<int>>  rev;//数组储存着数组
       vector<int> res;//一维数组
       int limit=(target)/2;//考虑到至少有两个的情况 两个值不可能都大于它的中间值
       int sum=0;
       for(int i=1;i<=limit;++i)
       {
           for(int j=i; ;++j)
           {
             sum+=j;
             if(sum>target)
             {
                 sum=0;
                 break;
             }
             else if(sum==target)
             {
                  res.clear();//清空res
                 for(int k=i;k<=j;++k)
                 {
                    
                     res.emplace_back(k);
                 }
                 rev.emplace_back(res);
                 sum=0;
                 break;
             }
           }
       }
        return rev;//返回vector<vector<int>>类型数组
    }
};
```

由题意知道要求序列长度至少大于2  这个限制条件可以知道 两个数不可能都大于target的中间值 所以有了
int limit=(target)/2;限制条件 也正因为这个条件可知for循环的起点为int i=1； 即第二个元素开始
判断以它为起点的序列和 sum 是否等于 target 即可










