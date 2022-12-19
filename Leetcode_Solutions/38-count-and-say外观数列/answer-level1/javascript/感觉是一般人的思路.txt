找到相同的数字，数的个数加这个数的字符串作为下一个数

```
function countAndSay(n) {
    var str = '1';
    var count = 0;
    var j = 0;
    var z = 0;
    // 遍历n-1次，因为第一位不用算为'1'
    for (var i = 0; i < n - 1; i++) {
        var aux = [];
        j = 0;
        while (j < str.length) {
            count = 1;
            // 找有多少个和str[j]一样的
            z = j + 1;
            while (str[z] === str[j] && z < str.length) {
                // 索引移动
                z++;
                // 计数增加
                count++;
            }
            // 把字符个数推进去
            aux.push(count + '');
            // 把字符推进去
            aux.push(str[j]);
            // 更新索引
            j = z - 1;
            // 移动索引
            j++;
        }
        // 全部处理完，join一下就是下一个数字
        str = aux.join('');
    }
    return str;
}
```
