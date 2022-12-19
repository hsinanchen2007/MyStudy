## 解答
先看一看下述代码有什么问题：
```java
class Solution {
    public String intToRoman(int num) {
        StringBuilder res = new StringBuilder();
        while(num > 0) {
            if(num >= 1000) {
                res.append("M");     
                num -= 1000;
            } else if(num >= 900) {
                res.append("CM");  
                num -= 900;
            } else if(num >= 500) {
                res.append("D");  
                num -= 500;
            } else if(num >= 400) {
                。。。
            } 。。。
        }   
        
        return res.toString();
    }
}
```
这应该是最简单的思路了。。

但这只是一个理论解法，当然可以继续向下写分支，如果写完整 **全部分支** 的话通过应该是 ok 的 。

但是这些 if - else 写的手都要断了好不 ：）

那么能不能抽象一下搞一个循环出来做这件事情呢？
- 那必然是可以的，，所以就有了后面的解法。

### 抽象了之后的解法
每次都找到对应极值，然后计算个数并添加到结果字符串里，再减去相对应数值即可。

简单理解：就是从当前罗马值的极值往下削，一直削到 num 比这个罗马值的极值小，才开始下一轮循环。

使用下面这十几行代码就可以实现上述一堆 if - else 代码才可以实现的功能啦 。。。
#### 代码
```java
class Solution {
    public String intToRoman(int num) {
        StringBuilder res = new StringBuilder();
        
        int[] vals = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        String[] ss = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D","CM", "M"};
        for(int i = vals.length - 1; i >= 0; i --) {
            int val = vals[i];
            while(num >= val) {
                num -= val;
                res.append(ss[i]);
            }
        }
        
        return res.toString();
    }
}
```
#### 结果
![在这里插入图片描述](https://pic.leetcode-cn.com/83d0f2b5ddb7611d91abc6621f0b1071dbf66deae018ab2817fdd8a7ea9ffe6e.png)
