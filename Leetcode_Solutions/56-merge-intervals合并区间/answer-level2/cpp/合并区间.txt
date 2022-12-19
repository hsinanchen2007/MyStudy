### 思路
要合并最大区间就要知道区间的左值和右值，在此基础上又分为三类
- 右值大于当前[x,y]中的y
- 右值介于当前[x,y]
- 右值小于当前[x,y]中的x

- ##### 方法一
```
// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector<vector<int>>res;
//         int interval_length=intervals.size();
//         if(interval_length<=1)return intervals;//intervals<=1没有继续执行程序的必要
//         sort(intervals.begin(),intervals.end());//按第一个字符排序
//         int left=intervals[0][0],right=intervals[0][1];//left用来记录即将合并区间的最小值，right为即将合并区间的最大值
//         int count=1;
//         while(count<interval_length){
//             if(intervals[count][1]<=right){//如果当前[x,y]中y<right，直接跳过本轮循环
//                 count++;
//                 continue;
//             }
//             if(intervals[count][0]<=right){//如果当前[x,y]中x<=right<y,更新right
//                 right=intervals[count][1];
//                 continue;
//             }
//             if(intervals[count][0]>right){//如果当前[x,y]中x>right,合并区间
//                 res.push_back({left,right});
//                 left=intervals[count][0];//更新left
//                 right=intervals[count][1];//更新right
//             }
//             count++;
//         }
//         res.push_back({left,right});//由于合并区间的时候总是合并上一个，所以在循环结束之后，最后的区间并没有合并，要最后push进去
//         return res;
//     }
// };
```

- #####方法二(一的plus)
```
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(interval.size()<=1)return intervals;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();++i){
            if(res.back()[1]>=intervals[i][0])
                res.back()[1]=max(res.back()[1],intervals[i][1]);
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};
```


