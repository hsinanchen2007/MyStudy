### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
if (n === 1 ) { return n.toString()}
let temp = ['1'];  // 第一项为['1'], 第二项为['1','1'],第三项为['2','1']
for(let x= 2,y = 0; x<= n; x++) {
    let num = 1
    let arr = []
    while(y<=temp.length) {
        if(temp[y] === temp [y+1]) {
            num++
        } else {
            arr.push(num.toString(), temp[y])
            num = 1
        }
        y++
    }
    y= 0
    temp=arr  // 第x项的字符串数组
}
return temp.join('')
};
```