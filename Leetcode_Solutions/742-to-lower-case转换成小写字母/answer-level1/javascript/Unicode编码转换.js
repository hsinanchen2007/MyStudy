### 解题思路
根据字母大小学的Unicode编码来重新赋值。
A-Z = [65,90];
a-z = [97,122]
大小写Unicode差32，
str.charCodeAt(index)返回指定位置Unicode编码
String.fromCharCode(code)将Unicode编码转换为字符

### 代码

```javascript
/**
 * @param {string} str
 * @return {string}
 */
var toLowerCase = function(str) {
    //return str.toLocaleLowerCase();
    var result = "";
    for(i=0;i<str.length;i++){
        var code = str.charCodeAt(i);
        if(code>=65&&code<=90){
            result+=String.fromCharCode(code+32)
        }
        else{
            result+=str[i]
        }
    }
    return result
};
```