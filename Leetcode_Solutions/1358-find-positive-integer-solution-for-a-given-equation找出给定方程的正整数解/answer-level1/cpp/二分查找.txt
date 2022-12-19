### 解题思路
由题意知道答案的范围为【1,1000】且是严格单调的，比如说找出x=1时对应的y值为nowy，那么当x大于1时，对应的y值小于nowy；当x对应的y值小于等于0时，结束循环。
### 代码

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
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int> > ans;
        int nowy = 1000;  //记录当前y值
        for(int i = 1; i <= 1000; i ++)  循环遍历x的值
        {
            int x = i, ly = 1, ry = nowy;
            vector<int> anss;
            while(ly <= ry)
            {
                int my = (ly + ry)/2;
                if(customfunction.f(x, my) == z)  //此时的x值和y值满足条件
                {
                    anss.push_back(x);
                    anss.push_back(my);
                    nowy = my;
                    ans.push_back(anss);
                    break;
                }
                else if(customfunction.f(x, my) > z)
                ry = my - 1;
                else if(customfunction.f(x, my) < z)
                ly = my + 1;
            }
            if(ry == 0)
            break;
        }
        return ans;
    }
};
```