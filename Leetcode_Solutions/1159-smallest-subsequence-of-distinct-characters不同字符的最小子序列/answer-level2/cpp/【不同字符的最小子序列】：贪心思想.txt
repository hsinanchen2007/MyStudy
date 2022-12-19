贪心和动态规划一样，考验的是对问题分析的能力，贪心算法解题的关键在于**如何找到每次的局部最优解**，动态规划则是如何找到状态转移方程。

---

首先解释一下两个名词：

**字典序**：对于字符而言，按 ascii 码值进行比较，小的排在前，大的排在后。对于字符串，从第 0 位字符开始比较，ascii 码数值小的排在前面，如果相同，就延后一位比较 ascii 码值大小。

**子序列**：子序列不同于子串，子串要求它们在原串中连续，而子序列则不要求连续。例如`acd`是`abcd`的子序列，但不是子串。

---

##### 首先判断能否用贪心算法来解决

一个题能不能用贪心思想来解决取决于它能不能通过局部最优得到全局最优。

这道题的全局最优是找到这样一个子序列：“字典序排列最小并且包含 text 中所有的不同字符一次”。

例如，对于`text = "ebcee"`，满足包含 text 中所有的不同字符一次的子序列有`"ebc"`和`"bce"`，但其中字典序最小是`"bce"`。所以对于`text = "ebcee"`而言，它的全局最优就是`"bce"`。

![image](https://pic.leetcode-cn.com/7e06806f1417b326453bf08fdc4d4ea51e21c6188e865fb7bc6e77abcd15950a-file_1574339518028)

通过对比我们发现，只要保证所求的子序列串中从第 0 位开始的每一个字符的 ascii 码是最小的，那整个子序列的字典序就是最小的了。所以局部最优就是保证子序列从第 0 位开始子序列的每一个字符的 ascii 码是最小的。

这样我们就找到了可以到达全局最优的局部最优了，这就说明这道题可以使用贪心思想来解决。

---

##### 如何得到局部最优

也就是如何保证子序列从第 0 位开始每个字符的 ascii 码最小呢？

还是以`text = "ebcee"`为例，
我们可以每次都从 26 个英文字母表`'a'~'z'`依次遍历，先看看`a`可不可以放到第一个：

![image](https://pic.leetcode-cn.com/f154f350a851929706bb5858dd81571862a6d631bbfaae06f2545d7da068fd14-file_1574339518059)

我们发现 text 中没有`a`，所以子序列中也不能有`a`。`a`不行我们再看看字母`b`可不可以：

![image](https://pic.leetcode-cn.com/ade1bcfa8b6a4ed81a3ed151017ace73972ddb96b535d643af6f060bdff52e2a-file_1574339518057)

这时我们发现 text 中有`b`了，但有`b`就可以填入了吗？题目要求的是”包含 text 中所有的不同字符“，我们选择`b`的话，还要看看`pos`后面的所有字符加上已选的字符`b`能不能包含 text 中所有的不同字符。

幸运的是`pos`后面还有字符`c`,`e`，加上`b`之后就正好是 text 中的所有字符了：`e`,`b`,`c`。所以子序列的第一个字符就确定下来了！填入`b`。

![image](https://pic.leetcode-cn.com/10fa06a7e82c7a9d77a7d920652efd32bcfc14f6b33e4487edb60c1602093cca-file_1574339518055)

这样我们就保证子序列的第 0 位填上了最优的字符。

按照这个选择局部最优的方式再填充子序列下一位：从字母表`'a'~'z'`依次遍历，`a`在 text 中没有，`b`在子序列中已经存在了，最后发现`c`可以填入，并且`pos`后面的字符`e`可以和已选的`b`,`c`构成 text 中的所有字符，于是子序列第 1 位填上了最优字符`c`。

![image](https://pic.leetcode-cn.com/fc9d4b5ded748b521023e9aecf084491951a76b0bbca308e1131e756dc8b2e52-file_1574339518020)

最后再按照相同的操作填入了`e`:

![image](https://pic.leetcode-cn.com/5511b774e4c613c425978dd85f8f925f946d37b26aaeecc965959a5e8b6c8d75-file_1574339518040)

接着发现`text`中所有的唯一字符(`'e'`,`'b'`,`'c'`)都已经选过了，结束循环。

这样按照每次都尽可能选择 ascii 最小的字符进行填充所得到的子序列就是字典序最小的子序列了。

```cpp
while (text中还有字符没有选) {
    for (int i = 0; i < 26; i++) {
        if (text包含该字符 && 子序列可包含text中所有字符) {
            ret.push_back(i+'a');  //添加到子序列末尾
        }
    }
}
```

到了这步，贪心思想就已经完全体现出来了：
每一次我们都在满足一定条件下选择字典序最小的字符，最后得到的子序列势必是符合条件，并且字典序最小的。

接下来就到了将思想用程序体现出来的过程了，这个过程注定是朴实无华且{枯燥|you qu}的。

##### 代码实现

这里使用位掩码来保存 text 中的所有字符：

```cpp
int all = 0;
for (int i = 0; i < len; i++) {
    all |= (1 << (text[i] - 'a'));
}
```

---

使用`all & (1 << i)`来判断 text 中是否包含字符`i+'a'`。

函数`isOk(text, all, i+'a', pos)`用来判断字符`i+'a'`之后的所有字符能否包含 text 中剩下未选的所有字符，如果包含则附带更新`pos`的位置。

`all ^= (1 << i)`表示将所选字符从剩下的字符集`all`中移除。

```cpp
//pos表示所选的当前字符在text中的位置
int pos = 0;
while (all) {
    for (int i = 0; i < 26; i++) {
        if ((all & (1 << i)) && isOk(text, all, i+'a', pos)) {
            ret.push_back(i+'a');
            all ^= (1 << i);
            break;
        }
    }
}
```

---

完整代码：

```cpp
class Solution {
public:
    string smallestSubsequence(string text) {
        string ret = "";
        int len = text.length();
        int all = 0;
        for (int i = 0; i < len; i++) {
            all |= (1 << (text[i] - 'a'));
        }
        //pos表示所选的当前字符在text中的位置
        int pos = 0;
        while (all) {
            for (int i = 0; i < 26; i++) {
                if ((all & (1 << i)) && isOk(text, all, i+'a', pos)) {
                    ret.push_back(i+'a');
                    all ^= (1 << i);
                    break;
                }
            }
        }
        return ret;
    }

    bool isOk(string& text, int all, char ch, int& pos) {
        int len = text.length();
        int i = pos;
        for (; i < len; i++) {
            if (text[i] == ch) {
                break;
            }
        }
        int p = i+1;
        int t = 0;
        for (; i < len; i++) {
            if (all & (1 << (text[i]-'a'))) {
                t |= (1 << (text[i]-'a'));
            }
        }
        if (t == all) {
            pos = p;
            return true;
        }
        return false;
    }
};
```

## 总结

像这类题型属于使用纯粹的贪心思想就能解决的问题，当然这道题的许多题解中还有很多巧妙的方法，不过不建议初学者立刻去学习这些巧妙的方法。前期多使用纯粹的贪心思想解决题目会对我们理解贪心很有帮助。

这里还给大家找了一个可以使用纯粹贪心思想解决的题，有空可以去做做：

[135. 分发糖果](https://leetcode-cn.com/problems/candy/ "135. 分发糖果")

你知道吗？Dijkstra 最短路径算法也使用了贪心思想，贪心思想还经常和二分、前缀和一起使用哦。加油吧。


**[点我阅读原文](https://mp.weixin.qq.com/s/6_C8PCq9jv-xKujRYMQO7Q)**