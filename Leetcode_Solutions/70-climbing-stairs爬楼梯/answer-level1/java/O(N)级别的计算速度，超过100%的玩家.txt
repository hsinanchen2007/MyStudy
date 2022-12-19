### 解题思路
![image.png](https://pic.leetcode-cn.com/a6976fad33c26a8271c629b244b55adfc4f1547c9fd04711b98936f5574c920d-image.png)


本题有一个递推的公式：
F(1) = 1
F(2)=2
F(n) = F(n-1)+F(n-2)  n>2时
方法一：
使用递归时间复杂度为O(2^N)，使用递归解答超时。
![image.png](https://pic.leetcode-cn.com/92c9bc0eba9a467dc832245e84a07bc3c0137938e5a336351b745f38d8a44d30-image.png)
```java
class Solution {
    public int climbStairs(int n) {
        if ( n == 1 ) return 1;
        if ( n == 2 ) return 2;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
}
```

方法二：
使用递归时间复杂度为O(N)，定义一个数组来存储每次产生的结果，多消耗一些内存空间；
运行的结果图片：
![image.png](https://pic.leetcode-cn.com/b0f2a6e33ba1318ae43d7ffac821d86d8246b8610ddca2c4534d9a30e503a19f-image.png)


```java
class Solution {
   public int climbStairs(int n) {
        int[] arr = new int[n];
        return fCore(arr);
    }

    public int fCore(int[] arr) {
        if ( arr.length == 1 ) return 1;
        if ( arr.length == 2 ) return 2;
        arr[0] = 1;
        arr[1] = 2;
        int i = 2;
        for ( i = 2; i < arr.length; i++ ) {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        return arr[i - 1];
    }
}
```