### 解题思路
两个26位的数组 
数组1 统计大写字母的数量
数组2 统计小写字母的数量
变量1 统计是否可存在中间数
简单易懂

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        //统计每个字母的个数 除以2
        if (s.length() == 0) {
            return 0;
        }

        //26位数的统计 大写字母
        int[] arrUpper = new int[26];

        //26位 小写字母
        int[] arrLower = new int[26];

        //ASCII值
        //A-Z 65-90 a-z 97-122

        //是否包括中间数
        boolean isHasMid = false;

        int res = 0;

        //hash计数
        for (int i = 0; i < s.length(); i++) {
            if ((s.charAt(i) - 'A') > 26) {
                arrLower[s.charAt(i) - 'a']++;
            } else {
                arrUpper[s.charAt(i) - 'A']++;
            }  
        }

        //遍历hash计数数组
        for (int i = 0; i <26; i++) {
            res += arrLower[i]/2;//统计小写字母数量
            res += arrUpper[i]/2;//统计大写字母数量
            if (isHasMid == false && (arrLower[i]%2 == 1 || arrUpper[i]%2 == 1)) {
                isHasMid = true;
            }
        }

        return isHasMid ? 2*res + 1 : 2*res;
    }
}
```