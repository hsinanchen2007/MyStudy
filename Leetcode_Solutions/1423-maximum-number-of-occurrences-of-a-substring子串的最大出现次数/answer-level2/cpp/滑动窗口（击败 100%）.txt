首先晒一下复杂度：

![complexity.png](https://pic.leetcode-cn.com/a21fd0fa6d74bfd4bd3e0133ecbfdf3574c239d2f6fd9d28b35aac147d934cd8-complexity.png)

首先我们考虑题目的特性，虽然 size 的要求是在 `minSize` 到 `maxSize` 之间，但我们实际只需要考虑 `minSize`。因为如果长度为 `maxSize` 的子串出现了 $n$ 次，那长度为 `minSize` 的子串一定也出现了至少 $n$ 次。

固定了 size 之后，这就是一道典型的滑动窗口题目。而且是固定窗口长度的滑动窗口，比较好写。滑动窗口的时间复杂度只有 $O(n)$。

参考代码：

```C++
int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        
    unordered_map<string, int> occur;
    
    countOccur(s, maxLetters, minSize, occur);
    
    int mo = 0;
    for (auto e : occur) {
        mo = max(mo, e.second);
    }
    return mo;
}

void countOccur(string& s, int maxLetters, int size, unordered_map<string, int>& occur) {
    if (s.length() < size) {
        return;
    }

    unordered_map<char,int> m;
    int letters = 0;
    for (int k = 0; k < size; k++) {
        char c = s[k];
        m[c]++;
        if (m[c] == 1) {
            letters++;
        }
    }
    if (letters <= maxLetters) {
        string t = s.substr(0, size);
        occur[t]++;
    }

    int i = 0;
    int j = size;
    while (j < s.length()) {
        char c1 = s[i++];
        m[c1]--;
        if (m[c1] == 0) {
            letters--;
        }
        char c2 = s[j++];
        m[c2]++;
        if (m[c2] == 1) {
            letters++;
        }
        if (letters <= maxLetters) {
            string t = s.substr(i, j-i);
            occur[t]++;
        }
    }
}
```

## 