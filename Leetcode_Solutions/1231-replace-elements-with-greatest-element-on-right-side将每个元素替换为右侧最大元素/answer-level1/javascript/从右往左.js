### 解题思路
从右往左，通过比较max和当前值来更新max即可

### 代码

```javascript []
var replaceElements = function(arr) {
    let max = -1, res = [];

    for (let i = arr.length - 1; i >= 0; i--) {
        res[i] = max;
        max = arr[i] > max ? arr[i] : max;
    }
    return res;
};
```
```java []
class Solution {
    public int[] replaceElements(int[] arr) {
        int[] res = new int[arr.length];
        int max = -1;

        for (int i = arr.length - 1; i >= 0; i--) {
            res[i] = max;
            max = arr[i] > max ? arr[i] : max;
        }
        
        return res;
    }
}
```
