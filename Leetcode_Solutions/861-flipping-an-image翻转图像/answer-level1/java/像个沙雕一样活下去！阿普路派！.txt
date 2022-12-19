### 解题思路
执行用时 :
1 ms
, 在所有 java 提交中击败了
76.67%
的用户
内存消耗 :
36.8 MB
, 在所有 java 提交中击败了
99.21%
的用户

### 代码

```java
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        int[][] Res=new int[A.length][A[0].length];
    	 //length属性获取的是数组的行数， array[0].length是该行拥有多少个元素，即列数
    	 for(int l=0;l<A.length;l++) {
    		 for(int c=0;c<A[0].length;c++) {
    			 Res[l][c]=A[l][A[0].length-1-c];
    		 }
    	 }
    	 for(int l=0;l<A.length;l++) {
    		 for(int c=0;c<A[0].length;c++) {
    			 if(Res[l][c]==0) {
    				 Res[l][c]=1;
    			 }else {
    				 Res[l][c]=0;
    			 }
    		 }
    	 }
    	 return Res;
    }
}
```