### 解题思路
因为只能修改一次，所以考虑三种情况：
#### 情况一： 两个字符串长度差大于1
一定是false
#### 情况二： 两个字符串长度相等
用一次迭代逐个比较字符，如果发现第二个不同的字符返回false
#### 情况三： 两个字符串长度相差1
先找出短字符串shortStr，和长字符串longStr
迭代短的字符串shortStr，如果i位置的字符shortStr[i]和longStr[i],longStr[i+1]都不相等返回false,说明不能通过插入一个字符让两个字符串相等。

### 代码

```javascript
/**
 * @param {string} first
 * @param {string} second
 * @return {boolean}
 */
var oneEditAway = function (first, second) {
    const lenDiff = Math.abs(first.length - second.length);
    if (lenDiff > 1) {
        return false;
    }
    else if (lenDiff === 1) {
        if (first.length > second.length) {
            [first, second] = [second, first];
        }
        for (let i = 0; i < first.length; i++) {
            if (first[i] !== second[i] && first[i] !== second[i + 1]) {
                return false;
            }
        }
    }
    else if (lenDiff === 0) {
        let diff = 0;
        for (let i = 0; i < first.length; i++) {
            if (first[i] !== second[i]) {
                diff++;
            }

            if (diff > 1) {
                return false;
            }
        }
    }

    return true;
};
```