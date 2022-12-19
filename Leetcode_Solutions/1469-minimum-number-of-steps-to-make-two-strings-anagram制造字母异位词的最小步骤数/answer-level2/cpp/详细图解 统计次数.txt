### 解题思路
首先，我们发现字母异位词 `s` 和 `t` 中，每个字母出现的次数相同，位置可能相同也可能不同，比如 `anagram` 和 `mangaar`，或者 `xxyyzz` 和 `xxyyzz`。因此我们在求解的时候，无需考虑位置，只需考虑两个字符串中字母出现的位置。

因此，使用数组记录每个字母出现的次数:

$字母i出现的次数=s中字母i出现的次数-t中字母i出现的次数$

出现次数有正有负，只需将正值加起来即可。

<![幻灯片1.JPG](https://pic.leetcode-cn.com/29cf45bf740037561df2179b6ec6df56a0b1aa52c51e0252774222f546030bfc-%E5%B9%BB%E7%81%AF%E7%89%871.JPG),![幻灯片2.JPG](https://pic.leetcode-cn.com/fa8720429db9ed5c233e307dc49fb730489c45c7aae77feec8f1899b6734bf25-%E5%B9%BB%E7%81%AF%E7%89%872.JPG),![幻灯片3.JPG](https://pic.leetcode-cn.com/62cb69982cf37fc32e834feb69dbda7ec4217ca7b41ba13cd25bae278719e095-%E5%B9%BB%E7%81%AF%E7%89%873.JPG),![幻灯片4.JPG](https://pic.leetcode-cn.com/4db0bb39ba64ab48dcdaa55203d8438fb9476e8566020fe7ba60b3f60f30bd70-%E5%B9%BB%E7%81%AF%E7%89%874.JPG),![幻灯片5.JPG](https://pic.leetcode-cn.com/e6c8f1ae3da134b59638bcb09a5f9567b37e21453bb098174b07152c035efc99-%E5%B9%BB%E7%81%AF%E7%89%875.JPG),![幻灯片6.JPG](https://pic.leetcode-cn.com/fa848594fbce43b486b19bc9dca7a81cca354a2f40b51910c7cfc8b7e5af54f5-%E5%B9%BB%E7%81%AF%E7%89%876.JPG),![幻灯片7.JPG](https://pic.leetcode-cn.com/922609eea9d88d0be5f4c60f28f36240214321a984cbae5f4635c63a5506683b-%E5%B9%BB%E7%81%AF%E7%89%877.JPG),![幻灯片8.JPG](https://pic.leetcode-cn.com/733ab9218e061c9ec7385b12be7e3fd804ded96133abf4a87c08756da54b5239-%E5%B9%BB%E7%81%AF%E7%89%878.JPG),![幻灯片9.JPG](https://pic.leetcode-cn.com/599c282145d40242cbafada5bb475e2b167e6853e478f001885ce70195a4bd37-%E5%B9%BB%E7%81%AF%E7%89%879.JPG),![幻灯片10.JPG](https://pic.leetcode-cn.com/2e74de690f18f098fbdc6879358a5f83901214012dfd2479571a05eb771e4860-%E5%B9%BB%E7%81%AF%E7%89%8710.JPG)>


### 代码

```python []
class Solution:
    def minSteps(self, s: str, t: str) -> int:
        cnt = [0] * 26
        for i in range(len(s)):
            cnt[ord(s[i]) - ord('a')] += 1
            cnt[ord(t[i]) - ord('a')] -= 1
        res = 0
        for i in cnt:
            if i > 0:
                res += i
        return res
```

```C++ []
class Solution {
public:
    int minSteps(string s, string t) {
        int res = 0;
        vector<int> tmp(26,0);

        for(int i = 0; i< s.size();i++){
            tmp[s[i] - 'a']++;
            tmp[t[i] - 'a']--;

        }
        for (int i = 0;i < 26;++i){
            if(tmp[i] > 0) res += abs(tmp[i]);
        }
        return res;
    }
};
```

### 复杂度分析
- 时间复杂度：$O(N)$。
- 空间复杂度：$O(N)$。