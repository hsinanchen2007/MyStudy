### 解题思路
我们可以通过排序，从最左边开始，尽量让左边相近的气球放一起，之后判断后来的气球右边是否可以加入到一起被射中的范围，如果碰到一个气球无法和前面的气球合一起的话，我们更新右边界值。
因为不管最后一个气球是否可以被合并，它其实都没有算入需要的箭数里，所以退出循环后要加1。

### 代码

```cpp
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0)
            return 0;
        sort(points.begin(), points.end());
        int ans = 0;
        int right = points[0][1];
        for(int i = 1 ; i < points.size() ; ++i)
        {
            if(points[i][0] <= right)
            {  
                right = min(right, points[i][1]);
            }
            else
            {
                ans++;
                right = points[i][1];
            }
        }
        ans++;
        return ans;
    }

};
```