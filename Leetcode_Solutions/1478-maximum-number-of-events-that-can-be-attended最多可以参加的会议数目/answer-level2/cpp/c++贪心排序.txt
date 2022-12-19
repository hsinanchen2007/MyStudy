
`
class Solution {
 public:
  int maxEvents(vector<vector<int>>& events) {
    std::sort(events.begin(), events.end(),
              [](const vector<int>& a, const vector<int>& b) {
                return (a[1] != b[1]) ? a[1] < b[1] : a[0] < b[0];
              });

    int res = 0;
    unordered_map<int, bool> visit;
    for (int i = 0; i < events.size(); ++i) {
      for (int day = events[i][0]; day <= events[i][1]; ++day) {
        if (!visit[day]) {
          ++res;
          visit[day] = true;
          break;
        }
      }
    }
    return res;
  }
};
`
