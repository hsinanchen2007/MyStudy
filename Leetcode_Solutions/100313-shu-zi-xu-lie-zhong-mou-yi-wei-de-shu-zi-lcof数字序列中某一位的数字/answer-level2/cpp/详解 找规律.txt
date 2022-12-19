### 思路一：找规律
我们通过观察，可以发现以下规律：

![1.png](https://pic.leetcode-cn.com/4f913f7a795d55038dc3a480c8268d8cc3367b14cb0cb4a7ea0c9d23f26fff9b-1.png)




对于第 n 位对应的数字，我们令这个数字对应的数为 `target`，然后分三步进行。
- 首先找到这个数字对应的数是几位数，用 `digits` 表示；
- 然后确定这个对应的数的数值 `target`；
- 最后确定返回值是 `target` 中的哪个数字。


举个栗子：

比如输入的 n 是 `365`：

1. 经过第一步计算我们可以得到第 365 个数字表示的数是三位数，$n=365-9-90\times2=176$，`digtis = 3`。这时 $n=176$ 表示目标数字是三位数中的第 $176$ 个数字。

2. 我们设目标数字所在的数为 `number`，计算得到 $number=100+176/3=158$，`idx` 是目标数字在 `number` 中的索引，如果 `idx = 0`，表示目标数字是 `number` 中的最后一个数字。
3. 根据步骤2，我们可以计算得到 `idx = n % digits = 176 % 3 = 2`，说明目标数字应该是 `number = 158` 中的第二个数字，即输出为 `5`。
### 代码




```python []
class Solution:
    def findNthDigit(self, n: int) -> int:
        # 首先判断target是几位数，用digits表示
        base = 9
        digits = 1
        while n - base * digits > 0:
            n -= base * digits
            base *= 10
            digits += 1
        # 计算target的值
        idx = n % digits  # 注意由于上面的计算，n现在表示digits位数的第n个数字
        if idx == 0: 
            idx = digits
        number = 1
        for i in range(1,digits):
            number *= 10
        if idx == digits:
            number += n // digits - 1
        else:
            number += n // digits
        # 找到target中对应的数字
        for i in range(idx,digits):
            number //= 10
        return number % 10
    
```
```c++ []
class Solution {
public:
    int findNthDigit(int n) {
        // 计算该数字由几位数字组成，由1位：digits = 1；2位：digits = 2...
        long base = 9,digits = 1;
        while (n - base * digits > 0){
            n -= base * digits;
            base *= 10;
            digits ++;
        }

        // 计算真实代表的数字是多少
        int idx = n % digits;  // 注意由于上面的计算，n现在表示digits位数的第n个数字
        if (idx == 0)idx = digits;
        long number = 1;
        for (int i = 1;i < digits;i++)
            number *= 10;
        number += (idx == digits)? n/digits - 1:n/digits;

        // 从真实的数字中找到我们想要的那个数字
        for (int i=idx;i<digits;i++) number /= 10;
        return number % 10;
    }
};
```
### 复杂度分析
- 时间复杂度：$O(N)$。
- 空间复杂度：$O(1)$。
### 思路二
掌握了方法之后可以对代码进行简化，思路与之前一样，这里注意的是 `first_num` 表示每组数的第一个数。

![2.png](https://pic.leetcode-cn.com/5a7b1f4a799ca649835939d7e1fdbc051c0e46506f0ccca703fa79d3028726b3-2.png)


### 代码


```cpp []
class Solution {
public:
    int findNthDigit(int n) {
        n -= 1;
        for (long digits=1;digits < 11;++digits ){
            int first_num = pow(10,digits-1);
            if (n < 9 * first_num * digits){
                return int(to_string(first_num + n/digits)[n%digits])-'0';
            }
            n -= 9 * first_num * digits;
        }
        return 0;
    }
};
```
```python []
class Solution:
    def findNthDigit(self, n):
        n -= 1
        for digits in range(1, 11):
            first_num = 10**(digits - 1)
            if n < 9 * first_num * digits:
                return int(str(first_num + n/digits)[n%digits])
            n -= 9 * first_num * digits
```



### 复杂度分析
- 时间复杂度：$O(N)$。
- 空间复杂度：$O(1)$。

如有问题，欢迎讨论~