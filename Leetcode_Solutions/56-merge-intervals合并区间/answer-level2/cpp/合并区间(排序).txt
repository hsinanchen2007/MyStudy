### 解题思路
手写快速排序

### 代码

```cpp
class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> res;
        if(intervals.empty()) return res;

        QuickSort(intervals,0,intervals.size()-1);
        res.push_back(intervals[0]);

        for(vector<int> i:intervals)
        {
            vector<int>& r=res.back();

            if(r[1]>=i[0])
            {
                r[0]=min(r[0],i[0]);
                r[1]=max(r[1],i[1]);
            }
            else res.push_back(i);
        }

        return res;
    }

    void QuickSort(vector<vector<int>>& a,int first,int last)
    {
        if(last-first<1) return;
        int low=first,high=last;
        vector<int> key=a[first];

        while(low!=high)
        {
            while(low!=high && a[high][0]>=key[0]) high--;
            a[low]=a[high];

            while(low!=high && a[low][0]<key[0]) low++;
            a[high]=a[low];
        }

        a[high]=key;

        QuickSort(a,first,high-1);
        QuickSort(a,high+1,last);
    }
};
```