思路：
1. 首先对数组最后一位加一
2. 循环遍历，从个位开始，即数组最后一位
3. 如果它为10，将它变为0，它的上一个下标的数加一，以此类推
4. 当进行到第一位时，如果它为10，同样将它变为0，只不过它没有上一个下标的数，这时候使用unshift()方法在头部插入一个数1
```
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    var length = digits.length;
    digits[length - 1] = digits[length - 1] + 1;
    for(var i = length - 1;i >= 0;i --){
        if(digits[i] == 10){
            digits[i] = 0;
            if(i != 0){
                digits[i - 1] = digits[i - 1] + 1;
            }
            else{
                digits.unshift(1);
            }
        }
    }
    return digits;
};
```
