### 解题思路
Check strings' length first, if the length does not match, return false directly.

If the strings' length are identical, we then sort both strings first, and then iterate through each character, and return false if any two characters from two sorted character array are different.

### 代码

```csharp
public class Solution {
    public bool CheckPermutation(string s1, string s2) {
        // 执行用时: 92 ms, 在所有 C# 提交中击败了 35.71% 的用户
        // 内存消耗: 21.9 MB, 在所有 C# 提交中击败了 100.00% 的用户
        
        if (s1.Length != s2.Length) { return false; }

        char[] sortedS1 = s1.OrderBy(c => c).ToArray();
        char[] sortedS2 = s2.OrderBy(c => c).ToArray();

        for (int i = 0; i < sortedS1.Length; i++) {
            if (sortedS1[i] != sortedS2[i]) {
                return false;
            }
        }

        return true;
    }
}
```