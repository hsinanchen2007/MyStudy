
方法一：
```
var isAnagram = function(s, t) {
     if(s.length != t.length) return false;
     return  s.split('').sort().join('') == t.split('').sort().join('');
 }
```
方法二：
```
var isAnagram = function(s, t) {
    if(s.length != t.length) return false;
    let sMap = {};
    let flag = true;
    s.split('').forEach(function(item,index){
        sMap[item]?(sMap[item]++):(sMap[item] = 1);
    })
    let tArr = t.split('');
    for(let i = 0,len = tArr.length;i<len;i++){
        if(sMap[tArr[i]]&&sMap[tArr[i]]>0){
            sMap[tArr[i]]--;
        }else{
            flag = !flag;
            break;
        }
    }
    return flag;
};
```
