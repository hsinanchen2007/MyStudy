### 解题思路
先算总和，循环A，累加到总和的三分之一，做一次标记b，还原一次r；
最终判断b为三时且s不为零，或b大于等于3且s为0时，返回true。
计算和的时候这么写感觉更好（搬运）：
Array.prototype.sum = function () { // 定义求数组和方法
  return this.reduce((a, b) => a + b, 0)
}

A.sum() //数组和

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {boolean}
 */
var canThreePartsEqualSum = function(A) {
    let s=A.reduce((a,b)=>a+b,0);
    let r=0,b=0;
    for(let i=0;i<A.length;i++){
        r+=A[i];
        if(r===s/3){
            b++
            r=0
        }
    }
    return (b===3&&s!==0)||(b>=3&&s===0)
};
```