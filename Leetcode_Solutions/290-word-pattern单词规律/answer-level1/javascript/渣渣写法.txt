
```
var wordPattern = function(pattern, str) {
 let arr= pattern.split('');
    let arr2 = str.split(' ');
    let isT = true;
    if(arr.length!==arr2.length) return false;
    let obj = {};
    let obj2={};
    arr.forEach((item,i)=>{
        if(obj[item]&&obj[item].length){
            obj[item].push(i);
        }else{
            obj[item]=[i];
        }
    })
     arr2.forEach((item,i)=>{
        if(obj2[item]&&obj2[item].length){
            obj2[item].push(i);
        }else{
            obj2[item]=[i];
        }
    })
    const a = JSON.stringify(Object.values(obj));
    const b =JSON.stringify(Object.values(obj2));
	if(a!==b) isT = false
    return isT;
};

```
 感谢父老乡亲，感谢亲戚朋友，感谢老师的细心教导和自己的努力抄袭...最后的转字符串有点low了只能针对这题
