![image.png](https://pic.leetcode-cn.com/0aee9364ccc61c961e6ea4b62e7958ba54f5a7c3cf4c1fd58326013812dbd375-image.png)


## 思路
输入：
  s = "barfoothefoobarman",
  words = ["foo","bar"]

第一步：遍历 words 的每一个元素，以 word 为起点切割 s，得到切割后的片段数组 allValues = ['foothe'、'foobar'、'barfoo'、'barman']。

第二步：遍历 allValues 的每一个元素，对每个元素进行切割（如：'foobar' 切割成 ['foo', 'bar']），接着对元素数组进行排序（如：['foo', 'bar'] 排序成 ['bar', 'foo']）,然后用 join 方法合成字符串，最后得到 valuesHadSorts = ['foothe'、'barfoo'、'barfoo'、'barman']。

第三步：对 words 进行排序，然后把排序后的 words 用 join 方法组合成字符串 w。

第四步：遍历 valuesHadSorts 的每一个元素，判断是否等于 w，相等则获取它们的 index。

```
var findSubstring = function(s, words) {
  const findIndexs = (str, p) => {
    var positions = []
    var pos = str.indexOf(p)

    while (pos > -1) {
      positions.push(pos)
      pos = str.indexOf(p, pos + 1)
    }
    return positions
  }

  const getValues = (s, word, sliceLength) => {
    let arr = []
    let indexs = findIndexs(s, word)

    indexs.forEach((index) => {
      if (index !== -1) {
        let leftStrEnd = index + word.length
        let leftStrStart = leftStrEnd - sliceLength
        if (leftStrStart >= 0 && leftStrEnd <= s.length) {
          let leftStr = s.substring(leftStrStart, leftStrEnd)
          arr.push(leftStr)
        }
      }
    })
    return arr
  }

  const getAllValues = (s, words) => {
    let values = []
    let wordSets = [...new Set(words)]
    for (let i = 0; i < wordSets.length; i++) {
      values = values.concat(getValues(s, wordSets[i], words.length * words[0].length))
    }
    return [...new Set(values)]
  }

  const isMatch = (value, words) => {
    let arr = []
    let v = value.slice()
    let len = words[0].length

    while (v) {
      arr.push(v.substring(0, len))
      v = v.substring(len)
    }
    return arr.sort().join('') === words.sort().join('')
  }

  if (!s || words.length === 0 || s.length < words.length * words[0].length) return []

  let arr = []
  const values = getAllValues(s, words)

  values.forEach((item) => {
    if (isMatch(item, words)) {
      arr = arr.concat(findIndexs(s, item))
    }
  })
  return arr
};
```