## 问题描述

给出一个无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

[无效的图片地址](https:liyiping.cn/media/editor/2020-01-13-18-33-08%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE_20200113183337519792.png)

[插入区间](https://leetcode-cn.com/problems/insert-interval/ "插入区间")

## 解决方法

### 插入后合并

由于区间是有序的，所以将新区间插入到适当位置，之后合并即可。

建议先做一下[合并区间](https://leetcode-cn.com/problems/merge-intervals/ "合并区间")这道题

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty())
            return {};
        //sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();++i){
            if(res.back()[1]>=intervals[i][0]){
                res.back()[1]=max(res.back()[1],intervals[i][1]);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int size=intervals.size();
        if(size==0){
            intervals.push_back(newInterval);
            return intervals;
        }
        int i=0;
        for(;i<size;i++){
            if(intervals[i][0]>newInterval[0]){
                intervals.insert(intervals.begin()+i,newInterval);
                break;
            }
        }
        if(i==size)intervals.push_back(newInterval);

        return merge(intervals);
    }
};
```

### 负优化

本想着在原数组上做修改，时间和空间复杂度会降低一点，没想到的时候，时间直接1200ms了，想想也是，毕竟vector嘛，删除操作其实还是很耗时的

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int size=intervals.size();
        if(size==0){
            intervals.push_back(newInterval);
            return intervals;
        }
        int i=0;
        for(;i<size;i++){
            if(intervals[i][0]>newInterval[0]){
                intervals.insert(intervals.begin()+i,newInterval);
                break;
            }
        }
        if(i==size)intervals.push_back(newInterval);
        i=1;
        while(i<=size){
            if(intervals[i-1][1]>=intervals[i][1]){
                intervals.erase(intervals.begin() + i);
                size--;
            }else if(intervals[i-1][1]>=intervals[i][0]){
                intervals[i-1][1]=intervals[i][1];
                intervals.erase(intervals.begin() + i);
                size--;
            }else{
                i++;
            }
        }
        return intervals;
    }
};



```

个人网站：[https://liyiping.cn](https://liyiping.cn)