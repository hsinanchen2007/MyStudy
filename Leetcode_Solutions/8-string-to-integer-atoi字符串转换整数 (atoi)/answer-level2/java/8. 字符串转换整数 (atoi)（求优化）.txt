### 解题思路
此题中规中矩，主要解题步骤如下：
1.读空白字符
2.判断第一个字符正负号还是其他字符
3.依次读取数字字符将其以sum=sum*10+digit方式计算，同时注意边界条件，也就是sum*10+digit>INT_MAX即sum>(INT_MAX-digit)/10，假如越界就根据正负数返回对应的Integer.MAX_VALUE/MIN_VALUE
此题借助一些常用函数Character.isDigit(),String.toCharArray()

### 代码

```java
class Solution {
    public int myAtoi(String str) {
        char[] c=str.toCharArray();
        int l=c.length;
        int index=0;
        while(index<l&&c[index]==' '){
            index++;
        }
        if(index==l)return 0;
        boolean flag=false;//标记是否负数
        if(c[index]=='-'){//如果是负号
            flag=true;
            index++;
        }else if (c[index]=='+'){
            index++;
        }else if(!Character.isDigit(c[index])){
            return 0;
        }
        int sum=0;
        while (index<l&&Character.isDigit(c[index])){
            int n=c[index]-'0';//0的ascll码是48，后面依次1-9
            if(sum>(Integer.MAX_VALUE-n)/10){//判断是否越界
                return flag? Integer.MIN_VALUE:Integer.MAX_VALUE;//是负数返回最小值，是正数返回最大值，指的都是int型的。
            }
            sum=sum*10+n;
            index++;
        }
        return flag?-sum:sum;
    }
}
```