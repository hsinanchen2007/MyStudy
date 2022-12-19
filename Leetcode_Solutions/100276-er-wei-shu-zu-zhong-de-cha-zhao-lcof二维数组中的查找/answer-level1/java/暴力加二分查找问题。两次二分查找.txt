```
class Solution {

    /*
    第一种解法暴力遍历，去找就完了。
    思路也简单没啥好讲的。
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(matrix[i][j]==target){
                    return true ;
                }
            }
        }
        return false ;
    }
    */

    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        /*
        这里还是有优化的空间。在每一列数组的第一个元素也通过二分查找，使用两次二分查找
        使用二分查找跟暴力方法竟然时间复杂度区别不大的
        boolean result = false ;
        for(int i=0;i<matrix.length;i++){
            result = banrySearch(matrix[i],target);
            if(result==true){
                break ;
            }
        }
        return result ;
        */

        //优化两次二分查找。
        int left = 0 ;
        int right = matrix.length-1 ;
        boolean result = false ;
        while(left<=right){
            int mid = (left+right)/2 ;
            if(matrix[mid][0]==target){
                result = true ;
                if(result){
                    break ;
                }
            }else if(matrix[mid][0]>target){
                if(matrix[mid-1][0]<target){
                    result = banrySearch(matrix[mid],target) ;
                    if(result){
                        break ;
                    }
                }
                right = mid-1 ;
            }else if(matrix[mid][0]<target){
                if(matrix[mid+1][0]>target){
                    result =  banrySearch(matrix[mid],target) ;
                    if(result){
                        break ;
                    }
                }
                left = mid+1 ;
            }
        }
        return  result ;
    }

    public boolean banrySearch(int[] array, int k){
        int left = 0 ;
        int right = array.length-1 ;
        while(left<=right){
            int mid = (left+right)/2 ;
            if(array[mid]==k){
                return true ;
            }else if(array[mid]>k){
                right = mid-1 ;
            }else{
                left = mid+1 ;
            }
        }
        return false ;
    }
}
```
