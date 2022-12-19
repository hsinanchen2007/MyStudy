关键在于理解题目中【单词】的定义：
前后被空格包裹的字符串（除了第一个和最后一个），即为单词

**解法一**
内置api
```javascript []
var countSegments = function(s) {
    return s.split(" ").filter(Boolean).length;
};
```

**解法二**
正则位置匹配
```javascript []
var countSegments = function(s) {
    return (s.match(/(?<=[\s]?)[^\s]+(?=[\s]?)/g) || []).length
};
```