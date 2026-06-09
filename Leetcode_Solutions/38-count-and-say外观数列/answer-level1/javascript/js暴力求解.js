# JS解题思路
1. 观察总结数列结构如下
2. 1->{count:1,val:1}
3. 11->{ccount:2,val:1}
4. ...

由以上规律可以实现
```js
<!-- 给出上一行的数，可以求出当前行的数 -->
let get = (str) => {
    // 保存当前行数
    let target = '';
    // 用来标记个数
    let index = 1;
    // 遍历上一行数
    for (let i = 0; i < str.length; i++) {
        <!-- 判断重复的数有几个 -->
        if (str[i] == str[i + 1]) {
            index++
        } else {
            <!-- 添加当前数字个数和具体值到target -->
            target += index
            target += str[i]
            index = 1;
        }
    }
    <!-- 返回结果   -->
    return target
}
```

```js
<!-- n为要求的目标行数 -->
let countAndSay = (n) => {
    let res = '1'
    <!-- 求第几行执行几次就可以得到结果 -->
    for (let i = 0; i < n - 1; i++) {
        res = get(res)
    }
    return res;
}
```


