![image.png](https://pic.leetcode-cn.com/d8f164a5d6e690729422684596e3ef20fad7b8ba321c7d19e96f96ce09315f39-image.png)
从外圈开始旋转每一圈，需要用到圈的长度的数组临时存储，类似交换：
临时存上，左给上，下给左，右给下，最后临时给右
这样一圈一圈向内递进，没有重复操作，就vans了
代码如下：
```
class Solution {
    public void rotate(int[][] matrix) {
        int left=0,right=matrix.length-1;
        int count=0;
        while (left<right){
            int[] tmp=new int[right-left+1];
            //旋转最外圈
            //1.上->临时
            //2.左->上;
            //3.下->左;
            //4.右->下;
            //5.临时->右;
            for(int i=left;i<right;i++){
                tmp[i-left]=matrix[left][i];
                matrix[left][i]=matrix[right-i+count][left];
                matrix[right-i+count][left]=matrix[right][right-i+count];
                matrix[right][right-i+count]=matrix[i][right];
                matrix[i][right]=tmp[i-left];
            }
            //进内圈
            left++;right--;count++;
        }
    }
}
```

