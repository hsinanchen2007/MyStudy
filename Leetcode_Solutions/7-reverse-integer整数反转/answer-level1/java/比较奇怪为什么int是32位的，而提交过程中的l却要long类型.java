### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int reverse(int x) {
        //分析
            /*
            1.返回值为int类型整数
            2.使用数学方法 （最低位数字*10+低位-1)*10+最高位数字
            */
            long l=0;
            while(x!=0){
                l=l*10+x%10;
                x=x/10;
            }
            return (int)l==l?(int)l:0;
    }
}
```