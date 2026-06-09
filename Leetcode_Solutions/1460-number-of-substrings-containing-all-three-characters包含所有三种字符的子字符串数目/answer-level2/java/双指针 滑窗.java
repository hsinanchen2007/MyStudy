### 解题思路
这道题比赛时一直在往动态规划的方向想，但是怎么都想不出状态是怎么转移的，其实这道题的特征很明显，第一个就是字符串处理，要么就是序列型的动态规划，要么就是滑窗，接着就是要求的是连续的子串，又是固定的abc，又是中等难度，其实很明显就是滑窗了

### 代码

```java
class Solution {
    public int numberOfSubstrings(String s) {
        int[] abc = new int[3];
        if (s.length() < 3) return 0;
        abc[s.charAt(0) - 'a']++;
        abc[s.charAt(1) - 'a']++;
        abc[s.charAt(2) - 'a']++; 
        int i = 0;
        int j = 2;
        int sum = 0;
        while (i < s.length() - 2 && j < s.length()) {
            if (abc[0] > 0 && abc[1] > 0 && abc[2] > 0) {
                sum += s.length() - j;
                abc[s.charAt(i) - 'a']--;
                i++;
                continue;
            } else {
                j++;
                if (j == s.length()) break;
                abc[s.charAt(j) - 'a']++;
            }
        }
        return sum;
    }
}
```