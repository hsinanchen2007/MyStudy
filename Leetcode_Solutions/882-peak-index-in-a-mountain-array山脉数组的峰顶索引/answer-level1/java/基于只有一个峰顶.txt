![2020011901.PNG](https://pic.leetcode-cn.com/6833f9f99ff8d3f654dd3cba65880bc0c0ddd8d64e79da2e77d8445491186cd9-2020011901.PNG)
### 解题思路
注意:峰顶是唯一的，
所以,遍历数组,找到A[i]>A[i+1]的索引i,并返回i

### 代码

```java
class Solution {
    public int peakIndexInMountainArray(int[] A) {
        for(int i =1;i<A.length-1;i++){
            if(A[i]>A[i+1]){
                return i;
            }
        }
        return 0;
    }
}
```