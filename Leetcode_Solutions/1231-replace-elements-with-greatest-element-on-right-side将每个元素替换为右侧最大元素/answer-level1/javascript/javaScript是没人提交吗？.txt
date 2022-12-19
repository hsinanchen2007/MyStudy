### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {number[]}
 */
var replaceElements = function(arr) {
    for(let i = 0; i < arr.length;++i)
    {
        let newArr = arr.slice(i+1,arr.length)
        arr[i] = Math.max(...newArr)
    }
    arr[arr.length-1] = -1
    return arr
};
```

![image.png](https://pic.leetcode-cn.com/66ba04b9dd45796b53da36f9802744e374c8529a5ea9330ffc59e6ca13d8fd44-image.png)
