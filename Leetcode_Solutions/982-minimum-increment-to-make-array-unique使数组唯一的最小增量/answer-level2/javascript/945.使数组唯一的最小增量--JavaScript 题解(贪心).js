将数组排序后，用贪心求解
eg：
[3,2,1,2,1,7]
排序后：
[1,1,2,2,3,7]
贪心：
[1,2,3,4,5,7]

```
var minIncrementForUnique = function (A) {
    A.sort((a, b) => a - b);
    var res = 0;
    var temp = A[0];
    for (var i = 1; i < A.length; i++) {
        if (temp >= A[i]) {
            temp++;
            res+=(temp-A[i]);
        }else{
            temp=A[i]
        }
    }
    return res;
};
```
