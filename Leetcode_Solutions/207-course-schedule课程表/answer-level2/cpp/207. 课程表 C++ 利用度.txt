### 解题思路
类似题目：课程表II https://leetcode-cn.com/problems/course-schedule-ii/
算法都是一样的

### 代码

```cpp
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> indegree = vector<int>(numCourses, 0);
        vector<int> result;
        unordered_map<int, vector<int>> coursemap;
        deque<int> buff;

        for (auto course : prerequisites) {
            indegree[course[0]]++;
            coursemap[course[1]].push_back(course[0]) ;
        }

        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                buff.push_back(i);
            }
        }

        while (!buff.empty()) {
            int length = buff.size();
            for (int i = 0; i < length;i++){
                int curcourse = buff.front();
                result.push_back(curcourse);
                buff.pop_front();
                for(auto num: coursemap[curcourse]){
                    indegree[num]--;
                    if(indegree[num] == 0){
                        buff.push_back(num);
                    }

                }
            }
        }

        if(result.size() != numCourses){
            return false;
        }

        return true;
    }
};
```