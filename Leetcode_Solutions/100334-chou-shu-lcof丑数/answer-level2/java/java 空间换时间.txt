![奇怪的知识增加了.jpg](https://pic.leetcode-cn.com/947c9a0104df9c493daa1a1839a53c8b470e662fdfb758bc582580753dc26a4a-%E5%A5%87%E6%80%AA%E7%9A%84%E7%9F%A5%E8%AF%86%E5%A2%9E%E5%8A%A0%E4%BA%86.jpg)


记录三个序号t1，t2，t3，代表分别乘2、3、5会大于当前的这个数。
当前的下一个数 = 三个序号的数分别乘2、3、5最小的那个数。

### 代码

```java
class Solution {
    public int nthUglyNumber(int n) {
        int[] num = new int[n+1];//建立储存丑数的数组，num[i] = x 第i个丑数为x
        num[1] = 1;
        int t1 = 1;//乘2，大于现有的丑数
        int t2 = 1;//乘3，。。
        int t3 = 1;//乘5，。。
        int index = 1;
        while(index < n){
            num[++index] = Math.min(Math.min(num[t1] * 2, num[t2] * 3), num[t3] * 5);
            while(2*num[t1] <= num[index]) t1 ++;
            while(3*num[t2] <= num[index]) t2 ++;
            while(5*num[t3] <= num[index]) t3 ++;
        }
        return num[n];
    }
}
```