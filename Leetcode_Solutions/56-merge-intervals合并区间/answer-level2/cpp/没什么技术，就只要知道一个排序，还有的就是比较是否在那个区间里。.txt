### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return {};
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        vector<int>vec=intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=vec[1]){     //一开始我也是这个想法，可是感觉应该不会这么普通的方法
                vec[1]=max(intervals[i][1],vec[1]);
            }
            else{
                ans.push_back(vec);
                vec.clear();
                vec=intervals[i];
            }
        }
        ans.push_back(vec);
        return ans;
    }
};
```