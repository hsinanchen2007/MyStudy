## 解题方案


### 思路:

- 标签：哈希表
- 本题最容易想到的就是使用哈希表进行运算，遍历第一个字符串标记出现的字符数量，再遍历第二个减去出现的数量，直到遇到为 0 或者原哈希表就不存在的情况

- 标签：异或运算
- 除了上述方法外，会有一个更 tricky 的解法，就是使用字符（**注意不是字符串**）异或运算，尽管并没有降低时间复杂度，但也是一种开阔思路的解题方式
- 使用异或运算可以解题主要因为异或运算有以下几个特点：
  - 一个数和0做XOR运算等于本身：a⊕0 = a
  - 一个数和其本身做XOR运算等于 0：a⊕a = 0
  - XOR 运算满足交换律和结合律：a⊕b⊕a = (a⊕a)⊕b = 0⊕b = b
- 故而在以上的基础条件上，将所有数字按照顺序做抑或运算，最后剩下的结果即为唯一的数字
- 时间复杂度：$O(m+n)$，$m$ 为字符串 $s$ 的长度，$n$ 为字符串t的长度

### 代码:

- Java 版本

```Java [Java]
class Solution {
    public char findTheDifference(String s, String t) {
        char ans = t.charAt(t.length()-1);
        for(int i = 0; i < s.length(); i++) {
            ans ^= s.charAt(i);
            ans ^= t.charAt(i);
        }
        return ans;
    }
}
```

- JavaScript 版本

JavaScript由于**没有字符位运算**所以无法使用异或运算解法。故而使用了第一种哈希表的解法

```JavaScript [-JavaScript]
/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function(s, t) {
    const map = new Map();
    for(let i = 0; i < s.length; i++) {
        const val = map.get(s[i]);
        map.set(s[i], val === undefined ? 1 : val + 1);
    }
    for(let i = 0; i < t.length; i++) {
        const val = map.get(t[i]);
        if(val === 0 || val === undefined) {
            return t[i];
        } else {
            map.set(t[i], val - 1);
        }
    }
};
```


### 画解:

<![1.png](https://pic.leetcode-cn.com/10bef1146d92934a69df90a2754424c1e9fc1630ebfc6a00c63be18d410d06f6-1.png),![2.png](https://pic.leetcode-cn.com/3cb03e34bf48adf63dadcea6c88cf01d49a5e1f6755b6b4391994587c41f552c-2.png),![3.png](https://pic.leetcode-cn.com/366f57cb5b00359729d8572601af36a4df396c5ca6b592c37d58eb683401aa24-3.png)>


