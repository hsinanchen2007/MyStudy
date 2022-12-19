### 解题思路
![QQ截图20200311165424.png](https://pic.leetcode-cn.com/8f6e1017ceea1f946d1e74bc082ff6d58dffbec150cbe4ff9dd5c7bbc79e9db3-QQ%E6%88%AA%E5%9B%BE20200311165424.png)

m[i]=m[i-1]+m[i-2];i>=3
### 代码

```java
class Solution {
    public int climbStairs(int n) {
          if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        int [] m=new int[n+1];
        m[1]=1;//爬一节楼梯只有一种可能
        m[2]=2;//爬2阶楼梯只有两种可能
        for(int i=3;i<=n;i++){//从第三阶楼梯开始算
            m[i]=m[i-1]+m[i-2];
        }
        return m[n];

    }
}
```