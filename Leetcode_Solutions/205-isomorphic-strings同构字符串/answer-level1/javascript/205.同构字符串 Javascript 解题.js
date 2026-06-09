
![javascript.jpg](https://pic.leetcode-cn.com/ff1e039df78b6c147338dcd29f1630d0e1b530ba97b52592f6692f126b71e5fe-javascript.jpg)  

<br />

- 这道题我的思路是用 map 判断值和索引  

```javascript []
const isIsomorphic = (s, t) => {
  if (s === t || s === '') return true
  let mapS = new Map(), mapT = new Map()
  for (let i = 0; i < s.length; i++) {
    if (mapS.has(s[i]) || mapT.has(t[i])) {
      if (mapS.get(s[i]) !== mapT.get(t[i])) return false
    }
    mapS.set(s[i], i)
    mapT.set(t[i], i)
  }
  return true
}
```

<br />

- 然而我提交后看到了大佬更加简洁的思路, 利用`indexOf()`第二个参数去寻找后面相同字符的`骚操作`

```javascript []
const isIsomorphic = (s, t) => {
  if (s === t || s === '') return true
  for (let i = 0; i < s.length - 1; i++) {
    if (s.indexOf(s[i], i+1) !== t.indexOf(t[i], i+1)) return false
  }
  return true
}
```

> 思路题解:

```
第1个栗子: 输入`egg`和`add`
    第一步:
        判断`gg`是否包含`e`, 不包含返回 -1
        判断`dd`是否包含`a`, 不包含返回 -1
        -1 === -1
    第二步:
        判断`g`是否包含`g`, 包含返回 1
        判断`d`是否包含`d`, 包含返回 1
        0 === 0
    循环执行完毕, 然后`return true`
```
```
第2个栗子: 输入`foo`和`bar`
    第一步:
        判断`oo`是否包含`f`, 不包含返回 -1
        判断`ar`是否包含`b`, 不包含返回 -1
        -1 === -1
    第二步:
        判断`o`是否包含`o`, 包含返回 1
        判断`r`是否包含`a`, 不包含返回 -1
        1 !== -1
        结束函数并 return false
```
```
第3个栗子: 输入`paper`和`title`
    第一步:
        判断`aper`是否包含`p`, 包含返回 2
        判断`itle`是否包含`t`, 包含返回 2
        2 === 2
    第二步:
        判断`per`是否包含`a`, 不包含返回 -1
        判断`tle`是否包含`i`, 不包含返回 -1
        -1 === -1
    第三步:
        判断`er`是否包含`p`, 不包含返回 -1
        判断`le`是否包含`t`, 不包含返回 -1
        -1 === -1
    第四步:
        判断`r`是否包含`e`, 不包含返回 -1
        判断`e`是否包含`l`, 不包含返回 -1
        -1 === -1
    循环执行完毕, 然后`return true`
```