思路: 先行查找，再列查找
- 行查找：仅仅找出区间
- 列查找：精准查找，找不到返回false
```C++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size() == 0) return false;
        int cindex = cowFind(matrix, target);
        //cout<<cindex<<endl;
        if(cindex == -1) return false;
        return rowFind(matrix[cindex], target);
    }
private:
    int cowFind(vector<vector<int>>& matrix, int target){
        int c = matrix.size();
        if(target>=matrix[c-1][0]) return c-1;
        int left=0; int right=c-2;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(matrix[mid][0]<=target && target<matrix[mid+1][0])
                return mid;
            else if(target < matrix[mid][0])
                right = mid-1;
            else if(target > matrix[mid][0])
                left = mid+1;
        }
        return -1;
    }
    
    int rowFind(vector<int>& matrix, int target){
        int left = 0; int right = matrix.size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            //cout<<mid<<" "<<matrix[mid]<<endl;
            if(matrix[mid]==target)
                return true;
            else if(target < matrix[mid])
                right = mid-1;
            else if(target > matrix[mid])
                left = mid+1;
        }
        return false;
    }
};
```