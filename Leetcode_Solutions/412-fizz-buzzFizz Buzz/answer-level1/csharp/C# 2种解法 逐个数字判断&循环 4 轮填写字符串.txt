### 解法一

##### 1. 题目概述：按照题目要求输出字符串数组

##### 2. 思路：
   - 特征：能被 3 和 5 各自以及全部整数的数字,是有规律的,没有必要每次都判断
   - 方案：先按照数字吧返回值填满,然后找到能被 3 整除的,把值覆盖上去,找到能被 5 整除的,把值覆盖,最后找到 15,把值覆盖
   - 结果：经常以上 4 轮操作以后,得到的就是所期望的解

##### 3. 知识点：数组

##### 4. 复杂度分析: 
   - 时间复杂度：O(n)
   - 空间复杂度：O(n)

```C# []
        public IList<string> FizzBuzz(int n)
        {
            var const3Str = "Fizz";
            var const5Str = "Buzz";
            var const35Str = "FizzBuzz";

            var forReturn = new List<string>(n);
            for (var i = 1; i <= n; i++)
                forReturn.Add(i.ToString());

            for (var i = 2; i < n; i += 3)
                forReturn[i] = const3Str;

            for (var i = 4; i < n; i += 5)
                forReturn[i] = const5Str;

            for (var i = 14; i < n; i += 15)
                forReturn[i] = const35Str;

            return forReturn;
        }
```

### 解法二

##### 1. 题目概述：将满足特定条件的数字字符串,用其它字符串来代替

##### 2. 思路：
   - 特征：若无特殊规则,这就是一个数字的循环和输出题,但是题目规定了满足特定条件时,要用其它字符串来代替原本的数字字符串
   - 方案：依次循环,满足特定规则,那么就按照规则来,否则,就输出原来的数字字符串
   - 结果：从 1 循环到 n 最后可得解

##### 3. 知识点：数组 取余

##### 4. 复杂度分析: 
   - 时间复杂度：O(n)
   - 空间复杂度：O(n)


```C# []
        public IList<string> FizzBuzz1(int n)
        {
            var const3Str = "Fizz";
            var const5Str = "Buzz";
            var const35Str = "FizzBuzz";

            var forReturn = new List<string>(n);
            for (int i = 1; i <= n; i++)
            {
                if (i % 3 == 0 || i % 5 == 0)
                {
                    if (i % 3 == 0 && i % 5 == 0)
                        forReturn.Add(const35Str);
                    else if (i % 3 == 0)
                        forReturn.Add(const3Str);
                    else
                        forReturn.Add(const5Str);
                }
                else
                {
                    forReturn.Add(i.ToString());
                }
            }

            return forReturn;
        }
```


