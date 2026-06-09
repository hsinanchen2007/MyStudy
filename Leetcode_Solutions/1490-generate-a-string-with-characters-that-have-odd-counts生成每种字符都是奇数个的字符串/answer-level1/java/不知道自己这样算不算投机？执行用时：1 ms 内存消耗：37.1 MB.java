既然n除了0之外只有可能是奇数或者偶数，那么随便取两个小写字母就可以达成要求啦！如果n是偶数，就取n-1个a字符，取一个b字符；如果n是奇数，那就取n个a字符就够了。至此就结束了！对于昨晚第一次参加双周赛只做出第一道题，然后接着今天来参加周赛的我甚至有点怀疑人生！莫名其妙就过第一题了。
```
class Solution {
    public String generateTheString(int n) {
        if (n == 0) {
            return "";
        }
        StringBuilder stringBuilder = new StringBuilder(n);
        if (n % 2 == 0) {
            int m = n - 1;
            for (int i = 0; i < m; i++) {
                stringBuilder.append('a');
            }
            stringBuilder.append('b');
        } else {
            for (int i = 0; i < n; i++) {
                stringBuilder.append('a');
            }
        }
        return stringBuilder.toString();
    }
}
```
