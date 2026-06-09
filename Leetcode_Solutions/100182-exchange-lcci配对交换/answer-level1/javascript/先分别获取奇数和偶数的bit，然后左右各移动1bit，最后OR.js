### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} num
 * @return {number}
 */
var exchangeBits = function(num) {
    //获取偶数位和奇数位，后面那段二进制很笨很直接。。。
    let even=num & 0b101010101010101010101010101010;
    let odds=num & 0b010101010101010101010101010101;
    //左右各移动一个bit, 如2(偶数位为1)->右移动后->01, 奇数位0左移得到00 
    even>>>=1;
    odds<<=1;
    return even|odds; //OR相当于交换当前位的bit值如2的话：01 OR 00->01, 3的话：10 OR 01->11
};
```