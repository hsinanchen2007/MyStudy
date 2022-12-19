### 解题思路
1 转成正数
2 数学运算 转换
3 反向判断越界
### 代码

```java
class Solution {
    public int reverse(int x) {
       if(x>0&&x<10) return x;
        if(x>-10&&x<=0) return x;
        int p=Math.abs(x);
        int a=0;
        while(p>0){
            int m=p%10;
            p=p/10;
            if(a>(Integer.MAX_VALUE-m)/10) return 0;
            a=a*10+m;
        }
        return a*(x>0?1:-1);
    }
}
```