### 解题思路

1. 先排序（按照区间的第一位置的数值大小排序，从小到大），这里采用快速排序
2. 记录当前的区间（用内存来记录目前记录的区间，不断迭代这个区间直到完成目标之后，再存起来）


### 代码

```cpp
class Solution {
public:
    void sort (vector<vector<int>> &a,int s,int e){
        if (s >= e)
            return;
        int i = s, j = e;
        vector<int> k = a[s];
        while (i < j) {
            while ( i < j && a[j][0] >= k[0])
                --j;
            if ( i < j ) {
                a[i] = a[j];
            }
            while ( i < j && a[i][0] <= k[0])
                ++i;
            if ( i < j ) {
                a[j] = a[i];
            }
        }
        a[i] = k;
        sort(a,s,i-1);
        sort(a,i+1,e);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i, j, last=-1;
        vector<vector<int>> ans;
        sort(intervals, 0, intervals.size() -1);
        for (int index=0; index<intervals.size(); ++index) {
            if (last == -1 || intervals[index][0] > j){
                if (last != -1){ // end
                    ans.push_back(vector<int>({i, j}));
                }
                i = intervals[index][0];
                j = intervals[index][1];
                last = index;
            } else {
                i = i < intervals[index][0]? i:intervals[index][0];
                j = j > intervals[index][1]? j:intervals[index][1];
            }
        }
        if (last != -1){ // end
            ans.push_back(vector<int>({i, j}));
        }

        return ans;
    }
};
```