先排序，然后取前k位的字符，坑点sort方法会把数组这么排[1,2,3,4,11,22,33,44] => [1,11,2,22,3,33,4,44]

```
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    // js中sort()不能对数字正确排序所以
    return arr.sort(sequence).splice(0,k)
};
function sequence(a,b){
    if(a>b) return 1;
    else if(a<b)return -1
    else return 0
}
```
