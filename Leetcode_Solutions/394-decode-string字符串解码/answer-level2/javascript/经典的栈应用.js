### 解题思路
![image.png](https://pic.leetcode-cn.com/48ce97cf89eee4cee3d78cfa7b71cf31e0f399f96c7b9edc2745f83d6024e9fb-image.png)

出栈把字符串解码，再将解码后的字符串推回栈，最后连接一下即可。

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var decodeString = function(s) {
    const NUM = "0123456789";
    const ALP = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    let st = [],
        i = 0,
        str = "";

    while (i < s.length) {
        const it = s[i];
        if (NUM.includes(it) || ALP.includes(it) || it === "[") {
            st.push(it);
        } else if (it === "]") {
            str = "";
            while (st[st.length - 1] != "[") {
                str = st.pop() + str;
            }
            st.pop();
            let qtyStr = "";
            while (NUM.includes(st[st.length - 1])) {
                qtyStr = st.pop() + qtyStr;
            }
            let qty = parseInt(qtyStr, 10);
            str = str.repeat(qty);
            st.push(str);
        }
        i++;
    }
    str = "";
    st.forEach(val => {
        str += val;
    })
    return str;
};
```