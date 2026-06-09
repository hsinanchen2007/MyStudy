哈希表以数组strs元素按Unicode字符排序后的字符串为键，以存储字母异位字符串数组为值，键相同则值进行添加，不同直接设置
```js
var groupAnagrams = function(strs) {
    var res = [];
    var map = new Map();
    for(var i=0;i<strs.length;i++){
        var k = strs[i].split('').sort().join('');
        if(map.has(k)){
            map.get(k).push(strs[i]);
        }else{
            map.set(k, [strs[i]]);    
        }
    }
    map.forEach((val, key)=>{
        res.push(val);
    })
    return res;
    
};
```