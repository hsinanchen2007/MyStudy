#### 方法一：穷举 [超出时间限制]

一个比较简单的做法是，我们生成字符串 $\mathrm{s}$ 的每一个排列，然后逐个检查它们是否为回文串。在得到了这些回文串后，我们可以用集合（set）进行去重操作，最终集合中的每一个元素就是一个回文串。

生成字符串的所有排列的做法有很多种，我们可以使用递归的方法，借助 `permute` 函数来生成所有的排列。`permute` 函数需要传入一个参数 `current_index`，该函数会将 `current_index` 位置的字符和它之后（包括本身）的每一个位置的字符进行交换。当一次交换操作结束后，会递归调用 `permute` 函数，且 `current_index` 的值增加 1。当 `current_index` 到达字符串末尾时，就得到了一个字符串的排列。下面的幻灯片给出了一个具体的例子。

<![1200](https://pic.leetcode-cn.com/Figures/561_ArraySlide1.PNG),![1200](https://pic.leetcode-cn.com/Figures/561_ArraySlide2.PNG),![1200](https://pic.leetcode-cn.com/Figures/561_ArraySlide3.PNG),![1200](https://pic.leetcode-cn.com/Figures/561_ArraySlide4.PNG),![1200](https://pic.leetcode-cn.com/Figures/561_ArraySlide5.PNG),![1200](https://pic.leetcode-cn.com/Figures/561_ArraySlide6.PNG),![1200](https://pic.leetcode-cn.com/Figures/561_ArraySlide7.PNG),![1200](https://pic.leetcode-cn.com/Figures/561_ArraySlide8.PNG),![1200](https://pic.leetcode-cn.com/Figures/561_ArraySlide9.PNG),![1200](https://pic.leetcode-cn.com/Figures/561_ArraySlide10.PNG),![1200](https://pic.leetcode-cn.com/Figures/561_ArraySlide11.PNG)>

```Java [sol1]
public class Solution {
    Set < String > set = new HashSet < > ();
    public List < String > generatePalindromes(String s) {
        permute(s.toCharArray(), 0);
        return new ArrayList < String > (set);
    }
    public boolean isPalindrome(char[] s) {
        for (int i = 0; i < s.length; i++) {
            if (s[i] != s[s.length - 1 - i])
                return false;
        }
        return true;
    }
    public void swap(char[] s, int i, int j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    void permute(char[] s, int l) {
        if (l == s.length) {
            if (isPalindrome(s))
                set.add(new String(s));
        } else {
            for (int i = l; i < s.length; i++) {
                swap(s, l, i);
                permute(s, l + 1);
                swap(s, l, i);
            }
        }
    }
}
```

**复杂度分析**

* 时间复杂度：$O(|S|* |S|!)$。对于字符串 $\mathrm{s}$，一共有 $|S|!$ 个排列。对于每一个排列，需要 $O(n)$ 的时间判断其是否为回文串。因此总的时间复杂度为 $O(|S|*|S|!)$。
* 空间复杂度：$O(|S|)$。递归的层数最多为 $|S|$。

#### 方法二：回溯 [通过]

有可能字符串本身就没法构造出一个回文排列，因此需要首先判断该字符串是否存在回文排列，具体的方法可以参考[回文排列](https://leetcode-cn.com/problems/palindrome-permutation/)这题中的题解部分。

当我们确定了字符串可以构造出回文排列之后，接下来仍然需要找出所有的回文排列。我们可以考虑直接枚举回文排列，即枚举一个排列的前半部分，将它的前半部分翻转即可得到一个回文排列。前半部分包含的每个字符的具体数量都是固定的，因此我们可以用与方法一中完全相同的方法，来枚举前半部分的所有排列。特别地，当字符串的长度为奇数时，那个唯一出现奇数次的字符需要被放在回文串的中间位置。

方法一中使用集合来进行去重操作，我们可以考虑在生成排列时添加约束，直接避免这些重复的回文串被生成。一个简单的做法是，当我们交换 `current_index` 和某个不同位置的两个字符时，如果这两个字符相同，就不进行交换操作（因为这与 `current_index` 和自己交换是等价的）。下面的幻灯片给出了一个具体的例子。

<![1000](https://pic.leetcode-cn.com/Figures/267/267_Palindrome_Permutation_IISlide1.PNG),![1000](https://pic.leetcode-cn.com/Figures/267/267_Palindrome_Permutation_IISlide2.PNG),![1000](https://pic.leetcode-cn.com/Figures/267/267_Palindrome_Permutation_IISlide3.PNG),![1000](https://pic.leetcode-cn.com/Figures/267/267_Palindrome_Permutation_IISlide4.PNG),![1000](https://pic.leetcode-cn.com/Figures/267/267_Palindrome_Permutation_IISlide5.PNG),![1000](https://pic.leetcode-cn.com/Figures/267/267_Palindrome_Permutation_IISlide6.PNG),![1000](https://pic.leetcode-cn.com/Figures/267/267_Palindrome_Permutation_IISlide7.PNG),![1000](https://pic.leetcode-cn.com/Figures/267/267_Palindrome_Permutation_IISlide8.PNG),![1000](https://pic.leetcode-cn.com/Figures/267/267_Palindrome_Permutation_IISlide9.PNG)>

```Java [sol2]
public class Solution {
    Set < String > set = new HashSet < > ();
    public List < String > generatePalindromes(String s) {
        int[] map = new int[128];
        char[] st = new char[s.length() / 2];
        if (!canPermutePalindrome(s, map))
            return new ArrayList < > ();
        char ch = 0;
        int k = 0;
        for (int i = 0; i < map.length; i++) {
            if (map[i] % 2 == 1)
                ch = (char) i;
            for (int j = 0; j < map[i] / 2; j++) {
                st[k++] = (char) i;
            }
        }
        permute(st, 0, ch);
        return new ArrayList < String > (set);
    }
    public boolean canPermutePalindrome(String s, int[] map) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            map[s.charAt(i)]++;
            if (map[s.charAt(i)] % 2 == 0)
                count--;
            else
                count++;
        }
        return count <= 1;
    }
    public void swap(char[] s, int i, int j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    void permute(char[] s, int l, char ch) {
        if (l == s.length) {
            set.add(new String(s) + (ch == 0 ? "" : ch) + new StringBuffer(new String(s)).reverse());
        } else {
            for (int i = l; i < s.length; i++) {
                if (s[l] != s[i] || l == i) {
                    swap(s, l, i);
                    permute(s, l + 1, ch);
                    swap(s, l, i);
                }
            }
        }
    }
}
```

**复杂度分析**

* 时间复杂度：$O\big(|S|* (\frac{|S|}{2})!\big)$。在最坏情况下，会生成 $(\frac{S}{2})!$ 个排列。在生成每个排列时，翻转操作 `string.reverse()` 的时间复杂度为 $O(|S|)$，因此总的时间复杂度为 $O\big(|S|*(\frac{|S|}{2})!\big)$。
* 空间复杂度：$O(|S|)$。递归的层数最多为 $\frac{|S|}{2}$。