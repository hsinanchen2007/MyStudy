思路是用一个数组当做栈，
1.向右遍历字符，当前字符串与上一字符串对比调到到2，遍历完字符串跳到4
2.若当前字符与前一个字符不同对栈顶的字符查重，以k个为步长去重
3.当前字符压进栈，回到1，
4.对栈顶元素查重，此时数组里面的元素就是结果，转成字符串即可
因为用的是数组所以查重比较容易，这么做使用的空间也就是一个长度为n的数组，但是因为查重的次数比较多，速度上算不上很快，空间可以超越100%的人。

var removeDuplicates = function (s, k) {
  if (k < 2) return s
  let arr = [s[0]]
  for (let i = 1; i < s.length; i++) {
    if (s[i] !== s[i - 1]) {
      deDuplication()
    }
    arr.push(s[i])
  }
  deDuplication()

  function deDuplication () {
    if (arr.length < k) return
    let count = k
    while (count > 1) {
      if (arr[arr.length - count] === arr[arr.length - count + 1]) {
        count--
      } else {
        return
      }
    }
    arr.length = arr.length - k
    deDuplication()
  }

  return arr.join('')
}