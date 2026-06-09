### 解题思路
写进对象 
var in遍历 判断两个不同对象键名-键值是否一致
需要注意 如果长度不一样直接返回false 如果字符串为空也可以直接返回

### 代码

```javascript
/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var CheckPermutation = function (s1, s2) {
    if(s1==''||s2==''||s1.length!=s2.length){
        return false
    }
let newStr1=translateObj(s1);
let newStr2=translateObj(s2);
let res=false;
for(var key in newStr1){
  if(newStr1[key]!=newStr2[key]){
      res=false;
      break;
  }
  res=true  
}
return res
};
function translateObj(str) {
    let obj = {};
    for (let i = 0; i < str.length; i++) {
        if(!obj[str[i]]){
            obj[str[i]]=1
        }else{
            obj[str[i]]+=1
        }
    }
    return obj;
}
```