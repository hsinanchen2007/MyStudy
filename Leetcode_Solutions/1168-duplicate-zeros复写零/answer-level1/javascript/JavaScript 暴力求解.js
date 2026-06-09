### 解题思路
![image.png](https://pic.leetcode-cn.com/459f060eb5268a1f0f0cfa6f2a5684ad43fde1c7637491c962543f8b8e73d8ad-image.png)

- for循环遍历，如果发现某一项是 0 则通过 Array.splice(start,deletecitem, addItem)方法添加 0
- 添加一个 0 ，pop() 最后一个元素

### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {void} Do not return anything, modify arr in-place instead.
 */
var duplicateZeros = function(arr) {
    for(let i = 0; i < arr.length; i++){
        if(arr[i] == 0){
           arr.splice(i,0,0)
            arr.pop()
            //当添加了一个元素，需要跳过一个index，否者一直添加 0
            i++
        }
    }
    return arr
};
```