因为只有最晚开始的限制，所以这些课都是可以拼成一个连续序列的，那么首先对最晚开始时间排个序，再维护一个大顶堆，每次遇到能缩短当前开始时间的课程就拿去替换当前最晚开始时间的课程。
```c++
class Solution {
public:
  int scheduleCourse(vector<vector<int>>& courses) {
    sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
      if (a[1] == b[1]) return a[0] < b[0];
      return a[1] < b[1];
    });
    int last = 0;
    priority_queue<int> pq;
    for (int i = 0; i < courses.size(); i++) {
      last += courses[i][0];
      pq.emplace(courses[i][0]);
      if (last > courses[i][1]) {
        last -= pq.top();
        pq.pop();
      }
    }
    return pq.size();
  }
};

```