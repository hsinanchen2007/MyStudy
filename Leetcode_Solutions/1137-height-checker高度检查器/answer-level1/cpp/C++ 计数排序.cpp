```c++
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        array<int, 101> m{0};
        for (int h : heights) {
            m[h]++;
        }

        // i as pointer, c as result
        int i = 0, c = 0;
        for (int h : heights) {
            while (!m[i]) {
                i++;
            }
            if (i != h) {
                c++;
            }
            m[i]--;
        }
        return c;
    }
};
```