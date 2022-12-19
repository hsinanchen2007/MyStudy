![image.png](https://pic.leetcode-cn.com/678776edf5b961874ddd626b1f4110892fbc45e73375cea753daf89fdd05e925-image.png)

主要思路：
    1. 二分法找到`target`所在的数组在`matrix` 中的位置 获得 `s`
    2. 二分法查找`s` 中是否存在`target` 存在 返回`true`否则返回`false`
    
直接看代码,代码可能比较长 但是思路比较好理解
```
var searchMatrix = function (matrix, target) {
    let len = matrix.length
    let l = 0
    let r = len
    if (!len) return false
    while (l < r) {
        let mid = Math.floor((l + r) / 2)
        let midtarget = matrix[mid][0]
        if (target === midtarget) return true
        if (target > midtarget) {
            l = mid + 1
        } else {
            r = mid
        }
    }
    if (l - 1 < 0) return false
    let s = matrix[l - 1]
    let ml = 0
    let mr = s.length
    while (ml < mr) {
        let mid = Math.floor((ml + mr) / 2)
        let midtarget = s[mid]
        if (target === midtarget) return true
        if (target > midtarget) {
            ml = mid + 1
        } else {
            mr = mid
        }
    }
    return false
};
```

实现步骤：
1.首先判断边界条件`matrix=[] || matrix=[[]]` 都返回 `false`
2.首先比较`target`与每个子数组的首位的大小 通过二分法确定 目标元素所在数组的下标 
        `-> 只比较每个数组第一个元素与目标元素的大小`
3.在第二步获得数组中查找 `target` 返回 `true || false`
4.Ok

