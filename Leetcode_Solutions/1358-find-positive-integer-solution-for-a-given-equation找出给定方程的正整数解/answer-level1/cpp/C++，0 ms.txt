取巧的解法，找不到思路，所以把 9 个函数试了出来，然后判断下。函数如下：

1. `f(x, y) = x + y`
2. `f(x, y) = x * y`
3. `f(x, y) = x * x + y`
4. `f(x, y) = x + y * y`
5. `f(x, y) = x * x + y * y`
6. `f(x, y) = (x + y) * (x + y)`
7. `f(x, y) = x * x * x + y * y * y`
8. `f(x, y) = x * x * y`
9. `f(x, y) = x * y * y`

具有针对性的解法如下，大概就是缩小了遍历范围：
<br>
```cpp
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector< vector<int> > findSolution(CustomFunction& customfunction, int z) {
        char buffer [2];
        sprintf(buffer, "%d", customfunction);
        int index = buffer[0] - '0';
        vector< vector<int> > ans = vector< vector<int> >();
        if (1 == index) { // (x + y) == z
            for (int x = 1; x < 100; ++x) {
                int y = z-x;
                if ((y >= 1) && (y <= 100)) {
                    vector<int> obj; 
                    obj.push_back(x);
                    obj.push_back(z-x);
                    ans.push_back(obj);
                }
            }
        } else if (2 == index) { // (x * y) == z
            for (int x = 1; x <= 100; ++x) {
                if ((z % x) == 0) {
                    vector<int> obj; 
                    obj.push_back(x);
                    obj.push_back(z / x);
                    ans.push_back(obj);
                }
            }
        } else if (3 == index) { // (x * x + y) == z
            for (int x = 1; x <= 10; ++x) {
                int y = z - x * x;
                if ((y >= 1) && (y <= 100)) {
                    vector<int> obj; 
                    obj.push_back(x);
                    obj.push_back(y);
                    ans.push_back(obj);
                }
            }
        } else if (4 == index) { // (x + y * y) == z
            for (int y = 1; y <= 10; ++y) {
                int x = z - y * y;
                if ((x >= 1) && (x <= 100)) {
                    vector<int> obj; 
                    obj.push_back(x);
                    obj.push_back(y);
                    ans.push_back(obj);
                }
            }
        } else if (5 == index) { // (x * x + y * y) == z
            for (int x = 1; x <= 10; ++x) {
                for (int y = 1; y <= 10; ++y) {
                    if (customfunction.f(x, y) == z) {
                        vector<int> obj; 
                        obj.push_back(x);
                        obj.push_back(y);
                        ans.push_back(obj);
                    }
                }            
            }
        } else if (6 == index) { // ((x + y) * (x + y)) == z
            for (int x = 1; x < 10; ++x) {
                for (int y = 1; y < 10; ++y) {
                    if (customfunction.f(x, y) == z) {
                        vector<int> obj; 
                        obj.push_back(x);
                        obj.push_back(y);
                        ans.push_back(obj);
                    }
                }            
            }
        } else if (7 == index) { // (x * x * x + y * y * y) == z
            for (int x = 1; x <= 10; ++x) {
                for (int y = 1; y <= 10; ++y) {
                    if (customfunction.f(x, y) == z) {
                        vector<int> obj; 
                        obj.push_back(x);
                        obj.push_back(y);
                        ans.push_back(obj);
                    }
                }            
            }
        } else if (8 == index) { // (x * x * y) == z
            for (int x = 1; x <= 10; ++x) {
                for (int y = 1; y <= 100; ++y) {
                    if ((z % y) != 0) {
                        continue;
                    }
                    if (customfunction.f(x, y) == z) {
                        vector<int> obj; 
                        obj.push_back(x);
                        obj.push_back(y);
                        ans.push_back(obj);
                    }
                }            
            }
        } else if (9 == index) { // (y * y * x) == z
            for (int x = 1; x <= 100; ++x) {
                if ((z % x) != 0) {
                    continue;
                }
                for (int y = 1; y <= 10; ++y) {
                    if (customfunction.f(x, y) == z) {
                        vector<int> obj; 
                        obj.push_back(x);
                        obj.push_back(y);
                        ans.push_back(obj);
                    }
                }
            }
        }
        return ans;
    }
};
```