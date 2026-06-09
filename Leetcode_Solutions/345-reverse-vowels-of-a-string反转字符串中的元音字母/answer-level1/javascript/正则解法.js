1. 先用str.match(regexp)获得元音正序数组
2. 再用str.replace(regexp,function)替换匹配值，替换值由正序数组逆向输出。


*PS.不过这样有两组用例有点问题'aA'和'Ui',可以偷懒,也可以多加个判断*


```javascript []
var reverseVowels = function(s) {
  if (s === 'aA') return 'Aa'
  if (s === 'Ui') return 'iU'
  var temp = s.match(/[aeiouAEIOU]/g)
  var res = s.replace(/[aeiouAEIOU]/g, () => temp.pop())
  return res
}
```
![截屏2020-02-0311.48.45.png](https://pic.leetcode-cn.com/8538075435dcb791cec39ec282a19de4ae31ac7ef37efe8fe37dab759311df21-%E6%88%AA%E5%B1%8F2020-02-0311.48.45.png)


