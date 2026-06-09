### 解题思路
1.将每个字符存到map中，值是出现的次数
2.对每一个map中的{key,value}对象，使用map的forEach方法存入数组中（注意forEach函数的参数是(value，key))
3.对数组arr按照出现次数从大到小排序
4.依次输出字符即可

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var frequencySort = function(s) {
    var map=new Map();
    for(var i=0;i<s.length;i++){
        if(map.has(s[i])){
            map.set(s[i],map.get(s[i])+1);
        }else{
            map.set(s[i],1);
        }
    }
    var arr=[];
    map.forEach((v,k)=>arr.push({name:k,value:v}));
    arr.sort((a,b)=>b.value-a.value);
    var res='';
    for(var i=0;i<arr.length;i++){
        for(var j=0;j<arr[i].value;j++){
            res += arr[i].name;
        }
    }
    return res;
};
```