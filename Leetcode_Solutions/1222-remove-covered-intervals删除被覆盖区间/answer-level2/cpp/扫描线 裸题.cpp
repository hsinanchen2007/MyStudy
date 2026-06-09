```c++
class Solution {
  typedef pair<int, int>PII;
 public:

  static bool cmp(vector<int>& a, vector<int>& b) {
    return (a[0] != b[0]) ? (a[0] < b[0]) : (a[1] > b[1]);
  }

  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    const int n = intervals.size();
    sort(intervals.begin(), intervals.end(), cmp);
    int l = intervals[0][1], ans = 1;
    for(int i = 1; i < n; ++i) {
      if(intervals[i][1] > l)
        ans++, l = intervals[i][1];
    }
    return ans;
  }
};

```