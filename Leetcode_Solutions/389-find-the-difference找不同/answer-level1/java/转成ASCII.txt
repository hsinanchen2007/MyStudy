每一个字母对应一个ASCII字符,对应一个整形数字,因此两个字符串的差值即为随机插入的字符.
```
public char findTheDifference(String s, String t) {
        int sum1 = 0, sum2 = 0;
        for (char c : t.toCharArray()) {
           sum1+=c;
        }
        for (char c : s.toCharArray()) {
            sum2+=c;
        }
        return (char) (sum1-sum2);
    }
```
