### 解题思路
统计每个单词出现的次数得到count[]
result+=count[i]/2*2
遇到第一个奇数时，result+1，此后再遇到奇数不做操作
### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        //并不是52个，因为Z和a之间多了6个其他符号
        int[] counts = new int[58];
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            counts[s.charAt(i) - 'A']++;
        }
        //每次result加上(count[i]/2)*2,这样result总是偶数，遇到第一个奇数时，result+1，此后再遇到奇数不做操作
        for (int count : counts) {
            result += (count / 2) * 2;
            if ((result & 1) == 0 && (count & 1) != 0) {
                result += 1;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.longestPalindrome("ccc"));
    }
}
```