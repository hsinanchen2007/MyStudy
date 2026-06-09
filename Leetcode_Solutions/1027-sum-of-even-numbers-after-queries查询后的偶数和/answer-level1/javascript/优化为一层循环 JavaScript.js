### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number[][]} queries
 * @return {number[]}
 */
var sumEvenAfterQueries = function(A, queries) {
    //return值
    var answer = [];
    //当前状态下的和
    var sum = 0;
    A.forEach((item) => {
        sum += item&1 ? 0 : item;
    })
    //遍历循环每次变化的值
    for(var i = 0; i < A.length; i++){
        const val = queries[i][0], index = queries[i][1];
        //根据奇偶性处理和sum的值
        if(val&1){
            if(A[index]&1) sum += A[index]+val;
            else sum -= A[index];
        }
        else{
            if(A[index]&1) sum += 0;
            else sum += val;
        }
        //更改index的值
        A[index] += val;
        //将和添加到answer中
        answer[i] = sum;
    }
    return answer;
};
```