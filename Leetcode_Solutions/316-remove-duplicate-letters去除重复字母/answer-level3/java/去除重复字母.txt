#### 思路

首先要知道什么叫 “字典序”。字符串之间比较跟数字之间比较是不太一样的。字符串比较是从头往后一个字符一个字符比较的。哪个字符串大取决于两个字符串中 _第一个对应不相等的字符_ 。根据这个规则，任意一个以 `a` 开头的字符串都大于任意一个以 `b` 开头的字符串。

综上所述，解题过程中我们将 _最小的字符尽可能的放在前面_ 。下面将给出两种 $O(N)$ 复杂度的解法：

1. 方法一：题目要求最终返回的字符串必须包含所有出现过的字母，同时得让字符串的字典序最小。因此，对于最终返回的字符串，最左侧的字符是在能保证其他字符至少能出现一次情况下的最小字符。

2. 方法二：在遍历字符串的过程中，如果字符 `i` 大于字符`i+1`，在字符 `i` 不是最后一次出现的情况下，删除字符 `i`。

#### 方法一：贪心 - 一个字符一个字符处理

**算法**

每次递归中，在保证其他字符至少出现一次的情况下，确定最小左侧字符。之后再将未处理的后缀字符串继续递归。

**实现**

```python [solution1-Python]
from collections import Counter

class Solution:
    def removeDuplicateLetters(self, s: str) -> str:

        # find pos - the index of the leftmost letter in our solution
        # we create a counter and end the iteration once the suffix doesn't have each unique character
        # pos will be the index of the smallest character we encounter before the iteration ends
        c = Counter(s)
        pos = 0
        for i in range(len(s)):
            if s[i] < s[pos]: pos = i
            c[s[i]] -=1
            if c[s[i]] == 0: break
        # our answer is the leftmost letter plus the recursive call on the remainder of the string
        # note we have to get rid of further occurrences of s[pos] to ensure that there are no duplicates
        return s[pos] + self.removeDuplicateLetters(s[pos:].replace(s[pos], "")) if s else ''

```

```java [solution1-Java]
public class Solution {
    public String removeDuplicateLetters(String s) {
        // find pos - the index of the leftmost letter in our solution
        // we create a counter and end the iteration once the suffix doesn't have each unique character
        // pos will be the index of the smallest character we encounter before the iteration ends
        int[] cnt = new int[26];
        int pos = 0;
        for (int i = 0; i < s.length(); i++) cnt[s.charAt(i) - 'a']++;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) < s.charAt(pos)) pos = i;
            if (--cnt[s.charAt(i) - 'a'] == 0) break;
        }
        // our answer is the leftmost letter plus the recursive call on the remainder of the string
        // note that we have to get rid of further occurrences of s[pos] to ensure that there are no duplicates
        return s.length() == 0 ? "" : s.charAt(pos) + removeDuplicateLetters(s.substring(pos + 1).replaceAll("" + s.charAt(pos), ""));
    }
}
```

**复杂度分析**

*时间复杂度：$O(N)$。 每次递归调用占用 $O(N)$ 时间。递归调用的次数受常数限制(只有26个字母)，最终复杂度为 $O(N) * C = O(N)$。

*空间复杂度：$O(N)$，每次给字符串切片都会创建一个新的字符串（字符串不可变），切片的数量受常数限制，最终复杂度为 $O(N) * C = O(N)$。

#### 方法二：贪心 - 用栈

**算法**

用栈来存储最终返回的字符串，并维持字符串的最小字典序。每遇到一个字符，如果这个字符不存在于栈中，就需要将该字符压入栈中。但在压入之前，需要先将之后还会出现，并且字典序比当前字符小的栈顶字符移除，然后再将当前字符压入。

详细过程如下动画所示：

<![2000](https://pic.leetcode-cn.com/Figures/316/1.png),![2000](https://pic.leetcode-cn.com/Figures/316/2.png),![2000](https://pic.leetcode-cn.com/Figures/316/3.png),![2000](https://pic.leetcode-cn.com/Figures/316/4.png),![2000](https://pic.leetcode-cn.com/Figures/316/5.png),![2000](https://pic.leetcode-cn.com/Figures/316/6.png),![2000](https://pic.leetcode-cn.com/Figures/316/7.png),![2000](https://pic.leetcode-cn.com/Figures/316/8.png),![2000](https://pic.leetcode-cn.com/Figures/316/9.png),![2000](https://pic.leetcode-cn.com/Figures/316/10.png),![2000](https://pic.leetcode-cn.com/Figures/316/11.png),![2000](https://pic.leetcode-cn.com/Figures/316/12.png)>


**实现**

```python [solution2-Python]
class Solution:
    def removeDuplicateLetters(self, s) -> int:

        stack = []

        # this lets us keep track of what's in our solution in O(1) time
        seen = set()

        # this will let us know if there are no more instances of s[i] left in s
        last_occurrence = {c: i for i, c in enumerate(s)}


        for i, c in enumerate(s):

            # we can only try to add c if it's not already in our solution
            # this is to maintain only one of each character
            if c not in seen:
                # if the last letter in our solution:
                #    1. exists
                #    2. is greater than c so removing it will make the string smaller
                #    3. it's not the last occurrence
                # we remove it from the solution to keep the solution optimal
                while stack and c < stack[-1] and i < last_occurrence[stack[-1]]:
                    seen.discard(stack.pop())
                seen.add(c)
                stack.append(c)
        return ''.join(stack)

```

```java [solution2-Java]
class Solution {
    public String removeDuplicateLetters(String s) {

        Stack<Character> stack = new Stack<>();

        // this lets us keep track of what's in our solution in O(1) time
        HashSet<Character> seen = new HashSet<>();

        // this will let us know if there are any more instances of s[i] left in s
        HashMap<Character, Integer> last_occurrence = new HashMap<>();
        for(int i = 0; i < s.length(); i++) last_occurrence.put(s.charAt(i), i);

        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            // we can only try to add c if it's not already in our solution
            // this is to maintain only one of each character
            if (!seen.contains(c)){
                // if the last letter in our solution:
                //     1. exists
                //     2. is greater than c so removing it will make the string smaller
                //     3. it's not the last occurrence
                // we remove it from the solution to keep the solution optimal
                while(!stack.isEmpty() && c < stack.peek() && last_occurrence.get(stack.peek()) > i){
                    seen.remove(stack.pop());
                }
                seen.add(c);
                stack.push(c);
            }
        }
    StringBuilder sb = new StringBuilder(stack.size());
    for (Character c : stack) sb.append(c.charValue());
    return sb.toString();
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$。虽然外循环里面还有一个内循环，但内循环的次数受栈中剩余字符总数的限制，因此最终复杂度仍为 $O(N)$。

* 空间复杂度：$O(1)$。看上去空间复杂度像是 $O(N)$，但这不对！首先， `seen` 中字符不重复，其大小受字母表大小的限制。其次，只有 `stack` 中不存在的元素才会被压入，因此 `stack` 中的元素也唯一。所以最终空间复杂度为 $O(1)$。