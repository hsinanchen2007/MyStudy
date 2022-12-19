### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/4b3530593921f9fcf9ca16aff06332464716b7b37e47978f336b846277373e9e-image.png)
第一个for循环用于找到n对应的最大值，第二个for循环将所有值赋给res数组。
### 代码

```java
class Solution {
    int last = 1;
    public int[] printNumbers(int n){
        for (int i = 0; i < n; i++) {
            last *= 10;
        }
        int[] res = new int[last-1];
        for (int i = 0; i < last-1; i++) {
            res[i] = i+1;
        }
        return res;
    }
}
```