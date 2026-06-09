### 解题思路
先排序，然后设置left,right指针分别初始化为第一和第二个元素，依次做差，保存最小值即可

### 代码

```javascript
var minimumAbsDifference = function(arr) {
    arr.sort((a, b) => a - b);
    let left = 0, right = 1, res = [], c = Number.MAX_SAFE_INTEGER;

    while (right < arr.length) {
        let k = arr[right] - arr[left];

        if (k < c) {
            res = [];
            res.push([arr[left], arr[right]]);
            c = k;
        } else if (k == c) {
            res.push([arr[left], arr[right]]);
        }
        left++;
        right++;
    }
    return res;
};
```