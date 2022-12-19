### 解题思路
题目本身并不难，无非就是取模%，除与÷，取模%，除与÷，取模%，除与÷......

容易暴bi的地方就在，环境只存储的下32位有符号整数。

// 一开始我还没完全理解这句话的意思，以为最后只要确保溢出的时候输出0就行。
// 所以一开始的做法是，溢出后，判断正数跳变负数的情况，输出0。
// 结果来了个runtime error，整数翻转的题都能错，人都裂开了。
// 本判题环境下，如果溢出，不会从正变负，而是直接运行时错误。
// 所以要在**运算之前**就判断本次运算会不会溢出，而不是之后再判断。
// PS：不知道可不可以用异常来解决，没去试。

基本框架：
1. 特殊情况（0直接返回）
2. 初始变量和保存符号
3. 变量扩容（int->long long），不然1023测试用例之后数太大，处理前就过不了
4. 负号转正（abs），简化后续判断条件
5. 倒序保存每一位到数组中
6. 循环，每次先判断溢出，再累“乘加”
7. 加上符号输出返回


### 代码

```cpp
class Solution
{
public:
    int reverse(int x)
    {
        // 特殊情况处理
        if (x == 0)
        {
            return 0;
        }

        // 初始化变量
        unsigned char number[64] = { 0 };
        int len = 0;

        // 保存符号
        bool is_minus = x < 0;

        // 变量扩容
        long long xx = x;
        // 取绝对值
        xx = is_minus ? -1 * xx : xx;

        // 倒序保存到number中
        while (xx != 0)
        {
            number[len++] = xx % 10;
            xx /= 10;
        }

        // 开始循环取出
        int result = number[0];
        
        // 循环中用INT32_MAX常量来判断“32位符号int”的溢出
        for (int i = 1; i < len; i++)
        {
            // 判断累乘是否会造成溢出
            if (result > INT32_MAX / 10)
            {
                return 0;
            }
            // 不会的话就乘上去
            result *= 10;

            // 判断累加是否会造成溢出
            if (result > INT32_MAX - number[i])
            {
                return 0;
            }
            // 不会的话就加上去
            result += number[i];
        }

        // 带上符号计算结果
        result *= is_minus ? -1 : 1;

        return result;
    }
};
```