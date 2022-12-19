- 将时间按分钟看成是一个圈即是从0~1439的圈，将给的时间点全转换成分钟(按照顺时针)然后将分钟数排序
要求的最小时间间隔就是环中的元素与自己相邻的两个点的距离的最小值。
![image.png](https://pic.leetcode-cn.com/51d831c8f0a6a61fd600a506cfae1a2cb769d30b249d0ec6ea0231d88daee4a5-image.png)

如图所示：例如我们要求到点320的距离最小的点,那么只要求点1111到320的顺时针距离和逆时针距离的最小值以及701到320的顺时针距离和
逆时针距离的最小值中的最小值。整个时间序列的最小值就可以这样判断与每个点相邻的两个点距离中的最小值求出。

```cpp
class Solution {
public:
    int time[20010];
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size(),res = INT_MAX;
        for(int i=0;i<n;i++){
            int h = stoi(timePoints[i].substr(0,2)),m = stoi(timePoints[i].substr(3,2));
            int t = h*60 + m;
            time[i] = h*60 + m;
        }
        sort(time,time+n);
        res = min(caculate(0,n-1),caculate(0,1));
        if(n==2) return res;
        for(int i=1;i<n-1;i++){
            res = min(res,min(caculate(i-1,i),caculate(i,i+1)));
        }
        return res;
    }
    int caculate(int x,int y){
        int t = abs(time[x] - time[y]);
        return min(t, 1440-t);
    }
};
```