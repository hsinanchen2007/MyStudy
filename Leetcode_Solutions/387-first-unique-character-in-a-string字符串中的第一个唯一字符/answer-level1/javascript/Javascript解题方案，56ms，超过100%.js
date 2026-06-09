![image.png](https://pic.leetcode-cn.com/9e2a71e63e12a84a432bdccf8899b310013c6f79e227cdd10b3c070f4f7d4b60-image.png)

```
const firstUniqChar = (w) => {
    if(w.length <= 1) return w.length - 1;
    if(w.length > 26) {
        const ps = 'abcdefghijklmnopqrstuvwxyz';
        let found = w.length;
        for (let i = 0; i < ps.length; ++i) {
            const left = w.indexOf(ps[i]);
            if (left === w.lastIndexOf(ps[i])) {
                if (found > left && left > -1) found = left;
            }
            const right = w.indexOf(ps[ps.length - 1 - i]);
            if (right === w.lastIndexOf(ps[ps.length - 1 - i])) {
                if (found > right && right > -1)
                    found = right;
            }
            if(found === 0) break;
            if (i >= ps.length / 2) {
                break;
            }
        }
        if(found === w.length) return -1;
        return found;
    } else {
        let i = 0;
        while(true) {
            if(w.indexOf(w[i], i + 1) === -1 && w.lastIndexOf(w[i], i - 1) === -1) {
                return i;
            } else if(i === 0) {
                if(w.indexOf(w[i], i + 1) === -1) return i;
            } else if(i === w.length - 1) {
                if(w.lastIndexOf(w[i], i - 1) === -1) return i;
                return -1;
            }
            ++i;
        }
    }
}
```
