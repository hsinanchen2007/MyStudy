#### 思路（递归）
1. 序列中的每一项都是对前一项的描述；
2. 所以第`n`项是对第`n-1`项的描述，以此类推，`n-1`是对`n-2，n-3...5...1`；
#### 代码
```
var countAndSay = function(n) {
    let map = {1: '1', 2: '11', 3: '21', 4: '1211', 5: '111221'};
    // 递归出口
    if (map[n]) {
        return map[n];
    }
    return fn(countAndSay(n - 1));
    
    // 核心方法，遍历字符串，找出每个字符的个数
    function fn(str) {
        let result = '';
        let count = 1;
        for (let i = 0; i < str.length; i++) {
            // 如果后面的数和前面一样，计数加一
            if (str[i+1] === str[i]) {
                count++;
            } else {
                // 保存数出的个数，例如：111-->count = 3；str[i] = 1-->31
                result += (count + str[i] + '')
                count = 1;
            }
        }
        return result;
    }
};
```
