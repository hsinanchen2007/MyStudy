### 解题思路
首先，对于短线和长线，短线决定容量高度，短线和长线的横坐标差值决定容量长度。所以，对每条线，只看比它高的线，找容量最大的组合即可。
用结构体存每个线
按高度从小到大排序
对每条线，找比它高且和它横坐标差值最大的线
记录求出最大值

### 代码

```cpp
class Solution {
public:
    struct point{
            int x;
            int h;
        }a,b,line[100010];
    int dst,maxdst,s,maxs;     // dst of x
    static bool com(point a,point b){
        if(a.h < b.h)
            return 1;
        else 
            return 0;
    }

    int maxArea(vector<int>& height) {
        int hsize = height.size();
        for(int i=0; i<hsize; i++){
            line[i].x = i+1;
            line[i].h = height[i];
        }
        sort(line,line+hsize,com);

        for(int i=0; i<hsize-1; i++){
            maxdst = 0;
            for(int j=i+1; j<hsize; j++){
                dst = fabs(line[i].x - line[j].x);
                maxdst = max(dst,maxdst);
            }
            s = maxdst * line[i].h;
            maxs = max(s,maxs);
        }
        return maxs;
    }
};
```