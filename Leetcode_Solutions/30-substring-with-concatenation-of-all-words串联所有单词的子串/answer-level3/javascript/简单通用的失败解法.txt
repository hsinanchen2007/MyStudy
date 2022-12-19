遇到计算瓶颈[单词长度相同这个条件没利用起来]
18!=6402373705728000
```
 var findSubstring = function (s, words) {
        if (words.length == 0 || s.length == 0) {
            return []
        }
        var result = []
        recursion(words, 0, [], '', s, result)
        return result
    };
    var count=0
    function recursion(arr, x, flag, str, s, result) {
        if (x == arr.length) {
            var start = -1//重置
            while (start + 1 < s.length) {
                var index = s.indexOf(str, start + 1)//重复出现的
                if (index != -1) {
                    start = index
                } else {
                    return
                }
                result.push(start)
            }
        }
        for (let i = 0; i < arr.length; i++) {//str是数组解决不了重复
            const e = arr[i];
            if (!flag[i]) {
                flag[i] = 1
                recursion(arr, x + 1, flag, str + e, s, result)
                count++
                console.log(count)
                flag[i] = undefined
            }
        }
    }
```
