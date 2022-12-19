### 解题思路
字串：指连续的字符串
该题是找出没有重复值出现的字串的长度，所以将没有重复的值按顺序放入到新数组temp中，当出现重复数字时，则表示以temp的第一个元素的字串出现了重复字符，重新以第二个元素为开头继续往下寻找。在删除第一个元素时，要注意的点s，是在for循环中，要将i的值恢复为查找到循环字符的下标，保证将这个值压入到temp数组中

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let res = 0, temp = []
    for (let i=0;i<s.length;i++) {
        if (temp.indexOf(s[i]) == -1) { //数组中无被遍历的值
            temp.push(s[i]) //将不重复的值去除
        } else {
            temp.shift() //因为有重复值出现，去除第一个元素
            i-- //控制i的值，将刚才重复的值重新压入数组
            continue    //不再进行res的赋值
        }
        res = Math.max(res, temp.length)    //Math.max(a, b)选出两个值中较大的那个值
    }
    return res
};
```