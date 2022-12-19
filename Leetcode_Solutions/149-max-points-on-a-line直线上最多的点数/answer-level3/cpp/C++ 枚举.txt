### 解题思路
通过枚举法 对每一个点取 在一条直线上的点的斜率是否一致来计数 并判断和更新最大一条直线的点数

### 代码

```cpp
/* 枚举法 */
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        //两点确定一条直线
        if(points.size()<3)return points.size();
        
        int Max=0;
        for(int i=0;i<points.size();i++)//i表示数组中的第i+1个点
        {
            //same用来表示和i一样的点
            int same=1;
            for(int j=i+1;j<points.size();j++)//j表示数组中的第j+1个点
            {
                int count=0;
                // i、j在数组中是重复点，计数
                if(points[i][0]==points[j][0]&&points[i][1]==points[j][1])same++;
                else{//i和j不是重复点，则计算和直线ij在一条直线上的点
                    count++;
                    long long xDiff = (long long)(points[i][0] - points[j][0]);//Δx1
                    long long yDiff = (long long)(points[i][1] - points[j][1]);//Δy1
                    
                    for (int k = j + 1; k < points.size(); k++)//Δy1/Δx1=Δy2/Δx2 => Δx1*Δy2=Δy1*Δx2，计算和直线ji在一条直线上的点
                        if (xDiff * (points[i][1] - points[k][1]) == yDiff * (points[i][0] - points[k][0]))
                            count++;
                }
                Max=max(Max,same+count);
            }
            if(Max>points.size()/2)return Max;//若某次最大个数超过所有点的一半，则不可能存在其他直线通过更多的点
        }
        return Max;
    }
};
```
![image.png](https://pic.leetcode-cn.com/d9bbef401585f972aec511ab072b18b8fa7acd46f5a4462f3f3211a75f899b7a-image.png)
