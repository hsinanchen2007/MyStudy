### 解题思路
此处撰写解题思路
1、把数组调转，只有第一项加一，然后加一之后对可能出现的情况进行判断，当出现个位数进一的时候判断i+1项是否有值没值直接开辟一个新的数组空间，并赋值为1
2、懒人解法利用js内置的方法。此处不使用Number的原因是，考虑会出现数字位数过长会超出Number的范围，BigInt数据类型的目的是比Number数据类型支持的范围更大的整数值。在对大整数执行数学运算时，以任意精度表示整数的能力尤为重要。使用BigInt，整数溢出将不再是问题。BigInt类型相加需要在数字后面加n 类似109n+1n
### 代码
1、
```javascript
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    var digitArr = digits.reverse()
    for(var i = 0;i<digitArr.length;i++)
    {
        if(i==0)
        {
           digitArr[0]= digitArr[0]+1
        }

        if(digitArr[i]>=10)
        {
            digitArr[i] = 0;
            if(!digitArr[i+1])
            {
                digitArr[i+1] = 1
            }else
            {
                digitArr[i+1] = digitArr[i+1]+1
            }
         
        }
    }
    return digitArr.reverse()
};
```
2、
```javascript
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    return String(BigInt(digits.join(""))+1n).split("")
}
```