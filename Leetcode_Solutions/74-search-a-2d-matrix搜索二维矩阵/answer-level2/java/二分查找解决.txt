这道题我在做的时候遇到了一些问题，就是我刚开始找的是最左边一列中的第一个大于等于目标值的那个数字，然后对这一行的上一行进行二分查找目标值，这个思路我觉得没有什么问题，但是这样做其实不是一个严谨的方法，因为也许二维数组中压根没有大于等于目标值那个数字，例如对于下面的这种情况
> {{1,3}} target=3 

如果找每一行中第一个数字最先大于等于目标值的数字，是找不到的，那最后找到的也就是第一行，这时我再去找它的上一行就会产生数组的越界，因为里面有-1的操作

之后换了一种思路，就是找第一列中最后一个小于等于目标值的数字，这样的话，要找的目标数字一定在那一行，因为这行的第一个数字是最后一个小于等于目标值的，由于每行的第一个数字大于上一行的最后一个数字，所以目标值一定不在上面的几行，下一行的所有的数字也绝对是大于目标值的，因为该行的第一个数字是最后一个小于等于目标值的数字，故目标值就在当前的这一行中，最后对这一行做二分操作，如果可以找到目标值，返回true，反之返回false

```
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
            /*
这道题其实就是找二维数组的左边中的最后一个小于等于目标值的数字，然后在这一行中去寻找目标数字就好了因为上面的行中的数字肯定比目标数字要小，下面的肯定比目标数字要大
		    */
	        //这里要有一个判空的操作
		    int n=matrix.length; 
		    if(n==0) return false;
		    int m=matrix[0].length;
		    if(m==0) return false;
		    
		    //然后找到小于等于目标值的最后一个数字
		    int left=0; int right=n-1;
		    while(left<right) {
		    	int mid=(left+right+1)>>1;
		        if(matrix[mid][0]>target) {
		        	right=mid-1;
		        }else {
		        	left=mid;
		        }
		    }
		    
		    //如果小于等于目标值的最后一个数字与目标值相同，返回true
		    if(matrix[left][0]==target) return true;
		 
		    //剩下的就是在left的这一行去找目标值就好了，如果找不到返回false
		    int l=0; int r=m-1;
		    while(l<r) {
		    	int mid=(l+r)>>1;
		        if(matrix[left][mid]<target) {
		        	l=mid+1;
		        }else {
		        	r=mid;
		        }
		    }
		    
		    return matrix[left][l]==target;
    }
}
```
