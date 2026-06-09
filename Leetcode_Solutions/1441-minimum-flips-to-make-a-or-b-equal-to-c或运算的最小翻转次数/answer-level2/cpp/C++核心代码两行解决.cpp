### 解题思路
以下分析均以二进制结构思考，不考虑十进制的值。
核心问题：分析题意可知是将a和b的或运算结果（记为result1）与c进行比较，看result1和c的位数哪些地方不同，不同就要修改a和b的相应位。
为了解决这个问题，分两步进行：
    1.找到哪些位需要修改：
        我们将result1和c进行异或运算，也就是看result1和c哪些位不同，得到哪些位需要修改；
    2.怎么修改：
        在假定a和b必须修改的前提下我们得到以下表：        
![表.jpg](https://pic.leetcode-cn.com/727e07cee24cd7a027bc5757fddb4017e56828a86bf8692f5fd3d06003b0d543-%E8%A1%A8.jpg)
        不难发现只有a和b的位均为1的时候需要修改两次，其他情况均为一次，而这恰好符合与运算的结果，所以我们将a和b进行与运算得到运算          结果（记为result2）。

接下来应用鸡兔同笼的思想，得到只要修改一次的次数（在数值上恰等于result1中1出现的次数）记为num1；接下来再考虑需要修改且要改两次的次数（在数值上恰等于result1&result2中1出现的次数）记为num2；num1+num2即为需要修改的最少次数。
![5308.png](https://pic.leetcode-cn.com/dcacbc4ca7f0a43dad204dc08d46a38c2c8630ed73880109d4426227456b05a6-5308.png)
### 代码

```cpp
class Solution {
    int one_num(int num){
        int n = 0;
        while(num){
            n+=num%2;
            num/=2;
        }
        return n;
    }
public:
    int minFlips(int a, int b, int c) {
        int d = (a|b)^c;
        int e = a&b;
        return one_num(d)+one_num(d&e);
    }
};
```