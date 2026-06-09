### 解题思路
首先构造一个针对回文串的Hash函数，可以大概率过滤非回文串。
对于一个长度为$N$字符串$s$我们当成字符序列：$c_{0},c_{1},\cdots,c_{N-1}$
求$a_{i}=c_{i} \bigoplus c_{i+1},i=0,1,\cdots,N-2$，（$\bigoplus$是二进制异或）
令Hash函数：$f(s)=(1<<(a_{0}\&31))\bigoplus(1<<(a_{1}\&31))\bigoplus\cdots\bigoplus(1<<(a_{N-2}\&31))$，（$<<$是二进制左移，$\&$是二进制与）

若$s$是回文串，则
$$f(s)=
\begin{cases}
0, len(s)是奇数或len(s)=0\\
1, otherwise
\end{cases}$$
否则，对于长度为$N$的随机非回文串$s$，$f(s)$有大约$\frac{7}{1000N}(N>4)$的概率满足以上Hash值。

用C#代码来表示如下：
```csharp
static int GetHashCode(ReadOnlySpan<char> s) {
    int hash = 0;
    for (int i = 1; i < s.Length; i++) {
        int xor = s[i - 1] ^ s[i];
        hash ^= 1 << (xor & 31);
    }
    return hash;
}
```

这个Hash函数有个非常好的性质，在我们已知字符串$s$和$f(s)$的情况下，对$s$删除或插入任意字符，都可以在$O(1)$时间内求得新字符串的Hash值。

最后再利用Trie树来实现就行了，这部分就不细说了，直接上代码。


### 代码

```csharp
public class Solution {
    class Node {
        public Node[] Children;
        public int WordIndex = -1;
        public List<int> PalindromeIndexes;

        Node GetChild(char c) {
            if (Children == null) Children = new Node[26];
            ref var child = ref Children[c - 'a'];
            if (child == null) child = new Node();
            return child;
        }

        void AddPalindromeIndex(int index) {
            if (PalindromeIndexes == null) PalindromeIndexes = new List<int>();
            PalindromeIndexes.Add(index);
        }

        public static Node BuildTrieTree((int HashCode, string Value)[] words) {
            var root = new Node();
            for (int i = 0; i < words.Length; i++) {
                var word = words[i];
                int hashCode = word.HashCode;
                string value = word.Value;
                var curr = root;
                for (int subLen = value.Length; subLen >= 2; subLen--) {
                    if (IsPalindrome(value.AsSpan(0, subLen), hashCode)) {
                        curr.AddPalindromeIndex(i);
                    }
                    hashCode ^= 1 << ((value[subLen - 2] ^ value[subLen - 1]) & 31);
                    curr = curr.GetChild(value[subLen - 1]);
                }
                curr.AddPalindromeIndex(i);
                if (value.Length > 0) {
                    curr = curr.GetChild(value[0]);
                    curr.AddPalindromeIndex(i);
                }
                curr.WordIndex = i;
            }
            return root;
        }
    }

    static int GetHashCode(ReadOnlySpan<char> s) {
        int hash = 0;
        for (int i = 1; i < s.Length; i++) {
            int xor = s[i - 1] ^ s[i];
            hash ^= 1 << (xor & 31);
        }
        return hash;
    }

    static bool IsPalindrome(ReadOnlySpan<char> s, int hashCode) {
        int targetHashCode = (s.Length & 1) ^ 1;
        if (hashCode != targetHashCode) return false;

        int len = s.Length / 2;
        for (int i = 0; i < len; i++) {
            if (s[i] != s[s.Length - 1 - i]) return false;
        }
        return true;
    }

    public IList<IList<int>> PalindromePairs(string[] ss) {
        var words = Array.ConvertAll(ss, s => (HashCode: GetHashCode(s), Value: s));
        var root = Node.BuildTrieTree(words);
        var result = new List<IList<int>>();

        for (int i = 0; i < words.Length; i++) {
            var word = words[i];
            Node curr = root;
            int hashCode = word.HashCode;
            string value = word.Value;
            for (int j = 0; j < value.Length - 1; j++) {
                if (curr.WordIndex >= 0 && i != curr.WordIndex) {
                    if (IsPalindrome(value.AsSpan(j), hashCode)) {
                        result.Add(new[] { i, curr.WordIndex });
                    }
                }
                curr = curr.Children?[value[j] - 'a'];
                if (curr == null) break;
                hashCode ^= 1 << ((value[j] ^ value[j + 1]) & 31);
            }
            if (value.Length > 0) {
                if (curr == null) continue;
                if (curr.WordIndex >= 0 && i != curr.WordIndex) {
                    result.Add(new[] { i, curr.WordIndex });
                }
                curr = curr.Children?[value[value.Length - 1] - 'a'];
            }
            if (curr?.PalindromeIndexes != null) {
                foreach (var index in curr.PalindromeIndexes) {
                    if (i != index) {
                        result.Add(new[] { i, index });
                    }
                }
            }
        }

        return result;
    }
}
```