执行用时 :36 ms, 在所有 C++ 提交中击败了54.68%的用户
内存消耗 :12.7 MB, 在所有 C++ 提交中击败了5.08%的用户
```
class Solution {
public:
    void Qsort(vector<vector<int>>& intervals,int low,int high){
        // cout<<low<<' '<<high;
        if(low>=high)
            return;
        int i=low;
        int j=high+1;
        int key=intervals[low][0];
        while(true)
        {
            while(intervals[++i][0]<=key)
            {
                if(i==high)
                    break;
            }
            while(intervals[--j][0]>=key)
            {
                if(j==low)
                    break;
            }
            if(i>=j)
                break;
            int tmp=intervals[i][0];
            intervals[i][0]=intervals[j][0];
            intervals[j][0]=tmp;
            tmp=intervals[i][1];
            intervals[i][1]=intervals[j][1];
            intervals[j][1]=tmp;
        }
        int tmp=intervals[low][0];
            intervals[low][0]=intervals[j][0];
            intervals[j][0]=tmp;
            tmp=intervals[low][1];
            intervals[low][1]=intervals[j][1];
            intervals[j][1]=tmp;
        cout<<intervals[low][0]<<' '<<intervals[j][0];
        Qsort(intervals,low,j-1);
        Qsort(intervals,j+1,high);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<2)
            return intervals;
        vector<vector<int>> ans;
        Qsort(intervals,0,intervals.size()-1);
        int first=intervals[0][0],second=intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]>second)
            {
                vector<int>tmp;
                tmp.push_back(first);
                tmp.push_back(second);
                ans.push_back(tmp);
                first=intervals[i][0];
                second=intervals[i][1];
            }
            else if(intervals[i][1]>second)
            {
                second=intervals[i][1];
            }
        }
        if(!ans.size()||second!=ans.back()[1])
           {
                vector<int>tmp;
                tmp.push_back(first);
                tmp.push_back(second);
                ans.push_back(tmp);
            }  
        return ans;
    }
};
```
