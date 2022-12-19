### 解题思路
官方题解是：对右边界排序，然后贪心，我个人觉得理解并不直观，提供一种对左边界排序的方法

类似题目：
435. 无重叠区间 ：https://leetcode-cn.com/problems/non-overlapping-intervals/
646. 最长数对链：https://leetcode-cn.com/problems/maximum-length-of-pair-chain/

贪心算法：
1）按从小到大排序
2）如果points[i]的左边界points[i][0]大于end，说明不重叠，需要一支新箭；同时更新end = points[i][1]
3) 如果points[i]的左边界points[i][0]小于end，说明存在重叠，不需要新箭；但是该气球的右边界需要取最小值

举例子说明：
1）排序后[0,5] [1,2] [3,6] [4,8]
A[0,5] : count =1,end = 5;
B[1,2] : count =1,end = 2; 重叠，end 取min(5,2)
C[3,6] : count =2,end = 6; 不重叠，count++，end刷新
D[4,8] ：count =2,end = 6; 重叠



![image.png](https://pic.leetcode-cn.com/9ef3edb3dbd5c98f0775651dd701074221123540480734becbb4540f508d5420-image.png)



### 代码

```cpp
class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        int end = 0;
        int count = 0;
        sort(points.begin(), points.end());

        for (int i = 0; i < points.size(); i++) {
            if (i == 0) {
                end = points[i][1];
                count++;
            } else {
                if (points[i][0] > end) {
                    count++;
                    end = points[i][1];
                }else{
                    end = min(end, points[i][1]);
                }
            }
        }

        return count;
    }
};
```