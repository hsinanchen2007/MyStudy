### 解题思路
![image.png](https://pic.leetcode-cn.com/8f55b702589ab9a6f8fdff7ff983425cc95aa169d25e0e3858b9c64dab646411-image.png)
-遍历，arr[i] 赋值为 通过Math.max进行找到最大值
### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {number[]}
 */
var replaceElements = function(arr) {
    for(let i = 0; i < arr.length; i++){
        if(i == (arr.length - 1)){
            arr[arr.length - 1] = -1
            break;
        }else{
            arr[i] = Math.max.apply(null,arr.slice(i+1))
        }
        
    }
    return arr
};
```