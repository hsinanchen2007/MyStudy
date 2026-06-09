1、如果目标数组中元素个数与输入数组长度相同，则放到结果集中，递归出口
2、取当前数组中的一个元素，如果前面没有遍历到这个元素，则放到目标数组中
3、原数组删除取出的元素，递归删除后的数组

```
var permuteUnique = function (nums) {
    let res = [];
    walk(nums, res, [], nums.length);
    return res;
};

function walk(arr, res, curr, n) {
    if (curr.length == n) {
        res.push(curr);
        return;
    }
    let map = {};
    for (let i = 0; i < arr.length; i++) {
        // 如果是重复数字
        if (!map[arr[i]]) {
            let newArr = curr.concat(arr[i]);
            let copyed = JSON.parse(JSON.stringify(arr));
            copyed.splice(i, 1);
            walk(copyed, res, newArr, n);
            map[arr[i]] = true;
        }
    }
}
```
