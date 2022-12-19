### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
function multiply(num1, num2) {
  if (num1 == "0" || num2 == "0") {
    return "0";
  }
  // 保存计算结果
  var res = "0";
  // num2 逐位与 num1 相乘
  for (let i = num2.length - 1, k=0; i >= 0; i--,k++) {
    var temp = k
    var decade = '';
    var bitRes = '';
    for(let j = num1.length - 1; j>=0 ; j--){
      bitRes = (num1[j] * num2[i] + decade) % 10 + bitRes
      decade = Math.floor((num1[j] * num2[i] + decade)/10)
    }
    while(temp--){
      bitRes = bitRes + '0'
    }
    bitRes = decade > 0 ? decade + bitRes : bitRes
    res = addStrings(res,bitRes)
  }
  return res;
}
/**
 * 对两个字符串数字进行相加，返回字符串形式的和
 */
var addStrings = function(num1, num2) {
  var carry = 0;
  var res = '';
  var i = num1.length-1;
  var j = num2.length-1;
  while(i>=0 || j>=0){
    var temp
    if(i<0){
      temp = Number(num2[j])+carry
    } else if(j<0){
      temp = Number(num1[i])+carry
    } else{
      temp = Number(num1[i])+ Number(num2[j])+carry
    }
    res = temp % 10 + res;
    carry = temp > 9 ? 1 :0;
    i--;
    j--;
  }
  return carry == 1 ? carry + res : res
};
```