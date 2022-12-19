### 解题思路
‘11000’ => '1100' 最后字符串为0，直接移除该字符串
‘11001111’ => '11010000' 最后字符串为1, 用0替换掉连续为1的字符串，并且把终止连续为0的地方替换为1
### 代码

```javascript
var numSteps = function(s) {
  let ans = 0;
  // 判断字符串长度是否大于一
  while(s.length > 1){
    let len = s.length
    let end = s[len - 1]
    if (end === '1') {
      // 最后一个字符串如果等于1
      let newStr = ''
      let curLen = s.length
      // 遍历出连续值为1的数量，并且替换成0，然后在前面+1
      while (--curLen >= 0) {
         if (s[curLen] === '1') {
           newStr += '0'
         }else {
           break;
         }
       }
       s = s.substring(0, len - (newStr.length + 1)) + '1' + newStr
    } else {
      // 最后一个字符串如果等于0，就删除该字符串
      s = s.substring(0, len - 1)
    }
    ans++;
  }
return ans
};


```