### 解题思路
此处撰写解题思路

通过手写二维vector的比较函数，将vector进行排序，然后从大到小贪心选取每个区间，中间设置一个断点lastX，只有在这个断电之前的区间才能算作不重叠区间，此时要选择的区间加1，最后将intervals原来的大小减去不重叠区间的个数即可得到最终可以删除的最小的值。


### 代码

```cpp
class Solution {
public:
    
    static bool cmp(vector<int>& a, vector<int>& b){
        if (a[0]!=b[0])
            return a[0]>b[0];
        else return a[1]>b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int n=intervals.size();
        
        if(n==0 || n==1) return 0;
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        int ans=1, lastX=intervals[0][0];
        
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][1]<=lastX){
                lastX = intervals[i][0];
                ans++;
            }
        }
        
        return n-ans;
        
    }
};
```