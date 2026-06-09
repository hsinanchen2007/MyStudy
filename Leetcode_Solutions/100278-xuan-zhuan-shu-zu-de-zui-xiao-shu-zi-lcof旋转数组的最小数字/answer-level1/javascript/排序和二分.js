### 解题思路
1.根据函数：
```
    const arr = numbers.sort((a,b) => a-b);
    return arr[0]
```
2.一行代码：

```
return Math.min(...nums); 

```
众所周知，二分用于有序数组，但我们可以用二分缩小范围
### 代码

```javascript
/**
 * @param {number[]} numbers
 * @return {number}
 */
var minArray = function(numbers) {
    let l = 0;
    let r = numbers.length-1;

    while(l<r){
        //算中间值
        let mid = (l+r) >>> 1;
        //如果中值大于r值，说明l那边元素比较大，缩小范围
        if(numbers[mid]>numbers[r]){
            l = mid+1
        //如果中和r相同，r-1，减少r范围
        }else if(numbers[mid] == numbers[r]){
            r= r-1;
        }else{
        //如果r值大，说明l是最小区间
            r = mid
        }
    }

    //此时只剩一个了 l和r都可以
    return numbers[l]
};
```