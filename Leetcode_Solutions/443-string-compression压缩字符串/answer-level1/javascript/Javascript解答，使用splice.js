### 解题思路
快慢指针，遇到不一样的就splice原数组，但是因为spilce改变了原数组的长度，所以快指针位置要做相应调整。慢指针在splice过后总是等于重置到快指针处。while loop的最后一次快指针要等与chars的长度，为了可以splice最后一次。

### 代码

```javascript
/**
 * @param {character[]} chars
 * @return {number}
 */
var compress = function (chars) {
    let slow = 0
    let fast = 0
    let curCount = 0
    while (fast <= chars.length) {
        if (chars[slow] == chars[fast]) {
            curCount += 1
            fast++
        } else {
            if (curCount > 1) {
                const strArr = String(curCount).split("")
                chars.splice(slow, curCount, chars[slow], ...strArr)
                console.log(chars)
                fast = fast - curCount + 1 + strArr.length
            }
            slow = fast
            curCount = 0
        }
    }
};
```