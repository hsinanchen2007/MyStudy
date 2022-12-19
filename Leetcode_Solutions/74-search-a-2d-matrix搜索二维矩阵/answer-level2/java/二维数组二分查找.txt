### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int low=0,high=matrix.length-1;
		//二维数组为空
		if(high==-1) {
			return false;
		}
		while(low<=high) {
			int middle=low+(high-low)/2;
			int rowLength=matrix[middle].length;
			if(rowLength==0) {
				return false;
			}
			if(target==matrix[middle][0]||target==matrix[middle][rowLength-1]) {
				return true;
			}
			if(target>matrix[middle][0]&&target<matrix[middle][rowLength-1]) {
				int ilow=0,ihigh=rowLength-1;
				while (ilow <= ihigh) {
					int imiddle = ilow + (ihigh - ilow) / 2;
					if (matrix[middle][imiddle] == target) {
						return true;
					}
					if (target <matrix[middle][imiddle]) {
						ihigh = imiddle - 1;
					} else {
						ilow = imiddle + 1;
					}
				}
				return false;
			}
			if(target>matrix[middle][rowLength-1]) {
				low=middle+1;
			}else {
				high=middle-1;
			}
		}
		return false;
    }
}
```