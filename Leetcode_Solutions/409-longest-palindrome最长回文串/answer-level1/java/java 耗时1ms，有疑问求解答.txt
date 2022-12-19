**curCount /2*2 这种写法耗时多,2ms，不知道为什么，希望有人能解答下~**

```
class Solution {
    public int longestPalindrome(String s) {
        //先排除空串
        if (s == null || s.length() == 0) {
            return 0;
        }
        //把字符串转换成char数组
        char[] charArr = s.toCharArray();
        //定义一个数组，放对应字符的出现次数。
        int[] arrCount = new int[128];
        for (char c : charArr) {
           arrCount[c]++;
        }
        
        //回文串长度
        int count = 0;
        for(int curCount : arrCount){
            //取出2的倍数的长度，奇数会忽略一个，
            //注意 curCount /2*2 这种写法耗时多,2ms，不知道为什么，希望有人能解答下~
            count += ((curCount /2)*2);
        }
        //如果所有字符个数都是偶数出现，会相等，直接返回
        if (count == s.length()) {
            return count;
        } else {
            //如果有奇数个数出现的字符，长度 + 1
            return count + 1;
        }
    }
}
```
