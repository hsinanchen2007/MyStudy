![2020010501.PNG](https://pic.leetcode-cn.com/f3cdbf0488b1cda7ef7e7c9fdd470ac4ced6e80bad1e568b73ec94c76e45f5b4-2020010501.PNG)
首先排序Arrays.sort(),
然后再从后往前逐个比较连续三个数的关系,该关系为两个较小数之和大于第三个数；
若三个数的关系成立,则三角形周长的最大值为这三个数之和,返回这个三个数之和；
若不满足该关系,则继续往前判断数组剩下的数

### 代码

```java
class Solution {
    public int largestPerimeter(int[] A) {
        Arrays.sort(A);
        for(int i=A.length-1;i-2>=0;i--){
            if(A[i]<(A[i-1]+A[i-2])){
                return A[i]+A[i-1]+A[i-2];
            }
        }
        return 0;
    }
}
```