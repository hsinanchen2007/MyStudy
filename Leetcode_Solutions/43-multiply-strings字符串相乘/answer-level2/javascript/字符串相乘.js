小学的竖式相乘，主要是补0的思想

```javascript
/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var multiply = function(num1, num2) {
    if(num1 === '0' || num2 === '0') return '0';
    let ans = [];
    let pre = 0;
    let temp = [];
    for(let i = num1.length - 1; i >=0; i--) {
        let item =  num1[i];
        for(let j = num2.length -1; j >=0; j--) {
            let val = item * num2[j] + pre;
            let cur = val % 10;
            pre = Math.floor(val/10);
            temp.unshift(cur);
        }
        if(pre > 0) temp.unshift(pre);
        let count = num1.length - 1 - i; // 后面加0的个树
        while(count > 0) {
            temp.push(0);
            --count;
        }
        ans = add(ans,temp);
        // 下次循环temp和pre重置为初始值
        temp = [];
        pre = 0;
    }
    return ans.join('');
};
const add = function(ans,temp) {
    let res = [];
    let pre = 0;
    for(let i= ans.length-1,j= temp.length-1; i>=0 || j>=0; i--,j--) {
        let a = i >=0 ? ans[i]: 0;
        let b = j >=0 ? temp[j]: 0;
        let val = (a + b + pre) % 10;
        pre = Math.floor((a + b + pre)/10);
        res.unshift(val);
    }
    if(pre > 0) res.unshift(pre);
    return res;
}
```