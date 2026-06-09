# 有效的字母异位词
[有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/)
```
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
示例 1:
输入: s = "anagram", t = "nagaram"
输出: true
示例 2:
输入: s = "rat", t = "car"
输出: false
```

## 方法一
### 思路
```
排序法，时间复杂度O(nlogn)

1.分别将两个字符串排序
2.比较两个排序后的字符串

```

### 实现
```
javascript中有Array.sort()，不传参数默认按首字母排序
我们只需要将字符串按照每个字符一个元素的方式转换成数组，可以使用拓展运算符`...`
将数组排完序后，将数组转回字符串，这里用到Array.join("")
为什么不直接比较两个数组？因为JavaScript中两个完全一样的数组直接用`==`比较也会返回false，因为虽然内容一样，但是存储在两个不同内存空间的数组
```
```javascript
var isVaildAnagram = function(s, t) {
    return [...s].sort().join("") === [...t].sort().join("")
}
```

## 方法二
### 思路
```
哈希法，时间复杂度O(n)
1.将字符串转成 字母：次数 形式的map，例如{"a" : 3, "n" : 1,...}
2.比较两个map是否相等

```
### 实现
```
javascript中，使用map.set(key, value)、 map.has(key) 、map.get(key) 转成哈希表示
比较两个map相等不能直接用`==`比较，首先看看两个map.size是否相同，
如果同为0直接返回true，然后遍历map1中的每个键名，
拿map1的中键看看map2中有没有相同的，若有并且值要相同则遍历完之后，全相同才是相同

我这里使用了两个辅助函数：一个是将字符串按照我们想要的方式转成map，另一个是比较两个map是否键值相同。
也就是下面的getMap()和compareTwoMap()
```

```javascript
var getMap(str) {
    if(typeof str !== "string") return false
    let map = new Map()
    for(let i of str){
        if(map.has(i)){
            map.set(i, map.get(i) + 1)
        }else{
            map.set(i, 1)
        }
    }
    return map
}

var compareTwoMap(map1, map2) {
    if(!(map1 instanceof Map) || !(map2 instanceof Map)) return false
        if(map1.size !== map2.size) return false
            //如果两个都是空map，直接return true，不然到了下一轮i会为undefined
        if(map1.size === map2.size && map1.size == 0) return true
        for(let i of map1.keys()) {
            if(!(map2.has(i))) return false
            if(map1.get(i) !== map2.get(i)) return false
        }
        return true

}

var isVaildAnagram = function (s, t) {
    return compareTwoMap(getMap(s), getMap(t))
}

```


