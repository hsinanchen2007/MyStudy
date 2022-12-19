### 解题思路
模拟队列的操作即可，预先加入一个元素
后来的元素判断与队列头部是否相等，不相等则直接res += 1，并且头部出队列，新元素入队
如果后来的元素与头部相等，则判断该元素与队列尾部是否相等
1. 相等则直接入队
2. 不相等则计算一次res += 1，且重置队列

### 代码

```javascript
var countBinarySubstrings = function(s) {
    if (s.length < 2) return 0;
    // 模拟队列
    let queue = [], i = 1, res = 0;
    queue.push(s[0]);

    while (i < s.length) {
        // 如果队头元素与当前元素相等
        if (queue[0] == s[i]) {
            let last = queue[queue.length - 1];
            queue.push(s[i]);

            if (last != s[i]) {
                // 如果队列尾部元素与当前元素不等，则必须计算一次，且重置队列
                res++;

                let index = queue.indexOf(last);
                queue = queue.slice(index + 1);
            }   
        } else {
            // 如果与队列头不相等
            res++;
            queue.shift();
            queue.push(s[i]);
        }
        i++;
    }
    return res;
};
```