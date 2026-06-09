### 解题思路
1.依次处理数组内每个元素，当发现有元素A[i]不满足题目规则的时候，从数组末端开始找到一个满足规则的元素A[j]，
2.交换A[i] A[j]
### 代码

```java
class Solution {
    public  int[] sortArrayByParityII(int[] A) {
      if (A.length == 0){
          return A;
      }
      for (int i=0;i<A.length;i++){
          int j = A.length-1;
          int temp ;
          if (i%2==0 && A[i] %2 == 0){
              continue;
          }
          if (i%2 == 0 && A[i] %2 !=0){
              while (j>=i && A[j]%2 !=0){
                  j--;
              }
              temp = A[i];
              A[i] = A[j];
              A[j] = temp;
          }
          if (i%2==1 && A[i] %2 == 1){
              continue;
          }
          if (i%2 == 1 && A[i] %2 !=1){
              while (j>=i && A[j] %2 != 1){
                 j--;
              }
              temp = A[i];
              A[i] = A[j];
              A[j] = temp;
          }
          
            
      }
      return A;
    }
}
时间复杂度：O(n^2)
空间复杂度：O(1)
```