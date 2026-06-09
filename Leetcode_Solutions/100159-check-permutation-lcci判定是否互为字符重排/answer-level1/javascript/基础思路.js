### 解题思路
比较直观的思路吧
1. 确保两个字符长度相等
2. 循环其中一个数组，然后弹出最后一项，在另一个数组中进行查找
    - 获取不到下标，则为非
    - 获取得到下表，将该项剔除
    - 进入下个循环

### 代码

```javascript
/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var CheckPermutation = function(s1, s2) {
    if (s1.length !== s2.length) {
        return false
    }

    let s1Arr = s1.split('');
    let s2Arr = s2.split('');
    while (s1Arr.length > 0) {
        let ele = s1Arr.pop();
        let index = s2Arr.indexOf(ele);

        //找不到
        if (index === -1) {
            return false
        }

        s2Arr.splice(index, 1);
    }
    return true;
};
```