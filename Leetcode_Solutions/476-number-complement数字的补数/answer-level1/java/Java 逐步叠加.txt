一个数的二进制形态和其补数的二进制形态加起来时，新的二进制数每个位的数字必为 1，也就是说一个数与补数之和为2^n - 1.
只需要找到这个和，然后用这个和减去原数就得到了结果。

代码如下：
```
class Solution {
    public int findComplement(int num) {
        int index = 1;
        while(index < num) {
            index = 2*index + 1;
        }
        return index - num;
    }
}
```
![image.png](https://pic.leetcode-cn.com/57d26d7fcf48f02a5c594df8e032e7c87085385fe661a37fe68b15bc65877948-image.png)
