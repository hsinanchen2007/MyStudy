### 思路一 ：滑动窗口（双指针）
题目中要求答案必须是 **子串** 的长度，意味着子串内的字符在原字符串中一定是连续的。因此我们可以将答案看作原字符串的一个滑动窗口，并维护窗口内不能有重复字符，同时更新窗口的最大值。


![TIM截图20200224210256.png](https://pic.leetcode-cn.com/ce96f9b99cba13a8c9f8b9c28d56b2e055fcc4186d9f36475674a673f9798fdc-TIM%E6%88%AA%E5%9B%BE20200224210256.png)

#### 算法
1. 初始化头尾指针 `head`，`tail`；
2. `tail` 指针右移，判断 `tail` 指向的元素是否在 `[head:tail]` 的窗口内；
    - 如果窗口中没有该元素，则将该元素加入窗口，同时更新窗口长度最大值，`tail` 指针继续右移；
    - 如果窗口中存在该元素，则将 `head` 指针右移，直到窗口中不包含该元素。
3. 返回窗口长度的最大值。

<![幻灯片1.JPG](https://pic.leetcode-cn.com/96ce866f5a5eba4d70c816ed38f9ab9a62fa65ebc345a335413fe9e7fd2680a7-%E5%B9%BB%E7%81%AF%E7%89%871.JPG),![幻灯片2.JPG](https://pic.leetcode-cn.com/37bbe74f96997ba9699b34bd20f0286269deba547f68e477d357e18e2939cf94-%E5%B9%BB%E7%81%AF%E7%89%872.JPG),![幻灯片3.JPG](https://pic.leetcode-cn.com/f90e166d312c905c78ff4b587ae35246c0aafd60cd80494526ecccfa483d117b-%E5%B9%BB%E7%81%AF%E7%89%873.JPG),![幻灯片4.JPG](https://pic.leetcode-cn.com/48125d25d150fc56fbb6cc294c099029bcc25e173ac7655672fb45d859f1bf16-%E5%B9%BB%E7%81%AF%E7%89%874.JPG),![幻灯片5.JPG](https://pic.leetcode-cn.com/0bcaec3805d3c00925242dbe0e25193c8fe6f52941358ee2687ef8c1b2a2f659-%E5%B9%BB%E7%81%AF%E7%89%875.JPG),![幻灯片6.JPG](https://pic.leetcode-cn.com/4ae9c130fc1298870a6551cb807d485aa2e738d3c790576e9993a921dced09af-%E5%B9%BB%E7%81%AF%E7%89%876.JPG),![幻灯片7.JPG](https://pic.leetcode-cn.com/14afc679fccdc2a49dd5e3df1a44539ff00c9134ba51b424b758f5c6149a4f32-%E5%B9%BB%E7%81%AF%E7%89%877.JPG),![幻灯片8.JPG](https://pic.leetcode-cn.com/8e57be8a1cc4887d5d6795f395d9638b2acc2d3d1a7003a1d469878adf85b9cf-%E5%B9%BB%E7%81%AF%E7%89%878.JPG),![幻灯片9.JPG](https://pic.leetcode-cn.com/77391c610acf1fa1572352e11b714b72c4222518e73998a4e165cdd638f9ef49-%E5%B9%BB%E7%81%AF%E7%89%879.JPG),![幻灯片10.JPG](https://pic.leetcode-cn.com/c22bb33cb62e21d39db03cc3159b8e286cc2a10406e7d15630475ef9386b771b-%E5%B9%BB%E7%81%AF%E7%89%8710.JPG),![幻灯片11.JPG](https://pic.leetcode-cn.com/2c09d27980af6a5c3caf9330f5413ae44759e8d22f62b11fb293e1813f1cc40f-%E5%B9%BB%E7%81%AF%E7%89%8711.JPG),![幻灯片12.JPG](https://pic.leetcode-cn.com/17232d3f08536c90285d00e44a93ede233cb37cb661b298a4b8524175eeb029f-%E5%B9%BB%E7%81%AF%E7%89%8712.JPG),![幻灯片13.JPG](https://pic.leetcode-cn.com/2a3ad15388cad0e399d55a159456d8f367bb124a8a95d6ccb9f6fd42c6742810-%E5%B9%BB%E7%81%AF%E7%89%8713.JPG),![幻灯片14.JPG](https://pic.leetcode-cn.com/d5222c1ad88f087c3edcf1ba858a4859c1c3a2753ebf7f2c256c50ff272eace2-%E5%B9%BB%E7%81%AF%E7%89%8714.JPG),![幻灯片15.JPG](https://pic.leetcode-cn.com/2d2bef2c108c64590e497eb050c11d283f0e5a27eb3187b31239f43923866fbf-%E5%B9%BB%E7%81%AF%E7%89%8715.JPG)>

#### 代码
```python []
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        head = 0
        tail = 0
        if len(s) < 2: return len(s) # 边界条件
        res = 1
        
        while tail < len(s) - 1:
            tail += 1
            if s[tail] not in s[head: tail]:
                res = max(tail - head + 1, res)
            else:
                while s[tail] in s[head: tail]:
                    head += 1
        return res
```


#### 复杂度分析
- 时间复杂度：$\mathcal{O}(n^2)$。
- 空间复杂度：$\mathcal{O}(1)$，使用了 `head`，`tail`，`res`。
### 思路二：优化的滑动窗口（哈希表）
我们可以使用哈希表记录每个字符的下一个索引，然后尽量向右移动尾指针来拓展窗口，并更新窗口的最大长度。如果尾指针指向的元素重复，则将头指针直接移动到窗口中重复元素的右侧。
#### 算法
- `tail` 指针向末尾方向移动；
- 如果尾指针指向的元素存在于哈希表中：
    - `head` 指针跳跃到重复字符的下一位；
- 更新哈希表和窗口长度。


<![幻灯片1.JPG](https://pic.leetcode-cn.com/3c28ac4876549614bb54bf79ea744447a71849366e7e6f63d9dce602af56edf0-%E5%B9%BB%E7%81%AF%E7%89%871.JPG),![幻灯片2.JPG](https://pic.leetcode-cn.com/41cbd432576d99cdfb6a2e4d964d6213cd7a77b0a44a0d433193b62b04aea734-%E5%B9%BB%E7%81%AF%E7%89%872.JPG),![幻灯片3.JPG](https://pic.leetcode-cn.com/7d998463ee69481ff04b6aeff13d99479bc6cb3c20a90e13d943b4fd23e2d0fa-%E5%B9%BB%E7%81%AF%E7%89%873.JPG),![幻灯片4.JPG](https://pic.leetcode-cn.com/7463e839f6ab2c3e9757266fc11fd75ffb879e93f2b34c81477337f74e93daad-%E5%B9%BB%E7%81%AF%E7%89%874.JPG),![幻灯片5.JPG](https://pic.leetcode-cn.com/3153e58826d5aab4a1b1c15b7739ca095166e26bb7d44b92b045cb9c3554a8b9-%E5%B9%BB%E7%81%AF%E7%89%875.JPG),![幻灯片6.JPG](https://pic.leetcode-cn.com/50736b6620a4c59734b3bd2b4e1a9d67d8c121e4551dde18fd6c89413a961ec2-%E5%B9%BB%E7%81%AF%E7%89%876.JPG),![幻灯片7.JPG](https://pic.leetcode-cn.com/d550d3fb36f5fdda62e37292a54a3e88e7b2c1a37d2d6db94e57a4aff7e00e75-%E5%B9%BB%E7%81%AF%E7%89%877.JPG),![幻灯片8.JPG](https://pic.leetcode-cn.com/96f71fea0f03e51854d2b9fed05d6d2802545014f0c030c36157369001c9067e-%E5%B9%BB%E7%81%AF%E7%89%878.JPG),![幻灯片9.JPG](https://pic.leetcode-cn.com/f0f4417151ed25caf3118d509600c89d2c1158714e77f8fd141677c7c3179bdf-%E5%B9%BB%E7%81%AF%E7%89%879.JPG),![幻灯片10.JPG](https://pic.leetcode-cn.com/4aeba2dc318b5b6c4080cb391db8358327d9a2ec612656f0f907e1960ff08280-%E5%B9%BB%E7%81%AF%E7%89%8710.JPG),![幻灯片11.JPG](https://pic.leetcode-cn.com/6ebcc4d987a32e53d96f42e6354ea7737959f0fa9aeb9fd000caa1067a62874c-%E5%B9%BB%E7%81%AF%E7%89%8711.JPG),![幻灯片12.JPG](https://pic.leetcode-cn.com/1320ad032739c87997c9bb168a4b71de59d6ebbf8abe0cc2238872f336f1168b-%E5%B9%BB%E7%81%AF%E7%89%8712.JPG),![幻灯片13.JPG](https://pic.leetcode-cn.com/5b368f71c947a92817decf1628713df208de4c4268559664448a371fed2e73ec-%E5%B9%BB%E7%81%AF%E7%89%8713.JPG),![幻灯片14.JPG](https://pic.leetcode-cn.com/ff40281fe8d6a033dcbf9b4c372e0202187aa1d4ce39e215749a5e0b54f3578c-%E5%B9%BB%E7%81%AF%E7%89%8714.JPG)>

#### 代码

感谢 [@huwt](/u/huwt/) 提供的 c++ 代码！
```python []
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        hashmap = {}
        head, res = 0, 0
        for tail in range(n):
            if s[tail] in hashmap:
                head = max(hashmap[s[tail]], head)
            hashmap[s[tail]] = tail + 1
            res = max(res, tail - head + 1)
        return res
```
```C++ []
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int ret = 0, l = 0, r = 0;
        while (r < s.size()) {
            if (m.find(s[r]) != m.end()) {
                l = max(l, m[s[r]] + 1);
            }
            m[s[r++]] = r;
            ret = max(r - l, ret);
        }
        return ret;
    }
};
```

#### 复杂度分析
- 时间复杂度：$\mathcal{O}(n)$，遍历了一遍 `s`，哈希表中查找的时间复杂度为 $\mathcal{O}(1)$。
- 空间复杂度：$\mathcal{O}(n)$，使用了哈希表。

欢迎提供c++代码
如有问题，欢迎讨论~