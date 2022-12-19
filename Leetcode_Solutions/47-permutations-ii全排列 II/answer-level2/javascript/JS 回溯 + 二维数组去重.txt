### 解题思路
>##### 46题结果 + 二维数组去重 
### 代码

```javascript
var permuteUnique = function(nums) {
    if(!nums.length) return [];
    const res = [];
    _permute(nums, 0, res);
    const unique = (res) => {
  	var temp = {}, r = [], len = res.length, val, type;
  	for(let i = 0; i < len; i++){
  		val = res[i];
  		type = typeof val;
  		if(!temp[val]){
  			temp[val] = [type];
  			r.push(val);
  		}else if(temp[val].indexOf(type) < 0){
  			temp[val].push(type);
  			r.push(val);
  		}
  	}
  	return r;
  }
  const result = unique(res);
  return result
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