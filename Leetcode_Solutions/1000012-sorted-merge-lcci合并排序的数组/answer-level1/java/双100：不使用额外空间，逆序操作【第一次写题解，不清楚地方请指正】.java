### 解题思路
![微信截图_20200303124733.png](https://pic.leetcode-cn.com/75c48b15c8fae723fd2493cd76e9ac8f5273a79c8fb40020d2e17eb6a62ecc14-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200303124733.png)
第一步，从合并后的A元素末尾出发，通过从后向前比较A数组元素和B数组元素的大小，将较大值插入合并后的A数组末尾处。
通过设置k指针指向合并后A数组的最后一个位置（m+n-1），设置i指针指向当前A数组当前的m-1位置，设置j指针指向B数组当前的n-1位置。
逐个比较A[i]与B[j]的大小，将较大的值赋给A[k]，同时将较大值的指针--，k--。
for循环的结束条件是 i<0 || j<0 || k<0。
第二步，通过j元素是否小于0，判断B数组是否迁移完毕。如果j大于等于0，则需要将B中剩余元素从到小赋予A[k]，直到k元素小于0

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
       int i = m-1;//A数组
       int j = n-1;//B数组
       int k = m+n-1;
       for(;i>=0 && j>=0 &&k>=0;k--){
           if(A[i] >= B[j]){
               A[k] = A[i];
               i--;
           }else{
               A[k] = B[j];
               j--;
           }
       }
       if(j>=0){
           while(k>=0 && j>=0){
               A[k--] = B[j--];
           }
       }
    }
}
```