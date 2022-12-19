### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var luckyNumbers  = function(matrix) {
    const res = [];
    for(let i=0; i<matrix.length; i++){
        const row = matrix[i];
        const min = Math.min(...row); //取出这行最小的
        let foundLarger = false;
        const index = row.indexOf(min);
        for(let j=0; j<matrix.length; j++){
            if(matrix[j][index]>min){ //遍历这一列所有元素，根据题目要求，如果这列找到更大的就说明上面找到的min不是幸运数
                foundLarger = true;
                break;
            }
        }
        if(!foundLarger){
            res.push(min);
        }
    }
    return res;
};
```