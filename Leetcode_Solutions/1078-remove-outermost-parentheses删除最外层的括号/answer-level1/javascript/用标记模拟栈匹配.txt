## 1. 题目分析
题目要求提取**原语**,且原语都是配对的`()`.那么,很自然我们想到了栈来做辅助匹配.
考虑到题目说,给出的串都是合法的`()`.栈在这里似乎没有作用,但是通过pop,push我们
想到这两个操作可以等效看作`+1`和`-1`.如果,我们将要提取串靠做一个不停"+1,+1..-1...+1"
的序列.那么,不妨设cnt表示读取计数器,且规定它遇到`(`:`+1` and `)`:`-`则立马可得,
我们只需要获取cnt>0的串就好了.于是,有下面的解法
## 2. 解法说明
```
/**
 * @param {string} S
 * @return {string}
 */
var removeOuterParentheses = function (S) {

    let cnt = 0
    let c = ''
    let ret = ''
    for (const c of S) {

        if (c === '(') {
            if (cnt > 0) {
                ret += c
            }
            cnt += 1
        } else {
            cnt -= 1
            if (cnt > 0) {
                ret += c
            }

        }

    }
    return ret
}
```
