### 解题思路
找到n的区间
找到n在此区间中的哪个数字上面
找到n在这个数字中的位置并返回

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 * 解题步骤分三步：

找到n的区间
找到n在此区间中的哪个数字上面
找到n在这个数字中的位置并返回
 */
var findNthDigit = function(n) {
    if(n<=9)return n;
    //1-9 站1位 
    //10-99站2位
    let x=1;//累计位数
    let carry=1;//求出是几位数
    while(x < n){

        x += 9 * Math.pow(10,carry-1)*carry;
        carry++;
    }
   // console.log(carry);
    carry--;
    x -= 9 * Math.pow(10,carry-1)*carry;//累计位数
    let num= Math.pow(10,carry-1) + Math.floor((n-x) / carry );//位于第几个数
    let mod = (n-x)%carry;
    console.log(carry,x,num,mod);
    return +num.toString()[mod];
    





    
};
```