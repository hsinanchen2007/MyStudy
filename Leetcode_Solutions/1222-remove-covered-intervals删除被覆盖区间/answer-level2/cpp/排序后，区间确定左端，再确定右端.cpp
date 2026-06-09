执行用时 :
16 ms
在所有 C++ 提交中击败了99.27%的用户
内存消耗 :12 MB, 在所有 C++ 提交中击败了21.01%的用户
```
class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        return a[0]<b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int i,j;
        int ans=0;
        sort(intervals.begin(),intervals.end(),cmp);
        for(i=0;i<intervals.size();i++){
          int curl=intervals[i][0];
          int cure=intervals[i][1]; 
          for(j=i+1;j<intervals.size();j++){
              if(cure<intervals[j][1])break;
          }
          i=j-1;
          ans++;
        }
        return ans;
    }
};
```
