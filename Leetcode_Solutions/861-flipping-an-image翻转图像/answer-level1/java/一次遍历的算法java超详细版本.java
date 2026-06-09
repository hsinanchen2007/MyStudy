遍历一次即可，，比如【110】。水平翻转后，是011，那么再反转就会变为100，会发现，两边的值只要不相等，水平翻转后再反转就会和之前一样。
假如是【101】，经过两次后维【010】，所以截半判断两处的值是否相等，相等就不处理，不相等就可以让他们取反。
不过要记得判断是否是奇数个数，奇数个数，就把最中间的数取反即可。
```java
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        int rows=A.length;
        int columns=A[0].length;
        boolean flag=false;
        if(columns%2==1)
            flag=true;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<columns/2;j++)
            {
                
                int temp1=A[i][j];
                int temp2=A[i][columns-j-1];
                if(temp1==temp2)
                {
        
                    A[i][j]=A[i][j]==0?1:0;
                    A[i][columns-j-1]=A[i][columns-j-1]==0?1:0;
                }
             
            }
            if(flag)
            {
               
                A[i][columns/2]=A[i][columns/2]==0?1:0;
            }
        }
     return A;
    }
}
```