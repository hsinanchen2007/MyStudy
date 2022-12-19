### 解题思路
先直接用js sort方法递增排序,然后当前比较数组的当前元素和上一个元素。让所有元素保持不重复的递增即可
### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
        var minIncrementForUnique = function (A) {
            A.sort((a, b) => { return a - b });
            let temp = 0;
            let out = 0;
            for (let index = 1; index < A.length; index++) {
                temp = A[index - 1]
                if (A[index] <= temp) {
                    out += temp - A[index] + 1;
                    A[index] += temp - A[index] + 1;
                }
            }
            return out
        };
```