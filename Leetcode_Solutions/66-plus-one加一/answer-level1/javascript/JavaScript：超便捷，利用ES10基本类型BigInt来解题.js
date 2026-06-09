由于JavaScript的某些Feature导致这道题使用JS实现起来特别简单。

现在来阐述下主要解题思路：

1. 已知传入参数必定为数值型数组
2. 将参数转换为字符型（Array.prototype.join()）
3. 由字符型变为整型（Number构造函数)）
4. 整型可以进行普通的数学计算
5. 计算结果再次变为字符型（String构造函数）
6. 将字符型数值变更为数组（String.prototype.split()）

这是最开始的解题思路，不过着进行测试时，发现了一个问题：
Number基本类型的存储范围在`-(2^53-1)`到`(2^53-1)`之间。

leetcode的测试用例`[6,1,4,5,3,9,0,1,9,5,1,8,6,7,0,5,5,4,4]`超出了这个范围。

而在ES10中，规范新引入了一种基本数据类型`BigInt`。它可以完美地兼容大数。

关于`BigInt`的其他知识点本处不详细阐述，只简单阐述下本例需要使用的相应知识点。

使用`BigInt构造函数`生成的数值，会在数值的末尾加个`n`。如：
```
BigInt(123) // 输出：123n
```
对`BigInt`类型的数值进行操作时，要特别注意，该类型不可与`Number`实例进行操作。

```
BigInt(123) + 1 // Error，数值1是Nuber基本类型
BigInt(123) + 1n // Success, 1n是BigInt基本类型，就是Number类型中的1，输出：124n
```

所以需要部分纠正下之前的解题思路：
1. 已知传入参数必定为数值型数组
2. 将参数转换为字符型（Array.prototype.join()）
3. **由字符型变为BigInt型（BigInt构造函数)**）
4. **进行专属于BigInt类型的数学计算**
5. 计算结果再次变为字符型（String构造函数）
6. 将字符型数值变更为数组（String.prototype.split()）

以下是相应的代码实现：
```
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    // 数值6145390195186705544超出Number基本类型的容纳范围，改用BigInt基本类型
    let num = BigInt(digits.join(''));
    // BigInt基本类型进行数学操作时，需要在数字字面量后加个n
    let string = String(num + 1n);
    let ary = string.split('');

    return ary.map(str => Number(str));
};
```
