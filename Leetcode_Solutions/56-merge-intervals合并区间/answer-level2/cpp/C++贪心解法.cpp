首先按照区间的第一个的大小对区间进行从大到小的排序，例子所给区间的都已经排好了。
然后用num来动态的维护当前的区间在结果中的编号，如果下一个区间的下限比当前区间的上限要大，则进行插入。如果下一个区间的下限小于等于当前区间的上限，就判断下一个区间的上限与当前区间的上限的大小。
下面就是我的代码。根据实际情况发现，排序的cmp函数需要带上static关键字，否则会报错。并且cmp函数的形参中最好使用引用，如果不使用引用，每回排序都要生成临时的数组，时间复杂度很高。
```
static bool cmp(vector<int> &v1,vector<int> &v2)
    {
        return v1[0]<v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int len=intervals.size();
        if(len<2)
            return intervals;
        sort(intervals.begin(),intervals.end(),cmp);
        int num;
        for(int i=0;i<len;i++)
        {
            if(i==0)
            {
                ans.push_back(intervals[i]);
                num=0;
                continue;
            }
            if(intervals[i][0]<=ans[num][1] && intervals[i][1]>=ans[num][1])
            {
                ans[num][1]=intervals[i][1];
            }
            else if(intervals[i][0]>ans[num][1])
            {
                ans.push_back(intervals[i]);
                num++;
                continue;
            }
        }
        return ans;
    }
```
