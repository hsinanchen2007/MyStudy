### 解题思路
其实这道题的核心就是判断一个点是不是在直线上，为此我们单独设计一个isOnline函数用于判断，如果斜率相等说明点在线上，或者该点正好是取的两点中的一个，则说明该点在这条直线上。
接下来用两个指针不断遍历points数组，生成不同的直线，并判断points的点是否在直线上。同时，用一个count计数器数组记录每一条直线上的点的个数，最后count数组的最大值即为题解。
但是提交代码时，我发现如果points数组有相同的点，那么答案就会比正解大。因为两个点取的一样的话，就不能确定唯一一条直线了。一开始我的思路是对二维数组points进行去重，但是在
cpp下很难做到，于是我选择在循环中做文章。如果两个点相同，那么直接continue进行下一个点的选取。
然后我遇到的第二个问题就是，如果points所有的点都相等，那么count里的元素个数就为0了，即没有最大值，编译会报错。于是还要添加判断，如果count元素为0直接返回points的元素个数即可。
最后一个问题就是精度问题，对于测试用例[[0,0],[94911151,94911150],[94911152,94911151]]一开始我的答案是3，编译器认为三个点在一条直线上，说明double精度不够，将int类型转换为long即可。

### 代码

```cpp
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        vector<int> count;
        if(points.size()<=2)
            return points.size();
        for(int i=0;i<points.size()-1;i++)
        {           
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=i+1;j<points.size();j++)
            {
                if(points[i][0]==points[j][0] && points[i][1]==points[j][1])
                    continue;
                int x2=points[j][0];
                int y2=points[j][1];
                int numCount=0;
                for(int i=0;i<points.size();i++)
                {                   
                    if(isOnline(x1,y1,x2,y2,points[i][0],points[i][1]))
                        numCount ++;
                }
                count.push_back(numCount);
            }
        }
        if(count.size()==0)
            return points.size();
        else
            return *max_element(count.begin(), count.end());
    }
    bool isOnline(int x1, int y1, int x2, int y2, int x, int y)
    {
        if(x==x1 && y==y1)
            return true;
        else if(x==x2 && y==y2)
            return true;
        else
            return (long(y1-y))*(x2-x) == (long(y2-y))*(x1-x);
    }
};

```