# 思路
1. 因为ip固定是4个数字，每个数字的长度范围是1-3。所以取第1个数字的时候，计算后面长度，可以缩小范围。
2. 处理最后1个数字时，要直接取到字符串最后一位。
3. ip中每个数字的范围是0-255，注意使用Number转换时“01”也是可以转换成1的，可以考虑再转回来与字符串对比排除。
4. 取得这一位的合法数字后，递归调用取下一位。
```
        var restoreIpAddresses = function(s) {
            return restoreIpAddresse(s, 3, 0);
        }

```
```
function restoreIpAddresse(s, count, begin) {
            let len = s.length;
            let array = [];
            for (let i = begin; i < begin + 3; i++) {
                if (count == 0 && i != len - 1) continue;
                if ((len - i - 1) > (count * 3)) continue;
                if ((len - i - 1) < (count * 1)) continue;
                let sub = s.substr(begin, i - begin + 1);
                let ip = Number(sub);
                if (ip < 0 || ip > 255) {
                    continue;
                }
                if (ip.toString() != sub) {
                    break;
                }
                if (count === 0) {
                    array.push(sub);
                }
                let result = restoreIpAddresse(s, count - 1, i + 1);
                result.forEach(item => {
                    return array.push(sub + "." + item);
                })
            }
            return array;
        }
```

