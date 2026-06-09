以前面试遇到过，当时用的动态规划写了一堆，结果答案很简单，就是数学上面的通项公式：
F(N) = F(N-1) + F(N-2)
递归调用即可。
真的像个脑筋急转弯啊！

js
```js
var fib = function(N) {
    return N == 0 ? 0
        : N == 1 ? 1
        : fib(N - 1) + fib(N - 2);
};
```

java
```java
class Solution {
    public int fib(int N) {
        return N == 0 ? 0
            : N == 1 ? 1
            : fib(N - 1) + fib(N - 2);
    }
}
```

但是，这样做的**效率极低**，时间复杂度达到了O(2^N)，显然不现实。
可想到的改进方案是，用一个列表保存结果，可以把时间复杂度降到O(N)：
```java
class Solution {
    
    public int fib(int N) {
        if(N == 0) return 0;
        if(N == 1) return 1;
        
        List<Integer> results = new ArrayList();
        results.add(0);
        results.add(1);
        results.add(1);

        return fib1(N, results);
    }
    
    public int fib1(int N, List<Integer> l) {
        if(l.size() > N) {
            return l.get(N);
        }
        return fib1(N - 1, l) + fib1(N - 2, l);
    }
}
```

事实上，这么做相当于脱了裤子放屁；
如果都想到了保存结果，那么用迭代法更简单，只需要一个数组保存**最后两个**结果即可，时间复杂度是O(n)：
```java
class Solution {
    
    public int fib(int N) {
        if(N == 0) return 0;
        if(N == 1) return 1;
        
        int[] FIB = {1,1};
        while(N-- > 2) {
            FIB[1] = FIB[0] + FIB[1];
            FIB[0] = FIB[1] - FIB[0];
        }
        
        return FIB[1];
    }
}
```

彩蛋1 通项公式
![image.png](https://pic.leetcode-cn.com/303429e3bc7ec151e12b4189148cba2ea73242c8c86d24b3c3fb7c27145b0156-image.png)
```java
class Solution {
    
    public int fib(int N) {
        double M = Math.sqrt(5);
        return (int) Math.round((Math.pow((1+M)/2, N) - Math.pow((1-M)/2, N)) / M);
    }

}
```

彩蛋2 提前算到int的最大值
```java
class Solution {
    public static final int[] FIB = {1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155,165580141,267914296,433494437,701408733,1134903170,1836311903};
    
    public int fib(int N) {
        return FIB[N];
    }
}
```
