#### 思路（贪心算法）
1. 根据已知的罗马数字和整数的映射关系，按数值大小，从大到小，初始化两个数组，一个放字符，一个放数值；
2. 将`num`拆解，比如：`2387 = 2000 + 300 + 80 + 7`；
3. 从`map`中找到最接近该数的值去匹配；
4. 比如：`2000`，只能用2个`M（1000）`；
5. `300`只能用3个`C（100）`；
6. `80`先用一个`L（50）`，还剩`30`，再用3个`X（10）`；
7. `7`先用一个`V（5）`，再用2个`I（1）`；
8. 最终结果：`MMCCCLXXXVII`。
#### 代码
```
var intToRoman = function(num) {
    // 之所以用两个数组而不用map，因为Object.keys()取出的key数组顺序不确定
    let valueArray = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
    let romanArray = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I'];
    let result = '';
    valueArray.forEach((key, index) => {
        while (parseInt(num / key) !== 0) {
            // 取出需要key的个数
            let count = parseInt(num / key);
            for (let i = 0; i < count; i++) {
                // 拼接罗马字符
                result += romanArray[index];
            }
            // 继续判断剩下的数
            num %= key;
        }
    })
    return result;
};
```
