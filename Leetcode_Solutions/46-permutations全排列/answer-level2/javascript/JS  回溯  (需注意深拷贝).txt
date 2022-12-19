### 解题思路
 > 无深拷贝就得不到正解
### 代码

```javascript
var permute = function(nums) {
    if(!nums.length) return [];
    const res = [];
    _permute(nums, 0, res);
    return res
};

const _permute = (arr, start, res) => {
    if(start === arr.length){
        res.push(JSON.parse(JSON.stringify(arr)))
        return;
    }
   
    for(let i = start; i < arr.length; i++){
        [arr[i], arr[start]] = [arr[start], arr[i]];
        _permute(arr, start + 1, res);
        [arr[i], arr[start]] = [arr[start], arr[i]];
    }
}
```