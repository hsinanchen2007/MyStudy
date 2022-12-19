## 定义字典
我们可以先定义一个存储26个字母的字典「Hash」，用来存储每个字母出现的次数。
```javascript
 let dictionary = new Array(26).fill(0);
```
## 遍历S1,完善字典
之后我们遍历s1中的字符，并向字典上添加记录
```javascript
// 遍历s1上的字符，在字典上进行记录
for(let i = 0; i < s1.length; i++) {
    let code = s1.charCodeAt(i) - 97;
    dictionary[code]++;
}
```
## 遍历S2,根据字典判断是否查找到子字符串
之后，我们在s2上定义两个索引，一个指向子字符串的开头，一个指向子字符串的末尾，我们一开始只移动末尾索引来增长子串
但是当我们遇到字典上某一个字母出现负值，意味着子串中出现了我们s1中没有的字符或者存在的字符数量超出，我们就向前移动头部索引来剪短子串，同时恢复字典上的值
在遍历途中，当找到了对应的子串时，一定是字典中没有小于0并且长度相同 === 字典中全部为0 === s1与子字符串中字符相同

完整代码

```javascript
function CheckInclusion (s1: string, s2: string) : boolean {
    if (typeof s1 !== 'string' || typeof s2 !== 'string' || s1.length === 0 || s2.length === 0) {
        return false;
    }
    // 创建一个字典
    let dictionary = new Array(26).fill(0);
    // 遍历s1上的字符，在字典上进行记录
    for(let i = 0; i < s1.length; i++) {
        let code = s1.charCodeAt(i) - 97;
        dictionary[code]++;
    }
    // 之后统计s2上的字符，每当出现后在字典上减少一个
    for(let start = 0, end = 0; end < s2.length; end++) {
        let code = s2.charCodeAt(end) - 97;
        dictionary[code]--;
        // 当出现了s1中不存在的字符或者数量超过s1中字符量，向前移动
        while (dictionary[code] < 0) {
            dictionary[s2.charCodeAt(start) - 97]++;
            start++;
        }
        // 如果此时出现全部符合同时长度与s1相同的子串，则查找成功
        if (end - start + 1 === s1.length) return true;
    }
    return false;
}
```

更多TypeScript - LeetCode题解，可在[数据结构与算法](https://reaperlee.cn/ds-al/)查看。
