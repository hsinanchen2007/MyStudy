#### 方法一：替换函数

我们可以用字符串自带的替换函数，由于字符串仅包含小写字母，因此只有 26 种不同的重复项。

1. 将 `aa` 到 `zz` 的 26 种重复项放入集合中；

2. 遍历这 26 种重复项，并用字符串的替换函数把重复项替换成空串。

注意，在进行过一次替换之后，可能会出现新的重复项。例如对于字符串 `abbaca`，如果替换了重复项 `bb`，字符串会变为 `aaca`，出现了新的重复项 `aa`。因此，上面的过程需要背重复若干次，直到字符串在一整轮替换过程后保持不变（即长度不变）为止。

![fig](https://pic.leetcode-cn.com/Figures/1047/repl.png){:width=600}
{:align=center}

```Python [sol1]
from string import ascii_lowercase
class Solution:
    def removeDuplicates(self, S: str) -> str:
        # generate 26 possible duplicates
        duplicates = {2 * ch for ch in ascii_lowercase}
        
        prev_length = -1
        while prev_length != len(S):
            prev_length = len(S)
            for d in duplicates:
                S = S.replace(d, '')
                
        return S
```

```Java [sol1]
class Solution {
    public String removeDuplicates(String S) {
      // generate 26 possible duplicates
        HashSet<String> duplicates = new HashSet();
        StringBuilder sb = new StringBuilder();
        for (char i = 'a'; i <= 'z'; ++i) {
            sb.setLength(0);
            sb.append(i); sb.append(i);
            duplicates.add(sb.toString());
        }

        int prevLength = -1;
        while (prevLength != S.length()) {
            prevLength = S.length();
            for (String d : duplicates) S = S.replace(d, "");
        }

      return S;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N^2)$，其中 $N$ 是字符串的长度。代码中的过程为 `while -> for -> replace`，其中 `while` 执行的次数最多为 $N/2$，`for` 固定执行 26 次，`replace` 的平均复杂度为 $O(N)$，因此总的时间复杂度为 $O(N^2)$。

* 空间复杂度：$O(N)$。由于字符串的替换函数会生成一份原字符串的拷贝，因此空间复杂度为 $O(N)$。

#### 方法二：栈

我们可以用栈来维护没有重复项的字母序列：

- 若当前的字母和栈顶的字母相同，则弹出栈顶的字母；

- 若当前的字母和栈顶的字母不同，则放入当前的字母。

<![1200](https://pic.leetcode-cn.com/Figures/1047/1047_slide_1.png),![1200](https://pic.leetcode-cn.com/Figures/1047/1047_slide_2.png),![1200](https://pic.leetcode-cn.com/Figures/1047/1047_slide_3.png),![1200](https://pic.leetcode-cn.com/Figures/1047/1047_slide_4.png),![1200](https://pic.leetcode-cn.com/Figures/1047/1047_slide_5.png),![1200](https://pic.leetcode-cn.com/Figures/1047/1047_slide_6.png),![1200](https://pic.leetcode-cn.com/Figures/1047/1047_slide_7.png),![1200](https://pic.leetcode-cn.com/Figures/1047/1047_slide_8.png),![1200](https://pic.leetcode-cn.com/Figures/1047/1047_slide_9.png),![1200](https://pic.leetcode-cn.com/Figures/1047/1047_slide_10.png),![1200](https://pic.leetcode-cn.com/Figures/1047/1047_slide_11.png)>{:width=600}
{:align=center}

```Python [sol2]
class Solution:
    def removeDuplicates(self, S: str) -> str:
        output = []
        for ch in S:
            if output and ch == output[-1]: 
                output.pop()
            else: 
                output.append(ch)
        return ''.join(output)
```

```Java [sol2]
class Solution {
    public String removeDuplicates(String S) {
        StringBuilder sb = new StringBuilder();
        int sbLength = 0;
        for (char character : S.toCharArray()) {
            if (sbLength != 0 && character == sb.charAt(sbLength - 1))
                sb.deleteCharAt(sbLength-- - 1);
            else {
                sb.append(character);
                sbLength++;
            }
        }
        return sb.toString();
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是字符串的长度。

* 空间复杂度：$O(N)$。