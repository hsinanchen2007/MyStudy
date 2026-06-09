就是两个两个判断，直接对原数组进行改变，最后输出结果。看图啦，随便拿一张纸写的，字很丑，见谅哟
![IMG_8549.JPG](https://pic.leetcode-cn.com/8d4109785c41455ac7d3b5ddf10bec0d88ed2745c4d1ef0b91fdcf490e58e6dd-IMG_8549.JPG)

```
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        if(intervals.empty())
            return intervals;
        vector<int> temp;
        int i=0;
        while(i<intervals.size()-1){
            if(intervals.size()==1)
                break;
            if(intervals[i][1]>=intervals[i+1][0]&& intervals[i][1] < intervals[i+1][1]){
                temp.push_back(intervals[i][0]);
                temp.push_back(intervals[i+1][1]);
                intervals.erase(intervals.begin()+i,intervals.begin()+i+2);
                intervals.insert(intervals.begin()+i,temp);
                temp.clear();
            }else if(intervals[i][1]>=intervals[i+1][0]&& intervals[i][1] >= intervals[i+1][1]){
                intervals.erase(intervals.begin()+i+1,intervals.begin()+i+2);
            }else{
                i++;
            }
        }
        return intervals;
        
    }
};
```

