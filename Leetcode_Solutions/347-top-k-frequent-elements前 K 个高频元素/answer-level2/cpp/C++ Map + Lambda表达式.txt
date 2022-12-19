思路：存到map里计数，然后结构体排序按照出现次数从大到小排序。

为什么用lambda表达式：因为map的key-value结构只能对key进行重载，所以需要手写一个对value的排序

为了贯彻懒得喜欢写短代码的习惯，果断选择lambda表达式


```
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>m;
        for(auto num : nums)    //  存到哈希结构里
            m[num]++;
        vector<pair<int,int >>v;
        vector<int>ans;
        for(auto it : m)        //  存到用于对value排序的容器里
            v.push_back(make_pair(it.first,it.second));
        sort(v.begin(),v.end(),[](pair<int,int> &a,pair<int,int> &b)->bool{return a.second>b.second;}  );
        //  对容器中的pair按照出现次数从大到小排序
        /*
            C++ 的lambda表达式和java的略有区别
        */
        for(int i=0;k;++i,--k)
            ans.push_back(v[i].first);

        return ans;
    }
};
```
