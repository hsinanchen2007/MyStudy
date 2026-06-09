### 解题思路
1.一定要判断数据是否溢出
2.局部变量的定义必须用long（传过来的x的值不确定有多大）

### 代码

```java
class Solution {
    public int reverse(int x) {
         long s = 0;
        //用一个永真式实现每位数的分离
        while(true) {
            s = s * 10 + x % 10;//分离出最低位
            x = x / 10;//去掉最低位，更新x的值，便于下次的最低位分离
            if(x == 0) {//如果x为0的话，说明数的分解结束，此时要跳出循环
                break;
            }
        }
        if((int)s != s) {
            return 0;
        } else {
            return (int)s;
        }
    }
}
```