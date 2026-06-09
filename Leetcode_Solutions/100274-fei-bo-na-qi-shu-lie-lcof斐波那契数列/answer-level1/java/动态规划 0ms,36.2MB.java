### 解题思路
判断n小于2的话直接返回n就可以了,后面的数递增,记得要取模
今天刚看完一个公众号介绍DP,晚上就用上了

### 代码

```java
class Solution {
    public int fib(int n) {
        if(n < 2){
            return n;
        }

        int[] arr = new int[n + 1];
        arr[0] = 0;
        arr[1] = 1;

        for(int i = 2; i <= n; i++){
            arr[i] = (arr[i-1] + arr[i-2]) % 1000000007;
        }
        return arr[n];
    }
}
```

![image.png](https://pic.leetcode-cn.com/db81efcd9949b8bc4f78ecfbd8e6c10d6e3e6a0ced5586d25db922893122d9a4-image.png)
