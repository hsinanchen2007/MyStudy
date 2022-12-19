![image.png](https://pic.leetcode-cn.com/53602fad53340a1f2036f72b697a540ea251f7dcc3a4054e72d937bfe30a0f10-image.png)

### 解题思路
当前数是否选择与前两个数有关。

### 代码

```java
class Solution {
    public int massage(int[] nums) {
        int a1 = 0, a2 = 0;
        for(int i : nums){
            int a3 = Math.max(a2, a1+i);
            a1 = a2;
            a2 = a3;
        } 
        return a2;
    }
}
```