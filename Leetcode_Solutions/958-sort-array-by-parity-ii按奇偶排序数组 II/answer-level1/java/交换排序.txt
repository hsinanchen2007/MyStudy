### 解题思路
1)找到数组偶数位上值位奇数的第一个元素A
2）找到数组奇数位上值为偶数的第一个元素B
3）交换A和B的值
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
空间复杂度：O(1)
```