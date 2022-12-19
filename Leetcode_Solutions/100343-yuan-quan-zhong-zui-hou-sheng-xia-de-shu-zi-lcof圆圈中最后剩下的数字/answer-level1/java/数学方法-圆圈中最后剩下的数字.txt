[参考](https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/javajie-jue-yue-se-fu-huan-wen-ti-gao-su-ni-wei-sh/)
最开始自己写了一个暴力的，但是leetcodeg会卡时间，就看了甜姨的反推的这个数学方法，目前还没看懂www
### 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {
        int ans = 0;
        for(int i = 2; i <= n; i++){
            ans = (ans + m) % i;
        }
        return ans;
    }
}
```