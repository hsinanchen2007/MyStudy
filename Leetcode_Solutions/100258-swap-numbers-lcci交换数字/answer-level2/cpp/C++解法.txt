> 思路描述：这一题主要是不让使用临时变量这一个难点，
>
> 比如说互换a,b，突然想到下面的算法

$a=a+b,b=a-b=a,a=a-b=b$

但是有可能会溢出，所以我们可以先除以2再进行加减

$a=\frac{a}{2}+\frac{b}{2},b=a-\frac{b}{2}=\frac{a}{2},a=a-b=\frac{b}{2}\\a=2a=b,b=2b=a$

其中需要注意到a，b是奇偶的问题，所以强制类型转换也是一种方法。

```C++
class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        numbers[0] = (long long)numbers[0] + numbers[1];
        numbers[1] = (long long)numbers[0] - numbers[1];
        numbers[0] = (long long)numbers[0] - numbers[1];
        return numbers;
    }
};
```

> 使用异或
>
> a ^ b ^ b = a 
>
> a ^ b ^ a = b
>
> a ^ a = 0  
>
> 0 ^ a = a
>
> 异或满足交换律 结合律
>
> a = a^b，b = a^b = a，a = a^b = b

```C++
class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        numbers[0] = numbers[0]^numbers[1];
        numbers[1] = numbers[0]^numbers[1];
        numbers[0] = numbers[0]^numbers[1];
        return numbers;
    }
};
```

但还是异或合适一些