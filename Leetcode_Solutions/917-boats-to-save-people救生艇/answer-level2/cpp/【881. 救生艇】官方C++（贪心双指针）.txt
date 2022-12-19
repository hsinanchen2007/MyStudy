## 思路
### 代码
```c++
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {        
        int L = 0, R = people.size() - 1, res = 0;
        sort(people.begin(), people.end());
        while (L <= R) {
            if (people[L] + people[R] <= limit) {
                ++L;
            }
            --R, ++res;
        }
        return res;
    }
};
```
