### 解题思路
思路不难，有细节需要注意一点，二维数组的排序

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      if(intervals.size() < 2) return intervals;
      vector<vector<int>> res;
      //需要先把左节点排序
      sort(intervals.begin(), intervals.end(), less<vector<int>>());

      int left = intervals[0][0], right = intervals[0][1];
      for(int i = 1; i < intervals.size(); i++){
        if(intervals[i][0] > right){
          res.push_back({left, right});
          left = intervals[i][0];
          right = intervals[i][1];
        }else{
          //[[1,4],[2,3]]这种case
          right = max(right, intervals[i][1]);
        }
      }

      res.push_back({left, right});
      return res;  
    }
};
```