### 解题思路
從字串末尾逐字向前檢查
情況1: 該字是空串且累積長度為0
  有可能該字末尾為空串
  此時不計入長度累積結果 但往前繼續檢查
情況2: 該字是空串或空值(且已有累積長度)
  表示單詞結束
  此時直接返回累積長度結果
情況3: (該字非空串也非空值)
  計入長度累積結果 並且往前繼續檢查
### 代码

```javascript
/**
 * @param {string} s
 * @param {number} i 倒數第幾個字
 * @param {number}} res 累積長度結果
 * @return {number}
 */
var lengthOfLastWord = function(s, i = 1, res = 0) {
  const char = s[s.length - i]
  if(char == ' ' && res == 0) i += 1
  else if(char == ' ' || char == null) return res
  else res += 1, i += 1
  return lengthOfLastWord(s, i, res)
};
```