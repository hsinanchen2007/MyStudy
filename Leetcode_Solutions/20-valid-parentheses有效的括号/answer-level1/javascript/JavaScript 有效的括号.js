解一：
> 找到最内层的括号对，消去，重复此过程，若存在无法消去的字符则说明字符串无效。

```js
var isValid = function (s) {
    while (s.length) {
        var temp = s;
        s = s.replace('()', '');
        s = s.replace('[]', '');
        s = s.replace('{}', '');
        if (s == temp) return false
    }
    return true;
};
```

解二：
> 解一跑出来的速度和内存都不尽人意，我怀疑是`replace`的问题，就用同样的思想重写了一遍，没想到性能更差了。

```js
var isValid = function (s) {
    var map = {
        "(": ")",
        "[": "]",
        "{": "}"
    }
    while (s.length) {
        var left = s[0];
        if (!(left in map)) return false;
        var i = 1;
        while (s[i] != map[left] && i < s.length) left = s[i++];
        if (s[i] != map[left]) return false
        s = s.slice(0, i - 1) + s.slice(i + 1, s.length);
    }
    return true
};
```
![-w458](https://pic.leetcode-cn.com/1647623111889fd010761ab71ad0d46df9d7984033c0b2d64a179a6f350ea473-file_1565193958508)

解三：
> 换一种思路，可以边遍历边匹配。也就是遍历的时候遇到左括号存入数组，下次遇到的第一个右括号必须和数组中最后一个元素匹配，否则为无效字符串，匹配完成后从数组中删除此元素。若最终数组为空，表示括号已全部匹配完，字符串有效。

```js
var isValid = function (s) {
    var map = {
        "(": ")",
        "[": "]",
        "{": "}"
    }
    var leftArr = []
    for (var ch of s){
        if (ch in map) leftArr.push(ch); //为左括号时，顺序保存
        else { //为右括号时，与数组末位匹配
            if(ch != map[leftArr.pop()]) return false;
        }
    }
    return !leftArr.length //防止全部为左括号
};
```
![-w458](https://pic.leetcode-cn.com/c5e7ec3af737815b4199f0e14813205488cea6f9980518214f7a1d6603733d6a-file_1565193957834)
