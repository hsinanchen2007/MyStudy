### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var subtractProductAndSum = function(n) {
    if(n==1)return 0;
    const broken = n=> {
        const arr=[];
        while(n>=1){
            arr.push(n%10);
            n=Math.floor(n/10);
        }
        return arr;
    }
    const ba = broken(n); //得出一个保存了各个位上的数字的数组
    const M = ba.reduce((a, b)=>a*b);
    const P = ba.reduce((a, b)=>a+b);
    return  M-P; 
};
```