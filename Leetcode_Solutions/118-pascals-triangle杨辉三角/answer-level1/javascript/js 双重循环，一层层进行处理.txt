### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} numRows
 * @return {number[][]}
 * 每一行有对应的几个数
 * 每个数j都是上一行(i-1)的(j-1)和j的值，如果上一行(i-1)的(j-1)或j不存在，那么值为0
 * 一层层进行处理
 */
var generate = function(numRows) {
    let arr = [];
    for(let i = 0; i < numRows; i++){
        let tmp = [];
        
        for(let j = 0; j <= i; j++){
            if(i==0){
                tmp.push(1);
                continue;
            };
            // arr[i-1]：上一行
            // [j-1]：左边的数，j：右边的数
            let left = j == 0 ? 0 : arr[i-1][j-1];
            let right = arr[i-1][j] ? arr[i-1][j] : 0;
            tmp.push(left+right);
        }

        arr[i]=tmp;
    }

    return arr;
};
```