### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/6219c536f0c62d5ce839f6fbd0caea8a6153babf095496b45bf4354be231f071-image.png)

### 代码

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function(target) {
    // 初始化窗口指针和输出列表
    let i = 1, j = 2, res = [];

    // 滑动窗口的右边界不能超过target的中值
    while (j <= target/2 + 1) {
        let num = (i + j) * (j - i + 1) / 2;
        if (num < target) {
            j++;
        } else if (num > target) {
            i++;
        } else {
            let arr = Array(j - i + 1).fill(i);
            let arr1 = arr.map((item,index) => {
                return item = item + index;
            });
            res.push(arr1);
            j++;
        }
    }
    return res
};
```