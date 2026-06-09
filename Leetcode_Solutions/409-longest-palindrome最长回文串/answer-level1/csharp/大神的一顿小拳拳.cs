### 解题思路
这个题解先说一下，是抄来的，首先这个int[58];因为大小写ASCII码值不连贯，所以这样写
神来之笔(item & 1);这个采用位运算符来区分奇偶数并对其进行取偶操作，
顺便带一下，这个三元运算符也挺不错；
### 代码

```csharp
public class Solution {
    public int LongestPalindrome(string s) {
        int[] count = new int[58];
            foreach (var item in s)
            {
                count[item - 'A']+=1;
            }
            int ans = 0;
            foreach (var item in count)
            {
                ans += item - (item & 1);
            }
            return ans < s.Length ? ans + 1 : ans;
    }
}
```