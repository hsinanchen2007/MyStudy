### 解题思路：

既然是求给定日期是一年中的第几天，用内置库将给定日期与当年的第一天做时间差除以一天的时长便是第几天了。

### 代码:
### 
```javascript []
var dayOfYear = function(date) {
    return (Date.parse(date) - Date.parse(date.substring(0, 4) + '-01-01')) / 86400000 + 1;
};
```

