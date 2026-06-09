### 解题思路
此处撰写解题思路

首先用parseInt方法解析字符串，再看是否得出NaN，再判断大小是否超出范围
### 代码

```javascript
/**
 * @param {string} str
 * @return {number}
 */
  var myAtoi = function(str) {
      let num=parseInt(str);
      let max = Math.pow(2, 31)-1;
      let min = -max-1;
      if(Number.isNaN(num)){
          num = 0
      }else if(num<min){
          num=min
      }else if(num>max){
          num=max
      }
      return num
  };
```