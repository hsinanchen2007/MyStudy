### 解题思路
![image.png](https://pic.leetcode-cn.com/d2c268632c1be52f75cba122c2ddabe4a9136bcb1090f18e26ed1671c5151664-image.png)

- 通过 obj 进行计数
- 判断两个 obj是否有相同项，如果有添加的 res数组中
### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
    debugger;
    let a = {}
    let b = {}
    for(let i of nums1){
        a[i] = !a[i] ? 1 : ++a[i]
    }
    for(let i of nums2){
        b[i] = !b[i] ? 1 : ++b[i]
    }
    let res = []
    for(let i in a){
        if(a[i] && b[i]){
            let len = a[i] > b[i] ? b[i] : a[i]
            for(let j = 0; j < len; j++){
                res.push(i)
            }
        }
    }
    return res
};
```