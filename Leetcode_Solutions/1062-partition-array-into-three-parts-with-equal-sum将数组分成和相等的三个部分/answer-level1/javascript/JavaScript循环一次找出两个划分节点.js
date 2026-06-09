### 解题思路
根据官方题解思想
设置一个判断参数，循环一次找到两个划分点

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {boolean}
 */
var canThreePartsEqualSum = function(A) {
    if(A[0] == A[1] == A[2] && A.length == 3) return true;
    
    var sum = 0;
    var len = A.length;

    sum = A.reduce((per, next) => per + next, 0);

    if(sum%3 !== 0) return false;

    var divide = sum/3;
    var tempDivide = 0; // 存储数组累加和
    var mark1 = 0;      // 第一个划分节点
    var markExist = 0;  // 判断是否找到第一个划分节点，利用贪心算法，避免找到第二个划分节点重新赋值
    var mark2 = 0;      // 第二个划分节点
    // 本次循环应该在倒数第一个值之前找到第二个划分节点，故循环次数为(len-1)
    for(let i = 0; i < len-1; i++){
        tempDivide = tempDivide + A[i];
        // 找出第一个划分节点，并且第一个划分节点和第二个节点不相等，直接跳过下面代码的执行
        if(tempDivide == divide){
            if(markExist == 0){
                mark1 = i;
                markExist = 1;
                continue;
            }
        }
        // 判断是否是第二个划分节点
        // 是否等于划分和的2倍，并且第一个划分节点已找到
        if(tempDivide == (2 * divide) && (markExist != 0)){
            mark2 = i;
        }
    }

    // 第一个节点存在并且第二个节点存在
    if((markExist != 0) && (mark2 !== 0)){
        return true;
    }else{
        return false;
    }
};
```