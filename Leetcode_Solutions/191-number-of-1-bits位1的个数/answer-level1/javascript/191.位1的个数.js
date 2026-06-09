### 解题思路
方法一、
与上一题颠倒二进制位相同的解法，先转换为字符串，存入数组，判断‘1’的个数
注意n是一个十进制数字，要先转化为32位的二进制字符串
### 代码

```javascript
/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
    var temp=n.toString(2).padStart(32,'0').split('');
    var count=0;
    for(var i=0;i<temp.length;i++){
        if(temp[i]==='1'){
            count++;
        }
    }
    return count;
};
```
方法二、位移动
![屏幕快照 2020-03-03 下午1.28.26.png](https://pic.leetcode-cn.com/615e3c8303f3e59f2b2047ea131393c791b0f1f51d2be0fd6cc0c7aeac3e9ac0-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-03%20%E4%B8%8B%E5%8D%881.28.26.png)
```
var hammingWeight = function(n) {
    var bits=0;
    var mask=1;
    for(var i=0;i<32;i++) {
        if((n&mask)!=0) {
            bits++;
        }
        mask<<=1;
    }
    return bits;
};
```