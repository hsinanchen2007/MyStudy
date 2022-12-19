#### 方法 1：字母栈

**想法和算法**

将 `s` 中的所有字母单独存入栈中，所以出栈等价于对字母反序操作。（或者，可以用数组存储字母并反序数组。）

然后，遍历 `s` 的所有字符，如果是字母我们就选择栈顶元素输出。

```Java []
class Solution {
    public String reverseOnlyLetters(String S) {
        Stack<Character> letters = new Stack();
        for (char c: S.toCharArray())
            if (Character.isLetter(c))
                letters.push(c);

        StringBuilder ans = new StringBuilder();
        for (char c: S.toCharArray()) {
            if (Character.isLetter(c))
                ans.append(letters.pop());
            else
                ans.append(c);
        }

        return ans.toString();
    }
}
```

```Python []
class Solution(object):
    def reverseOnlyLetters(self, S):
        letters = [c for c in S if c.isalpha()]
        ans = []
        for c in S:
            if c.isalpha():
                ans.append(letters.pop())
            else:
                ans.append(c)
        return "".join(ans)
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是 `S` 的长度。
* 空间复杂度：$O(N)$。

#### 方法 2：反转指针

**想法**

一个接一个输出 `s`  的所有字符。当遇到一个字母时，我们希望找到逆序遍历字符串的下一个字母。

所以我们这么做：维护一个指针 `j` 从后往前遍历字符串，当需要字母时就使用它。

```Java []
class Solution {
    public String reverseOnlyLetters(String S) {
        StringBuilder ans = new StringBuilder();
        int j = S.length() - 1;
        for (int i = 0; i < S.length(); ++i) {
            if (Character.isLetter(S.charAt(i))) {
                while (!Character.isLetter(S.charAt(j)))
                    j--;
                ans.append(S.charAt(j--));
            } else {
                ans.append(S.charAt(i));
            }
        }

        return ans.toString();
    }
}
```

```Python []
class Solution(object):
    def reverseOnlyLetters(self, S):
        ans = []
        j = len(ans) - 1
        for i, x in enumerate(S):
            if x.isalpha():
                while not S[j].isalpha():
                    j -= 1
                ans.append(S[j])
                j -= 1
            else:
                ans.append(x)
        
        return "".join(ans)
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是 `S` 的长度。
* 空间复杂度：$O(N)$。