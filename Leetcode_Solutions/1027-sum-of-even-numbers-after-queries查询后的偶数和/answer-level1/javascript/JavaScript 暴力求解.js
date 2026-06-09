### 解题思路
- 先求出原来 A 矩阵的偶数和
- 判断 原本位置上的数字是否是偶数 以及 添加之后的数字是否是偶数

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number[][]} queries
 * @return {number[]}
 */
var sumEvenAfterQueries = function(A, queries) {
    let len = A.length
    let answer = []
    let temp = 0
    let sum = 0
    let index = 0
    for(let i = 0; i < len; i++){
        if(A[i] % 2 == 0){
            sum += A[i]
        }
    }
    for (let i = 0; i <len; i++){
        index = queries[i][1]
        temp = A[index]
        A[index] += queries[i][0]
        //以下判断是否进行对 sum值替换，如果替换前后都是偶数，则进行特换，将旧值减去，增加新值
        if(temp%2 == 0 && A[index] %2 == 0){
            sum = sum - temp + A[index]
            answer.push(sum)
        }
        if(temp%2 == 0 && A[index] %2 != 0){
            sum -= temp
            answer.push(sum)
        }
        if(temp%2 != 0 && A[index] %2 == 0){
            sum += A[index]
            answer.push(sum)
        }
        if(temp%2 != 0 && A[index] %2 != 0){
            answer.push(sum)
        }
    }
    return answer 
};
```