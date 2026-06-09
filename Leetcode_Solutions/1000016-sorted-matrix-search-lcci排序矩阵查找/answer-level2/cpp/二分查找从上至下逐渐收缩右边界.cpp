因为数组对于每一列递增，当我们对于一列使用二分查找找到target的插入序号后，在下一行我们可以将二分查找的右边界缩小到这个值。平均时间复杂度为logN*logN
```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if(!m)return false;
        int n=matrix[0].size();
        int now=n-1,row=0;
        while(now>=0&&row<m){
            int l=0,r=now;
            while(l<=r){
                int mid=(l+r)/2;
                if(matrix[row][mid]==target)return true;
                else if(matrix[row][mid]<target)l=mid+1;
                else r=mid-1;
            }
            now=r;
            row++;
        }
        return false;
    }
};
```
