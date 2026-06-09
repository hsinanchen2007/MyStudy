### 解题思路
递归超出时间限制，使用迭代

### 代码

```java
class Solution {
    public int climbStairs(int n) {
       if (n == 1){
           return 1;
       } 
       if (n == 2){
           return 2;
       }
    //    }else{
    //        return climbStairs(n - 1) + climbStairs(n - 2);
    //    }
        int f1 = 1;
        int f2 = 2;
        int f3 = 0;
        for (int i = 2; i < n; i++){
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        return f3;
    }
}
```