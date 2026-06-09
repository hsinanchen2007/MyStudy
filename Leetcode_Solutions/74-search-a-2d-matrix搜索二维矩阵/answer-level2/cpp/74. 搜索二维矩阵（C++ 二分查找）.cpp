# 74. 搜索二维矩阵

**思路：**
由于二维矩阵从左到右有序，而且上一行的最大值一定，小于下一行的最小值。
可以利用两次二分排序，来进行元素搜索。
第一次二分搜索，找到元素可能所在的行。
第二次二分搜索，从该行中搜索具体元素值。

**完整代码：**
```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if( matrix.empty() || matrix[0].empty() ) return false;
		
        //首先二分查找找到所在行
		int low  = 0;
		int high = matrix.size() - 1;
		int row  = -1;
		
		while(low <= high){
			int mid = (low + high)/2;
			
			if( ( matrix[mid][0] <= target ) && ( target <= matrix[mid][matrix[0].size()-1] ) ){
				row = mid;
				break;
			}else if( matrix[mid][0] < target ){
				low = mid + 1;
			}else if( matrix[mid][matrix[0].size()-1] > target ){
				high = mid - 1;
			}
		}
		
		if( row == -1 ) return false;
		
		//第二次利用二分查找找到所在列
		low  = 0;
		high = matrix[0].size() - 1;
		
		while(low <= high){
			int mid = (low + high)/2;
			
			if( matrix[row][mid] == target ) {
				return true;
			}else if( matrix[row][mid] < target ){
				low = mid + 1;
			}else if( matrix[row][mid] > target ){
				high = mid - 1;
			}
		}
		
		return false;
    }
};
```

