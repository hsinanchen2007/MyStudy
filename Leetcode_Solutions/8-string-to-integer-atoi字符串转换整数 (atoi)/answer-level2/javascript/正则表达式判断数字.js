### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
  var res=[];
  var a = /[0-9]/;
  for(let i=0; i<str.length; i++){
      if(str[i]==" "){
        str=str.slice(1,);
        i--
      }
      else{
        break;
      }
          
  }
  if(str.charAt(0)=="+"||str.charAt(0)=="-"||a.test(str[0])){
      if(str.charAt(0)=="+"){
          for(let i=1; i<str.length; i++){
              if(a.test(str[i])){
                  res.push(str[i]);
              }
              else{
                  break;
              }
          }
          res=res.join("");
          res=+res;
      }
      else if(str.charAt(0)=="-"){
          for(let i=1; i<str.length; i++){
              if(a.test(str[i])){
                  res.push(str[i]);
              }
              else{
                  break;
              }
          }
          res=res.join("");
          res=-res;
      }
      else{
          for(let i=0; i<str.length; i++){
              if(a.test(str[i])){
                  res.push(str[i]);
              }
              else{
                  break;
              }
          }
          res=res.join("");
          res=+res;
      }
      if(res>=0) return Math.min(res, (Math.pow(2,31)-1));
      else if(res<0) return Math.max(res, -Math.pow(2,31));
  }
  else {
      return 0;
  }
};
```