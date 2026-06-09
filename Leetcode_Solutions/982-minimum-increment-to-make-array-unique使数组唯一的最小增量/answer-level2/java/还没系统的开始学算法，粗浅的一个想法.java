### 解题思路
初次接触算法题可能思路什么的u不太正规
我的想法就是先排序好，之后检测后一个是不是比前一个大，当出现连续相等的数列之后判断下一个值是不是大到足以让这一段的数列变成一个以1为差值的等差数列，如果是就把这一段变成等差数列。
执行用时 :19 ms, 在所有 Java 提交中击败了67.81%的用户
内存消耗 :45.7 MB, 在所有 Java 提交中击败了92.16%的用户
### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
         int move=0;
         int a =A.length;
         int i=0;
         Arrays.sort(A);
         while(i<(a-1)){
              if(A[i]<A[i+1]){
                     i++;
                 }else{
             for(int j=i+1;j<a;j++){
                 if(j==(a-1)||(A[i]+(j-i))<=A[j]){
                	 if((j-i)==1) {
                		 move++;
                	 }else {
                		 int pro=j-i;
                		 if(j==(a-1)&&(A[i]+(j-i))>A[j]){
                			 pro=j-i+1;
                		 }
                     for (int index=1;index<pro;index++){
                         move=move+A[i]+index-A[i+index];
                     }
                     }
                 i=j;
                 break;
                     }
                 }
             }
         }
    return move;
    }
}
```