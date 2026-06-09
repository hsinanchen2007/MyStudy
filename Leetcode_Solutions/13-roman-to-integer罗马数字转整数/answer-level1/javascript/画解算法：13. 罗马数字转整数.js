### 思路

- 首先将所有的组合可能性列出并添加到哈希表中
- 然后对字符串进行遍历，由于组合只有两种，一种是 1 个字符，一种是 2 个字符，其中 2 个字符优先于 1 个字符
- 先判断两个字符的组合在哈希表中是否存在，存在则将值取出加到结果 ans 中，并向后移2个字符。不存在则将判断当前 1 个字符是否存在，存在则将值取出加到结果 ans 中，并向后移 1 个字符
- 遍历结束返回结果 ans


### 代码

```Java []
class Solution {
    public int romanToInt(String s) {
        Map<String, Integer> map = new HashMap<>();
        map.put("I", 1);
        map.put("IV", 4);
        map.put("V", 5);
        map.put("IX", 9);
        map.put("X", 10);
        map.put("XL", 40);
        map.put("L", 50);
        map.put("XC", 90);
        map.put("C", 100);
        map.put("CD", 400);
        map.put("D", 500);
        map.put("CM", 900);
        map.put("M", 1000);
        
        int ans = 0;
        for(int i = 0;i < s.length();) {
            if(i + 1 < s.length() && map.containsKey(s.substring(i, i+2))) {
                ans += map.get(s.substring(i, i+2));
                i += 2;
            } else {
                ans += map.get(s.substring(i, i+1));
                i ++;
            }
        }
        return ans;
    }
}
```
```javascript []
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    const map = {
        I : 1,
        IV: 4,
        V: 5,
        IX: 9,
        X: 10,
        XL: 40,
        L: 50,
        XC: 90,
        C: 100,
        CD: 400,
        D: 500,
        CM: 900,
        M: 1000
    };
    let ans = 0;
    for(let i = 0;i < s.length;) {
        if(i + 1 < s.length && map[s.substring(i, i+2)]) {
            ans += map[s.substring(i, i+2)];
            i += 2;
        } else {
            ans += map[s.substring(i, i+1)];
            i ++;
        }
    }
    return ans;
};
```

### 画解

<![frame_00001.png](https://pic.leetcode-cn.com/e3f26945d92e29ba0e6fa2b8f0c49523a1ab5c23430c395c9ff0ee4a68528bb2-frame_00001.png),![frame_00002.png](https://pic.leetcode-cn.com/686e489ea52cc03771444b41d96c8cb0ce8b0bf01c1cac1dac9574cbc8013896-frame_00002.png),![frame_00003.png](https://pic.leetcode-cn.com/f0b9f26dcdb46dc9c7f011a9f7779d36601ef7ecc5954d78154a5301c87c34aa-frame_00003.png),![frame_00004.png](https://pic.leetcode-cn.com/be5d7293d6f7e4d671d687fa4f868d0d82f3ca98c80246e03b2b2e67194de232-frame_00004.png),![frame_00005.png](https://pic.leetcode-cn.com/58472ed35af9bcaccf80cfd8780afdcbcf2afc4cfaaef3d044a74020ac3d900d-frame_00005.png)>
