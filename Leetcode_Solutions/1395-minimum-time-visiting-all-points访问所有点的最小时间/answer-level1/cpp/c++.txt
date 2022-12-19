### 解题思路
手生了。。这么简单的题写了这么久，，
唉，要再练练了！
不过吧，要把代码缩减到这个程度，其是要基于其中的数学规律的。

### 代码

```cpp
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        if(points.size()<=1){
            return -1;
        }
        int sum=0;
        int a,b;
        int length=points.size()-1;
        for(int i=0;i<length;i++){
            a=points[i+1][0]-points[i][0];
            b=points[i+1][1]-points[i][1];
            a=(a<0?-a:a);
            b=(b<0?-b:b);
            sum+=(a>b?a:b);
        }
        return sum;
    }
};
```