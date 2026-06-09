![奇怪的知识增加了.jpg](https://pic.leetcode-cn.com/d32fc2340d25d68770e74a0f98645ddc2fb03e02a8f45e527864b49de58ff064-%E5%A5%87%E6%80%AA%E7%9A%84%E7%9F%A5%E8%AF%86%E5%A2%9E%E5%8A%A0%E4%BA%86.jpg)


### 代码

```java
class Solution {
    public int findNthDigit(int n) {
        if (n <= 9) return n;// 前9位搞定
        int count = n + 1;//需要找到的位数。
        double num = 2;//在两位数区间里找
        double left = count - 10;//还需要找的位数
        double tmp;
        while (left > (tmp = num * (9 * (int) Math.pow(10, num - 1)))) {//如果
            left -= tmp;
            num++;
        }
        int begin = (int) (Math.pow(10, num - 1));
        int index = (int)left / (int)num;
        int ano = (int)left % (int)num;
        if (ano == 0) return (begin + index - 1) % 10;
        return ((begin + index) / (int) (Math.pow(10, num - ano))) % 10;
    }
}
```