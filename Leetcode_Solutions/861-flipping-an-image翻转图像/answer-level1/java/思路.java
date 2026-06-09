### 解题思路
此处撰写解题思路
我的思路:
    将二维数组中的列进行交换
    第二次的遍历是将二维数组中的0替换成1，把1替换成0的
最后返回这个数组；
### 代码

```java
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        for(int i=0;i<A.length;i++){
            for(int j=0;j<A[i].length/2;j++){
                int t=A[i][j];
               A[i][j]= A[i][A[i].length-j-1];
                A[i][A[i].length-j-1]=t;
            }
        }
        for(int i=0;i<A.length;i++){
            for(int j=0;j<A[i].length;j++){
                if(A[i][j]==0){
                    A[i][j]=1;
                }else{
                    A[i][j]=0;
                }
            }
        }
        return A;
    }
}
```