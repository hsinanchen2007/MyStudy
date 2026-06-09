### 解题思路
此处撰写解题思路
这个题，刚开始我用最大堆，每次将堆顶元素除以2,然后再压堆2次，一直重复K次，但是发现结果不对，看了高手的解答，发现还是二分搜索，
将最大值 和最小值取出来，以二分查找，找到临界点处理值。
### 代码

```cpp
class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        if(stations.empty() || stations.size() == 1) return 0;
        int prev = stations[0];
        int maxDiff = 0;
        for(int i = 1; i < stations.size(); i++)
        {
            maxDiff = max(stations[i] - prev, maxDiff);
            prev = stations[i];
        }
        double lo =  maxDiff/(K+1);
        double hi = maxDiff+1;
        while(abs(hi - lo) > 1e-6){
            double mid = lo + (hi-lo)/2;
            int cnt = 0;
            prev = stations[0];
            for(int i = 1; i < stations.size(); i++)
            {
               cnt+=(stations[i]-prev)/mid;
               prev = stations[i];
            }
            if(cnt > K)
            {
                 lo = mid+1e-6;
            }else
                hi = mid;
        } 
        return lo;  
    }
};
```