本质上就是斐波那契数列的一个现实例子，从第三阶楼梯来举例：当你爬上一阶楼梯后，剩下还有两阶楼梯也就等于现在走两阶楼梯的可能，也就是2，如果是爬上两阶楼梯，就剩下一阶楼梯，也就是还有一种可能，所以f(3) = f(2) + f(1)
第四阶：当爬上一阶楼梯后还剩下三阶楼梯，也就是现在有f(3)种可能，当你爬上两阶楼梯后，还有f(2)种可能，所以f(4) = f(3) + f(2)
第五阶：当爬上一阶楼梯后还剩下四阶楼梯，也就是还有f(4)种可能，当你爬上两阶楼梯后，还有f(3)种可能，所以f(5) = f(4) + f(3)
... ...以此类推
得出结论：f(n) = f(n -1) + f(n -2) (n > 2)
直接撸代码：
```
//这个是傻递归方法，并不是递归方法不好，而是这种递归方法会重复造轮子，没有使用到缓存
class Solution {
    public int climbStairs(int n) {
       if (n == 1) {
           return 1;
       }
       if (n == 2) {
           return 2;
       }
       return climbStairs(n - 1) + climbStairs(n - 2);
    }
}
```
其实递归算法是一种不错的方法，只是上面这个代码不会存结果，比如如果n = 6的话，可能会计算2,3次f(3)
下面使用了缓存的递归方法，时间复杂度上还算可以
```
class Solution {
    Map<Integer, Integer> map = new HashMap<>();
    public int climbStairs(int n) {
        if (n == 1) {
            map.put(1, 1);
            return 1;
        }
        if (n == 2) {
            map.put(2, 2);
            return 2;
        }
        if (map.get(n) != null) {
            return map.get(n);
        } else {
            int result = climbStairs(n - 1) + climbStairs(n - 2);
            map.put(n, result);
            return result;
        }
    }
}
```
还有一种方法：就是非递归方法，这个方法和做二叉树时一样，就是递归算法好理解，非递归方法不好理解
其实也挺容易理解，按上面公式来看，f(n) = f(n -1) + f(n -2) (n > 2)
其实就是他的上一个结果和上上个结果，只需要在赋值的时候，记录上就可以了，然后相加时再替换
```
class Solution {
    public int climbStairs(int n) {
        int result = 0;
        int f1 = 1;
        int f2 = 2;
        if (n == 1) {
            return f1;
        }
        if (n == 2) {
            return f2;
        }
        for (int i = 3; i <= n; i++) {
            result = f1 + f2;
            f1 = f2;
            f2 = result;
        }
        return result;
    }
}
```


