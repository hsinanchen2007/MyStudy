### 解题思路
此处撰写解题思路


### 代码

```javascript
/**
 * @param {string} text
 * @return {number}
 */
var maxNumberOfBalloons = function (text) {
        let map = {}, arr = []
    for (let element of text) {
        map[element] = (map[element] || 0) + 1
        // 记录每个字母出现的次数
    }

    for (let index of "balon") {
        arr.push(map[index] || 0)
        // 将 balon 字母出现的次数存到数组中
    }
        // 将 l o 的次数除以二，因为需要两个
    arr[2] = Math.floor(arr[2] / 2); // l
    arr[3] = Math.floor(arr[3] / 2); // o
        //求出最小的那个，即是最后的结果
    return Math.min(... arr)
    
};
```