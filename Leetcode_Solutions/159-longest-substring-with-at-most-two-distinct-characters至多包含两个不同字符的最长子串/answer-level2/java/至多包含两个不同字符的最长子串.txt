#### 方法 1：滑动窗口
**想法**

为了遍历一遍就得到答案，我们使用一个左指针和一个右指针表示滑动窗口的边界。

一开始，让两个指针都指向 0 ，当窗口包含的字符不超过 2 个不同的字符时，就不断将右指针往右边移动。如果在某一个位置有 3 个不同的字符，就开始移动左指针，直到窗口内包含不超过 2 个不同字符。

![image.png](https://pic.leetcode-cn.com/ec1b0faba8ddd06620284cd224892efecf46f48a6bdf24ff0bb1ab44e64bc701-image.png)

这就是基本的想法：沿着字符串移动滑动窗口，并保持窗口内只有不超过 2 个不同字符，同时每一步都更新最长子串的长度。

只有一个问题还没解决 - 如何移动左指针确保窗口内只有 2 种不同的字符？

我们使用一个 hashmap ，把字符串里的字符都当做键，在窗口中的最右边的字符位置作为值。每一个时刻，这个 hashmap 包括不超过 3 个元素。

![image.png](https://pic.leetcode-cn.com/b5c5c5da311f52bbfd0cba6d16260b4df4a290177b2ed95d2e5e9315e81ef87a-image.png)

比方说，通过这个 hashmap ，你可以知道窗口 "eeeeeeeet" 中字符 e 最右边的位置是 8 ，所以必须要至少将左指针移动到 8 + 1 = 9 的位置来将 e 从滑动窗口中移除。

我们的方法时间复杂度是否是最优的呢？答案是是的。我们只将字符串的 N 个字符遍历了一次，时间复杂度是 $\mathcal{O}(N)$ 。

**算法**

现在我们可以写出如下算法：

- 如果 `N` 的长度小于 `3` ，返回 `N` 。
- 将左右指针都初始化成字符串的左端点 `left = 0` 和 `right = 0` ，且初始化最大子字符串为 `max_len = 2`
- 当右指针小于 `N` 时：
    * 如果 hashmap 包含小于 `3` 个不同字符，那么将当前字符 `s[right]` 放到 hashmap 中并将右指针往右移动一次。
    * 如果 hashmap 包含 `3` 个不同字符，将最左边的字符从 哈希表中删去，并移动左指针，以便滑动窗口只包含 `2` 个不同的字符。
    * 更新 `max_len`

**算法实现**

<![image.png](https://pic.leetcode-cn.com/5932a02478486b3e31efa95ef7f1ab136664676fa720736a731ce96ee404c674-image.png),![image.png](https://pic.leetcode-cn.com/d337045e95bc83a9fd0fa03312f24fe277dbad302a934b5d6c448db6766472b9-image.png),![image.png](https://pic.leetcode-cn.com/fc74c6e36cbc6cdf0e6e19a83a89a62bd0698ffe13aa086b86eb7cf80d420ab0-image.png),![image.png](https://pic.leetcode-cn.com/6eca4e2e99af06fae16ade62261f02975d056ccb1814680ab1c3a94f00d45411-image.png),![image.png](https://pic.leetcode-cn.com/337ade89b1b43ccbcec634c4b535f22e48a1da5d36341e65a68388885ad5c0b7-image.png),![image.png](https://pic.leetcode-cn.com/96f6c8d52d3cfa9f72a250e94007d6401a8d4b0f142c51aa78560fdcd9717235-image.png),![image.png](https://pic.leetcode-cn.com/a2b5f2aaa423c26fdaf46976e93188c3d3fa956f9fe422a8c405eb5ee787d0b1-image.png),![image.png](https://pic.leetcode-cn.com/40c59431c37b6b609c9da4f184fa463bb48b086c24373a78f53cef6d4a31638b-image.png),![image.png](https://pic.leetcode-cn.com/27e9d45c27651bb2db18dac1e56a3c999f39b1fb53e94262a3e659b716447004-image.png), ![image.png](https://pic.leetcode-cn.com/4e30e64cf425d07154d6cd641bda2c340722f279af3fad70f48258a7038ed425-image.png),![image.png](https://pic.leetcode-cn.com/abca636bdb830ebae7df231b741fe702d0b5795df549a1daa58f2a50edb4d3f3-image.png),![image.png](https://pic.leetcode-cn.com/8bc1d340442551a5eaa7a1ca85b1091e437018ea1155766f46173d049eec3266-image.png),![image.png](https://pic.leetcode-cn.com/fa7d1cae379d3fc2ee0ee866c5cfa92c69f485bf1939bc8a57643fca0403ece4-image.png),![image.png](https://pic.leetcode-cn.com/d9f589b213e9296556cbe7c921fb57ed19703d805f6202d9d0c9f2c4b85cd96e-image.png),![image.png](https://pic.leetcode-cn.com/508190a7869408b5c60c5c7c73e2393942175d806f3c83cb5695abb2265ba7cc-image.png),![image.png](https://pic.leetcode-cn.com/0538f5bac747e127e4b098c0152d084918e5c5f522ae810bfcbc0979244b7dc0-image.png),![image.png](https://pic.leetcode-cn.com/7a0a59b527f9ea000e514a5f60bc9361d9a50b11e2b5e21996cccbb0150ae66a-image.png),![image.png](https://pic.leetcode-cn.com/6474091ca19683c3b905859b17607a07e306b1afba2de2ba3bccd1ba4e380f8c-image.png),![image.png](https://pic.leetcode-cn.com/7540755d0f53f83e679f1b87ed999824ad5dbd30ffbb1f6a1b5b16bbf9dca2bb-image.png),![image.png](https://pic.leetcode-cn.com/8b4c60bce6faae3b9392b570d8a80382cd49cb181b936edf45b6e22775d92662-image.png),![image.png](https://pic.leetcode-cn.com/5ae2dbd1168e5b926e8e7e9e5d0b6613a01d35a0f18b9cfb6657fcc431e8e35a-image.png),![image.png](https://pic.leetcode-cn.com/cb379142214b9f866e4402056e6ca5bd98f0d76f433e46639ad1c113617be83e-image.png),![image.png](https://pic.leetcode-cn.com/6d7518e60fc03804f36a6ae7556a693d316074dbcff8b10d4901a18adb1ef128-image.png),![image.png](https://pic.leetcode-cn.com/87575edb23ebb9e0f4d21d07f94b8326ecb63da973416b6f035c800ab1f19e0a-image.png),![image.png](https://pic.leetcode-cn.com/33996b01e9701f8dd474164f0463da4d33a5d4f40665b68d778d1bd990b8651f-image.png),![image.png](https://pic.leetcode-cn.com/77fdeb8ab807437acd3264836fe4430d8e7ac0c57bc62d65c156bc66d266c9e9-image.png),![image.png](https://pic.leetcode-cn.com/0930ee9b8e0e24dc4a0f8c8fc44f129065375bc125019597ccacb47bc8810a3e-image.png),![image.png](https://pic.leetcode-cn.com/d18b3bca5be67d77c694fe5821674b7aeed9129ec91477507b8746dafee6541d-image.png),![image.png](https://pic.leetcode-cn.com/1985cd25e02d15c412267d159295f736d04a9514597177ddce2b24cc3ad175da-image.png)>

<br/>
```Java []
class Solution {
  public int lengthOfLongestSubstringTwoDistinct(String s) {
    int n = s.length();
    if (n < 3) return n;

    // sliding window left and right pointers
    int left = 0;
    int right = 0;
    // hashmap character -> its rightmost position 
    // in the sliding window
    HashMap<Character, Integer> hashmap = new HashMap<Character, Integer>();

    int max_len = 2;

    while (right < n) {
      // slidewindow contains less than 3 characters
      if (hashmap.size() < 3)
        hashmap.put(s.charAt(right), right++);

      // slidewindow contains 3 characters
      if (hashmap.size() == 3) {
        // delete the leftmost character
        int del_idx = Collections.min(hashmap.values());
        hashmap.remove(s.charAt(del_idx));
        // move left pointer of the slidewindow
        left = del_idx + 1;
      }

      max_len = Math.max(max_len, right - left);
    }
    return max_len;
  }
}
```

```Python []
from collections import defaultdict
class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s: 'str') -> 'int':
        n = len(s) 
        if n < 3:
            return n
        
        # sliding window left and right pointers
        left, right = 0, 0
        # hashmap character -> its rightmost position 
        # in the sliding window
        hashmap = defaultdict()

        max_len = 2
        
        while right < n:
            # slidewindow contains less than 3 characters
            if len(hashmap) < 3:
                hashmap[s[right]] = right
                right += 1

            # slidewindow contains 3 characters
            if len(hashmap) == 3:
                # delete the leftmost character
                del_idx = min(hashmap.values())
                del hashmap[s[del_idx]]
                # move left pointer of the slidewindow
                left = del_idx + 1

            max_len = max(max_len, right - left)

        return max_len
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N)$ 其中 `N` 是输入串的字符数目。
 
* 空间复杂度：$\mathcal{O}(1)$，这是因为额外的空间只有 hashmap ，且它包含不超过 `3` 个元素。

**相似问题**

相同的滑动窗口问题还可以用来解决如下问题：[《340. 至多包含 K 个不同字符的最长子串》](https://leetcode-cn.com/problems/longest-substring-with-at-most-k-distinct-characters/)
