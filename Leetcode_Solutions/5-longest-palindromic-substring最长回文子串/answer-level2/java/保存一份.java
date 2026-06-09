### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
        if(s.length() == 1){
            return s;
        }

        /***
         * 处理字符串，无论偶数字符串还是奇数字符串都变成奇数串，方便找中心 eg:abc->#a#b#c#
         */
        char orichar[] = s.toCharArray();
        String dealStr = "#";
        for (int i = 0; i < s.length(); i++) {
            dealStr += orichar[i];
            dealStr += "#";
        }

        int radius[] = new int[dealStr.length()];
        int maxLen = 0;//最大回文子串长度
        int right = 0;//当前最大回文子串对应最右边位置
        int maxPosition = 0;//当前最大回文子串位置

        for (int i = 0; i < dealStr.length(); i++) {
            /***
             * 条件：若当前中心位置小于right，
             *       则当前中心位置i相对maxPosition左边对应位置i_left(2 * maxPosition -i)为中心的回文串半径
             *       与right - i进行比较则有以下2种情况：
             * 1.若radius[i_left] < right - i,则说明radius[i] < right-i，当前中心位置对应回文串 = radius[i_left]，并小于maxPosition对应回文串。
             * 2.若radius[i_left] > right - i,则说明radius[i]可能会大于radius[maxPosition],不妨赋值radius[i] = right - 1，后续进行暴力破解。
             * 条件：若当前中心位置大于right，则赋值radius[i] = 1，后进行暴力破解。
             */
            radius[i] = i < right ? Math.min(radius[2 * maxPosition -i], right - i) : 1;

            /**
             * 暴力破解，每次分别比较以当前位置为中心对称两点的值，如果相等，则回文半径加一。
             */
            while ((i + radius[i]) < dealStr.length() &&
                    (i - radius[i]) >= 0 &&
                    dealStr.charAt(i + radius[i]) == dealStr.charAt(i - radius[i])) {
                radius[i] = radius[i] + 1;
            }

            /**
             * 如果右边界小于 当前中心位置 + 当前中心位置对应回文半径 - 1，则更新右边界以及中心位置
             */
            if ((radius[i] > radius[maxPosition]) && right < i + radius[i] -1) {
                right = radius[i] +i -1;
                maxPosition = i;
            }

            /***
             * 更新此
             * 在以maxPosition点为中点的回文长度为（2 * radius[maxPosition]-1），半径为radius[maxPosition]。设在其中的“#”有x个，其他字符有y个，则：
             * x + y = 2radius[maxPosition] - 1
             * 由于在每个字符前后都有一个“#”，显而易见“#”要比其他的字符多一个，则：
             * x-y=1
             * 解以上两个方程得:
             * y= radius[maxPosition] - 1
             */
            if (maxLen < radius[i]) {
                maxLen = radius[i] -1;
            }
        }
        /**
         * 算出带#的最长回文子串
         */
        dealStr = dealStr.substring(maxPosition - (radius[maxPosition] - 1), maxPosition + radius[maxPosition]);
        return dealStr.replaceAll("#", "");
    }
}
```