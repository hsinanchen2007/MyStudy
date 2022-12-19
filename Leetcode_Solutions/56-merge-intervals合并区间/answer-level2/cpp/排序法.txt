```
class Solution {
public:
    void quickSort(vector<vector<int>>& intervals, int left, int right){
        if(left > right)
            return;
        vector<int> temp = intervals[left];
        int start = left;
        int end = right;
        while(left<right)
        {
            while(left<right && intervals[right][0]>temp[0])
                right--;
            if(left<right)
            {
                intervals[left] = intervals[right];
                left++;
            }
            while(left<right && intervals[left][0]<temp[0])
                left++;
            if(left<right)
            {
                intervals[right] = intervals[left];
                right--;
            }
        }
        intervals[left]=temp;
        quickSort(intervals, start, left-1);
        quickSort(intervals, left+1, end);
        return;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        if(n <= 1)
            return intervals;
        // quickSort(intervals, 0, n-1);
        sort(intervals.begin(), intervals.end());
        for(int i=0; i<n-1; ++i)
        {
            if(intervals[i+1][0] > intervals[i][1])
                ans.push_back(intervals[i]);
            else
            {
                intervals[i+1][0] = intervals[i][0];
                intervals[i+1][1] = max(intervals[i][1], intervals[i+1][1]);
            }
        }
        ans.push_back(intervals[n-1]);
        return ans;
    }
};
```
