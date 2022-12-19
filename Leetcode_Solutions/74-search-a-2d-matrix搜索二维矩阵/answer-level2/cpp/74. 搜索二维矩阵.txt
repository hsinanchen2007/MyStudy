简单的二分法
```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if(m==0)return false;
        int n=matrix[0].size();
        if(n==0)return false;
        int low=0;
        int high=m*n-1;
        while(low<high-1)
        {
            int mid=(low+high)/2;
            int i=mid/n;
            int j=mid%n;
            int item=matrix[i][j];
            if(item==target)return true;
            else if(item<target)low=mid;
            else high=mid;
        }
        int mid=low;
        int i=mid/n;
        int j=mid%n;
        int item=matrix[i][j];
        if(item==target)return true;
        mid=high;
        i=mid/n;
        j=mid%n;
        item=matrix[i][j];
        if(item==target)return true;
        return false;
    }
};
```
