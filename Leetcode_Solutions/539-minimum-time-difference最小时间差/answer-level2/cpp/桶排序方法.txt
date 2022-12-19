![Screen Shot 2020-02-27 at 10.20.40 PM.png](https://pic.leetcode-cn.com/dde98750f01efc37e668ad22204aacf072dba345dc69b982087ae04d37574571-Screen%20Shot%202020-02-27%20at%2010.20.40%20PM.png)

桶排序在数据均匀分布的时候使用线性时间O(n)，稳定性也不错。

解题思路：
1. 将24个小时分为24个桶，相应把分钟压入桶中。
2. 每个桶内部排序一次，计算桶内的最小时间差。
3. 把每个桶的第一个元素和前一个非空桶的最后一个元素做计算。
4. 注意不要漏掉首个非空桶和最后一个非空桶的首尾元素计算。

```
class Solution {
public:
    void helper(vector<vector<int>> &buckets, int &h, int &ret){
        int tmp;
        for (int j=1; j<buckets[h].size(); j++){
            tmp=buckets[h][j]-buckets[h][j-1];
            ret=min(tmp, ret);
        }
    }
    int findMinDifference(vector<string>& timePoints) {
        /*timePoints={
            "01:39","10:26","21:43"
        };*/
        vector<vector<int>> buckets(24);
        int hour, minute;
        int ret=INT_MAX;
        int tmp;
        for (int i=0; i<timePoints.size(); i++){
            hour=stoi(timePoints[i].substr(0, 2));
            minute=stoi(timePoints[i].substr(3, 5));
            buckets[hour].push_back(minute);
        }

        int pre=-1;
        
        for (int i=0; i<24; i++){
            if (buckets[i].size()){
                sort(buckets[i].begin(), buckets[i].end());
                helper(buckets, i, ret);
                if (pre!=-1){
                    tmp=i*60+buckets[i][0]-pre*60-buckets[pre].back();
                    tmp=min(tmp, 1440-tmp);
                    ret=min(ret,tmp);
                }
                pre=i;
            }
        }

        int i=0;
        while (buckets[i].size()==0){
            i++;
        }
        if (pre>i){
                tmp=pre*60+buckets[pre].back()-i*60-buckets[i][0];
                tmp=min(tmp, 1440-tmp);
                ret=min(ret,tmp);
        }
        
        return ret;
    }
};
```

