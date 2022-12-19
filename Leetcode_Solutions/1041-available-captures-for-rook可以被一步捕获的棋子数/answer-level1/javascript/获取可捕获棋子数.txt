### 解题思路
1. 获取 R 所在位置的 x 轴数据和 y 轴数据；
2. 找到 R 在数据中所在位置，以R 为终点位置向前遍历，获取 B、p 的位置进行分情况比较；
3. 类似2，以R 为起点位置向后遍历，获取 B、p 的位置进行分情况比较；
4. 结果相加得到最后结果

### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function(board) {
    let xData = [];
    let yData = [];
    let centerIndex;
    (board || []).forEach((data, index) => {
        (data || []).forEach((item, i) => {
            if(item === 'R') {
                yData = data;
                centerIndex = i;
            }
        })
    });
    (board || []).forEach((data, index) => {
        xData.push(data[centerIndex]);
    });
    return getP(xData) + getP(yData);
};
// 获取单行数据的结果
function getP(data) {
    let count = 0;
    const index = data.indexOf('R');
    return getLastIndex(data, index) + getIndex(data, index);
}
// 获取左侧的值
function getLastIndex(data, index) {
    const BIndex = data.lastIndexOf('B', index);
    const pIndex = data.lastIndexOf('p', index);
    if(BIndex === -1) {
        return pIndex === -1 ? 0 : 1;
    }
    else if (pIndex === -1){
        return 0;
    }
    else {
        return pIndex > BIndex ? 1 : 0;
    }
}
// 获取右侧的值
function getIndex(data, index) {
    const BIndex = data.indexOf('B', index);
    const pIndex = data.indexOf('p', index);
    if(BIndex === -1) {
        return pIndex === -1 ? 0 : 1;
    }
    else if (pIndex === -1){
        return 0;
    }
    else {
        return pIndex < BIndex ? 1 : 0;
    }
}
```
