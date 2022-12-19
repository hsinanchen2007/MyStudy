#### 方法一：暴力法

**思路**

记录机械手上一个位置 `pre`（初始为 0）。遍历字符串 `word`，对于每一个字符 `word[i]`，再遍历 `keyboard` 找到对应的下标。对应下标和上一个位置 `pre` 的差就是移动到当前字符的时间，同样的方法计算所有字符的移动时间并累加即可。

**代码**

```Golang [ ]
func calculateTime(keyboard string, word string) int {
    sum, pre := 0, 0 
    for i := 0; i < len(word); i++ {
        for j := 0; j < 26; j++ {
            if keyboard[j] == word[i] {
                sum += abs(j - pre) // 计算移动到当前字符的时间
                pre = j // 保存上一个位置
                break
            }
        }
    }
    return sum
}

func abs(x int) int {
    if x < 0 {
        return -1 * x
    }
    return x
}
```

```cpp []
class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int sum = 0, pre = 0;
        for (int i = 0; i < word.size(); ++i) {
            for (int j = 0; j < 26; ++j) {
                if (keyboard[j] == word[i]) {
                    sum += abs(j - pre);
                    pre = j;
                    break;
                }
            }
        }
        return sum;
    }
};
```

**复杂度分析**

- 时间复杂度：$O(n)$，其中 $n$ 为字符串 `word` 的长度，外层循环遍历一次 `word`。内层循环遍历 `keyboard`，长度固定为 26。

- 空间复杂度：$O(1)$，没有使用额外的空间。

#### 方法二：哈希表

**思路**

方法一每次都暴力查找当前字符的下标，当 `keyboard` 长度很长的时候时间复杂度会很高，我们可以使用哈希表，保存所有字符的下标。在遍历 `word` 的时候直接通过哈希表查找当前字符的下标。

**代码**

```Golang [ ]
func calculateTime(keyboard string, word string) int {
    m := map[byte]int{}
    // 构建哈希表，记录每个字符的下标
    for i := 0; i < len(keyboard); i++ {
        m[keyboard[i]] = i
    }
    sum, pre := 0, 0
    for i := 0; i < len(word); i++ {
        sum += abs(m[word[i]] - pre)
        pre = m[word[i]]
    }
    return sum
}

func abs(x int) int {
    if x < 0 {
        return -1 * x
    }
    return x
}
```

```cpp []
class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map <char, int> m;
        for (unsigned i = 0; i < keyboard.size(); ++i) {
            m[keyboard[i]] = i;
        }
        int sum = 0, pre = 0;
        for (int i = 0; i < word.size(); ++i) {
            sum += abs(m[word[i]] - pre);
            pre = m[word[i]];
        }
        return sum;
    }
};
```

**复杂度分析**

- 时间复杂度：$O(n)$，其中 $n$ 为字符串 `word` 的长度，遍历一次 `word` 计算移动时间。构建哈希表遍历一次 `keyboard`，长度固定为 26。 

- 空间复杂度：$O(1)$，哈希表的大小为 `keyboard` 的长度，固定为 26。