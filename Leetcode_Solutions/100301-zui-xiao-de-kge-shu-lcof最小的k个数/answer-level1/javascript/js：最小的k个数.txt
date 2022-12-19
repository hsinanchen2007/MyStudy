### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
        function sortNumber(a,b)
        {
            return a - b
        }
        let arr_num = [];
        for(let i = 0; i < arr.length; i++){
            arr_num[i] = parseInt(arr[i]);
        }

        arr_num.sort(sortNumber);
        let min_k = [];
        for(let i = 0; i < k; i++){
            min_k.push(arr_num[i]);
        }
        return min_k;
    };
```