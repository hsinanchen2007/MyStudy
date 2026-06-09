### 解题思路
1）新建数组B
2)遍历A数组，依次将A数组内的偶数赋值到B数组的偶数位上，依次将A数组内的奇数赋值到B数组的奇数位上
3）返回数组B
### 代码

```java
class Solution {
    public  int[] sortArrayByParityII(int[] A) {
      if (A.length == 0){
          return A;
      }
      int [] B = new int[A.length];
      int j=0;
      int k=1;
      for (int i = 0;i<A.length;i ++){
         if (A[i] % 2 ==0 ){
            B[j] = A[i];
            j += 2;
         }else {
             B[k] = A[i];
             k +=2;
         }
      }
      return B;
    }
}
时间复杂度：O(n)
空间复杂度：O(n)
```