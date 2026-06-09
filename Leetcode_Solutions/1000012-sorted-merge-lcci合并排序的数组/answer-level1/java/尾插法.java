### 解题思路
1.算出两个数组元素数量合
2.从每个数组的尾巴出取出元素然后比较大小将大的放在m+b-1位置，然后一直循环比较
3.没有占用额外空间，时间复杂度O(m+n) 

### 代码

```java
class Solution {
 public void merge(int[] A, int m, int[] B, int n) {
        // 算出两个数组最大长度
        int length = m+n;
        // 从头到尾插入两个数组元素
        for (int i = length-1; i >=0 ; i--) {
            if(m>0 && n>0){
                if(A[m-1]>B[n-1]){
                    A[i] = A[--m];
                }else{
                    A[i] = B[--n];
                }
            }else if(m==0 && n>0){
                A[i] = B[--n];
            }
        }
    }
}
```