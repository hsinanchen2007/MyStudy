### 解题思路
第一次写，要是写错了，请轻喷啊

我们常用的10进制数字，总共有 0~9 总共 10个基本数字；

我们这里 a~z 总共 26个字母，可以看做是 26进制数字(不知道数学上这样对不对)。

**所以字母最终的值 result = 累加 每位所代表的值**

每位上对应的值怎么计算呢？ 

> 1. 首先知道这一位的base，比如倒数第一位的base 是 1，倒数第二位base 是 1*64，倒数第三位base 是 1*64*64 ，每个 base 都是前一个 base * 64 ...    
> 2. 其次，计算(倒数)第i位的值为： (Character.toLowerCase(charAt(i)) - 'a' + 1) * base     
> 3. 按照我们的习惯，低位在右边，所以for 循环要从 s.length() 开始取值，计算，累加     
> 4. 我个人比较懒，没有写 map 映射，使用 字母差值，唯一要注意的就是 防止输入小写，诸如  "aa" 之类的      

话不多说，看代码，很简单

### 代码

```java
class Solution {
    public int titleToNumber(String s) {
        if(s == null || s.length() == 0){
            return 0;
        }

        int strLen = s.length();
        int result = 0;
        int base = 1;

        for(int i = strLen - 1;i >= 0;i --){
            char currentChar = Character.toLowerCase(s.charAt(i));
            result = result + base * (int)(currentChar - 'a' + 1);
            base = base * 26;
        }

        return result;
    }
}
```