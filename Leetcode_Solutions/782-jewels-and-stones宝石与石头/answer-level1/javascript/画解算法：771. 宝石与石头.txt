## 解题方案

### 思路

- 标签：字符串
- 首先对J进行遍历，将字符分别存到HashSet中，以便之后遍历S的时候查找
- 遍历S，并将每个字符与HashSet中的进行比对，如果存在，则结果ans++，遍历结束，返回ans
- 时间复杂度：O(m+n)，m为J的长度，n为S的长度

### 代码


```java []
class Solution {
    public int numJewelsInStones(String J, String S) {
        Set<Character> set = new HashSet<>();
        for(int i = 0; i < J.length(); i++) {
            set.add(J.charAt(i));
        }
        int ans = 0;
        for(int i = 0; i < S.length(); i++) {
            if(set.contains(S.charAt(i))){
                ans++;
            }
        }
        return ans;
    }
}
```
```javascript []
/**
 * @param {string} J
 * @param {string} S
 * @return {number}
 */
var numJewelsInStones = function(J, S) {
    const set = new Set();
    for(const s of J) {
        set.add(s);
    }
    let ans = 0;
    for(const s of S) {
        if(set.has(s)){
            ans++;
        }
    }
    return ans;
};
```

### 画解


<![frame_00001.png](https://pic.leetcode-cn.com/d01b91b678b3d79ec7471c09eeb74c7498bce07d8833e96c08cab54059ed863c-frame_00001.png),![frame_00002.png](https://pic.leetcode-cn.com/37d5cc0ea2b68d407478aa8c8633719e73b89ed028ec1b4fb0eee274eb120c4c-frame_00002.png),![frame_00003.png](https://pic.leetcode-cn.com/e883c974994f25d4890cd6d1c164c955ad5675866639cbd09f3df3590a16356f-frame_00003.png),![frame_00004.png](https://pic.leetcode-cn.com/7faee08ea3d8d0dd55bb1e25e22cf22b2b39a4494823194ab1f0e2a860743a77-frame_00004.png),![frame_00005.png](https://pic.leetcode-cn.com/b7fcca2f7236e6d605985b9c6147aad09207c470b66baafae8a50a03fef3471f-frame_00005.png)>


点击我的头像加关注，和我一起打卡天天算法