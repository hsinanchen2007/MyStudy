### 解题思路
见注释

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {boolean}
 */
var canThreePartsEqualSum = function(A) {
    let sum = A.mySum();             // 数组的累加和
    if(sum % 3 !== 0) return false;  // 不能被3整除，则return false
    let avgrage = parseInt(sum/3);   /* 每个部分应该累加的和 */
    let temp = 0;  // 记录每部分的累加
    let count = 0; // 记录分成部分的个数
    for(let i=0;i<A.length;i++) {
        temp += A[i];
        if(temp === avgrage) { // 累加和达到平均值，说明可分为一个部分
            temp = 0; // 重置为0，准备下一部分的累加
            count++; 
            if(count === 2) { 
                // count为2时，说明已经分好了两个部分
                // 如果第二个部分分好时，累加的最后一个数字刚好是数组A的最后一个数字，说明此数组只能分为两个部分，因此返回false
                // 如果累加的最后一个数字不是数组A的最后一个数字，那么不管后面还有多少个数字，它们的累加和一定等于平均值
                if(i === A.length-1) {
                    return false;
                }
                return true;
            }
        }  
    }
    return false;
};

Array.prototype.mySum = function() {
    return this.reduce((a,b)=>a+b, 0);
}

```