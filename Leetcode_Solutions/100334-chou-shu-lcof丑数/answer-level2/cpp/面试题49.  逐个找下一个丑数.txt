```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v;
        v.push_back(1);
        int t2 = 0, t3 = 0, t5 = 0;
        int tmp2, tmp3, tmp5;
        for (int i = 1; i < n; i++) {

            tmp2 = 2 * v[t2];
            tmp3 = 3 * v[t3];
            tmp5 = 5 * v[t5];
            int minVal = min(min(tmp2, tmp3), tmp5);
            if (tmp2 == minVal)
                t2 ++;
            if (tmp3 == minVal)
                t3 ++;
            if (tmp5 == minVal)
                t5 ++;
            
            v.push_back(minVal);

        }
        return v[n-1];
    }
};

```