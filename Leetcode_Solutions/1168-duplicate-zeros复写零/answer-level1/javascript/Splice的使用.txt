### 解题思路
1. 遍历数组
2. 碰到0， 在后边插入一个0
3. 弹出末尾的一个元素

### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {void} Do not return anything, modify arr in-place instead.
 */
var duplicateZeros = function(arr) {
    for(let i=0; i<arr.length; i++){
        if(arr[i] == 0){
            arr.splice(i, 0, 0);
            arr.pop();
            i++;
        }
    }
    return arr;
};
```