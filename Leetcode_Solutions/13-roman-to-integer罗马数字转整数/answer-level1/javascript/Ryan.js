## 搞一个Mapping, 按照限制条件筛选

- 时间复杂度: O(n), n是字符串的长度
- 空间复制度：O(1)

```
const mapping = {
        'I': 1,
        'IV': 4,
        'V': 5,
        'IX': 9,
        'X': 10,
        'XL': 40,
        'L': 50,
        'XC': 90,
        'C': 100,
        'CD': 400,
        'D': 500,
        'CM': 900,
        'M': 1000
    };

    let result = 0;

    for (let i = 0; i < s.length; i++) {

        if (i === s.length - 1) return result += mapping[s[i]];

        let comb = s[i] + s[i + 1];

        if (comb === 'IV' || comb === 'IX' || comb === 'XL' || comb === 'XC' || comb === 'CD' || comb === 'CM') {
            result += mapping[comb];
            i += 1; // 连续判断两个字符，所以i要手动再加1
            continue;
        }

        result += mapping[s[i]];
    }

    return result;
```
