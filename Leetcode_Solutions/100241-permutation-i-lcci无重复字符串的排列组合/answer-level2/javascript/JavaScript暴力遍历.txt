```js
var permutation = function(S) {
  let len = S.length
  let result = []
  if (len === 0) return result
  //结果存放
  result.push(S[0])
  for (let i = 1; i < len; i++) {
    //数组长度
    let length = result.length

    for (let j = 0; j < length; j++) {
      //数组中的字符串
      let str = result[j]
      let l = str.length
      //遍历字符串
      for (let k = 0; k < l; k++) {
        //合并字符串
        const temp = str.substr(0, k) + S[i] + str.substr(k)

        result.push(temp)
      }

      result.push(str + S[i])
    }
    //过滤
    result = result.filter(item => item.length > i)
  }
  //输出
  return result
}
```
