
![ac.png](https://pic.leetcode-cn.com/eaf62e52b9632d8b8da42469ef1a5eb20daf86fc68b36e661d74dd683a8d9e34-ac.png)

### 解题思路
发现JS写很容易超100%啊，看来大部分人都不用JS写....
贪心算法不能保证结果正确，就暴力BFS搜索+优化。
爆栈超时都遇到了，我的优化策略如下

1. 总步骤分两部分：转动的次数+按按钮的次数，可以发现按按钮的次数就等于key的长度。这样我们就只需要计算转动的次数。
2. 然后就是key相邻相同元素可以去重，比如 abbbc，和abc等价，因为在b时不用转动
3. 然后是BFS数组的优化，如果不优化，最多是要达到2^100这种量级的，优化有2个策略，对于每一轮，记录一个当前轮的最低步数minStep，如果有其他节点的步数大于minStep + ring.length，这样的节点一定不是答案，过滤掉。第二点，如果存在停留位置一样，步数也一样的节点，应该去重


### 代码

```javascript
/**
 * @param {string} ring
 * @param {string} key
 * @return {number}
 */
var findRotateSteps = function(ring, key) {
    
    let q = [], ans = Infinity
    let len = key.length
    key = Array.prototype.slice.call(key).reduce((a,b) => {
        a.length == 0 ? a.push(b) : ''
        a[a.length - 1] == b ? '' : a.push(b)
        return a
    }, []).join('')
    if(key.length == 1 && key[0] == ring[0]) return len
    
    q.push({s: 0, l: ring[0]==key[0] ? 1 : 0, step: 0})
    while(q.length) {
        let p = []; let minStep = Infinity
        for(let i = 0 ; i < q.length; i++) {
            let e = q[i]
            let dis = getDis(ring, e.s, key[e.l], 1) // 向左找
            let pos = (e.s - dis + ring.length) % ring.length
            let posL = e.l + 1
            if(posL == key.length) {
                ans =  Math.min(e.step + dis, ans)
            }
            minStep = Math.min(minStep, e.step + dis)
            p.push({s: pos, l: posL, step: e.step + dis })
            
            dis = getDis(ring, e.s, key[e.l], 0) // 向右找
            pos = (e.s + dis + ring.length) % ring.length
            posL = e.l +1 
            if(posL == key.length) {
                ans =  Math.min(e.step + dis, ans)
            }
            minStep = Math.min(minStep, e.step + dis)
            p.push({s: pos, l: posL, step: e.step + dis })
            
        }
        if(ans != Infinity) break
        // 过滤+去重
        let o = {}
        q = p.filter(v => v.step < minStep + ring.length).reduce((a,b) => {
            a.length == 0 ? a.push(b) : ''
            o[`${b.s}_${b.step}`] ? '' : a.push(b) 
            o[`${b.s}_${b.step}`] = 1
            return a
        }, [])
    }
    return ans + len
};

// 从str的pos处出发，向左(或者右)查找，找到str[pos] == char，返回查找的步数
function getDis(str, pos, char, left) {
    let cnt = 0
    while(1) {
        pos = left ? pos - 1 : pos + 1
        pos = (pos + str.length) % str.length
        cnt++
        if(str[pos] == char) return cnt
    }
}
```