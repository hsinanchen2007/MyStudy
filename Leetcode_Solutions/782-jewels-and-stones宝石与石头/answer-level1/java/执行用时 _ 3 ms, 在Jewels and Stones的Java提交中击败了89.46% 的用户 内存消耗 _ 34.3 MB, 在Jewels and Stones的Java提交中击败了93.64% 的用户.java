// 执行用时 : 3 ms, 在Jewels and Stones的Java提交中击败了89.46% 的用户
// 内存消耗 : 34.3 MB, 在Jewels and Stones的Java提交中击败了93.64% 的用户
```
class Solution {
    public int numJewelsInStones(String J, String S) {
        int sum = 0;
        for (int i = 0; i < J.length(); i++) {
            for (int j = 0; j < S.length(); j++) {
                if (J.charAt(i) == S.charAt(j))
                    sum++;
            }
        }
        return sum;
    }
}