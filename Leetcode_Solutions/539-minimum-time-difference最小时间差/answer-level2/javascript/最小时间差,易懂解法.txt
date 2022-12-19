### 解题思路
转换成分钟，塞进一新数组，然后新数组升序排序，本体重点理解：arr[0]+1440，其是为了解决'小时差'大于12小时的情况。

### 代码

```javascript
/**)
 * @param {string[]} timePoints
 * @return {number}
 */
var findMinDifference = function(timePoints) {
    var arr = [];
    for(let i = 0; i < timePoints.length; i++){
        let k = Number(timePoints[i].substring(0,2)) * 60 + Number(timePoints[i].substring(3,5));
        arr.push(k);
    }
    arr = arr.sort(function(a,b){
        return a - b;
    })
    arr.push(arr[0] + 1440);
    var newArr = [];
    for(let j = 1; j < arr.length; j++){
        var newElem = arr[j] - arr[j-1];
        newArr.push(newElem);
    }
    return Math.min(...newArr);

};
```