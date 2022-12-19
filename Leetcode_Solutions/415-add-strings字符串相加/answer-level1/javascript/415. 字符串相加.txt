### 解题思路

+ `max`取两数最大的长度，
+ 递减循环一位一位进行计算，
+ `%`大于10，取0，
+ `floor`向下取整，
+ 最后一位，且大于10则直接补一位，返回，否则循环结束返回结果；

### 代码

```javascript
/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var addStrings = function(num1, num2) {

  let len1 = num1.length-1;
  let len2 = num2.length-1;
  let maxNum = Math.max(len1,len2);
  let result ="";
  let carry = 0;
  for(let i=0;i<=maxNum;i++){
    let key1 = parseInt(num1[len1-i]||0);
    let key2 = parseInt(num2[len2-i]||0);
    let item = key1+ key2 + carry;
    result = (item%10)+result;
    carry = Math.floor(item/10);
    if(i == maxNum && carry == 1){
      return carry+result;
    } 
  }
  return result;
};
```