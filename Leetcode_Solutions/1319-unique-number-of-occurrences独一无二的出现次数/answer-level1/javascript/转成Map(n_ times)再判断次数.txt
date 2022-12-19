### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {boolean}
 */
var uniqueOccurrences = function(arr) {
    function toMap(arr){
        return arr.reduce((obj, ele)=>{
            if(obj[ele]){
                obj[ele] = obj[ele]+1;
            }else{
                obj[ele]=1;
            }
            return obj;
        }, {});
    }
    const result = Object.values(toMap(Object.values(toMap(arr))));
    for(let v of result){
        if(v!=1)return false;
    }
    return true;
};
```