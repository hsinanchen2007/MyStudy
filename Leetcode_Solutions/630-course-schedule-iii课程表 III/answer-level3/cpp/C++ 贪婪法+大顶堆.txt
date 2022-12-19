```
class Solution {
public:
    static bool comp(const vector<int>& v1, const vector<int>& v2) {
        return v1[1] < v2[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), comp);
        priority_queue<int> q;
        int dur = 0;
        for (int i = 0; i < courses.size(); ++i) {
            if (dur + courses[i][0] <= courses[i][1]) {
                dur += courses[i][0];
                q.push(courses[i][0]);
            } else if (!q.empty() && q.top() > courses[i][0]) {
                dur += courses[i][0] - q.top();
                q.pop();
                q.push(courses[i][0]);
            }
        }
        return q.size();
    }
};
```
