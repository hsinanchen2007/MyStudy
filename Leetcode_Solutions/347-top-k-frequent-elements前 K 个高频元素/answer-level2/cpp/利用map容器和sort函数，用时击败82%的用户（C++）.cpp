### 解题思路
整体思路如下：
（1）利用map容器中的key保存数组nums中的数，利用value保存该数字出现的次数；
（2）将map中的key和value以pair的形式存入vector，并利用sort函数依据value的大小排序；
（3）将排序后的vector中每个pair元素的key值存进一个新的vector，返回该vector。
【注意】：
（1）在调用sort函数时，需要写一个仿函数（即map_compare），告诉sort()函数对于pair元素该如何排序；
（2）仿函数需要声明为静态，不写static会报错（有大佬出来解释一下原因吗？）；
（3）因为map默认不允许key值出现重复，因此map[key]++（即temp[nums[i]]++）可直接统计得到每个数组元素的出现次数。

### 代码

```cpp
class Solution 
{
public:
    static bool map_compare(pair<int,int> &a,pair<int,int>&b)  //这里仿函数要声明为静态，不然会报错
    {
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        map<int,int>temp;
        for (int i=0;i!=nums.size();i++)  //统计各元素的出现次数，作为value保存在map容器中
        {
            temp[nums[i]]++;
        }
        vector<pair<int,int>>vec;
        for (auto i:temp)
        {
            vec.push_back(make_pair(i.first,i.second));
        }
        sort(vec.begin(),vec.end(),map_compare);
        vector<int>result;
        for (int i=0;i!=k;i++)
        {
            result.push_back(vec[i].first);
        }
        return result;
    }
};
```