### 解题思路
用正则不知道算不算作弊。。但是是真的好用呀。。。正则轻松搞定

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var decodeString = function(s) {
    let reg = /(\d+)\[([a-zA-Z]+)\]/g;
    while(s.indexOf('[')>0){
        s = s.replace(reg,(_,...[num,str])=>{
            let result = "";
            for(let i=0;i<num-0;i++){
                result += str;
            }
            return result;
        });
    }
    return s;
};
```