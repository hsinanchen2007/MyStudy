```
public boolean canConstruct(String s, int k) {
    //所有出现次数为偶数的那些字符全都可以扔到一个回文串中。
    //但两个出现次数为奇数的字符无法组成一个回文串，有n个出现次数为奇数的字符就需要n个回文串容纳。
    //所以只要出现次数为奇数的字符数量不大于回文串的数量就可以。
    if (s.length() < k) {
        return false;
    }

    int[] count = new int[26];
    for (int i = 0; i < s.length(); i++) {
        count[s.charAt(i) - 'a']++;
    }
    int oddCount = 0;
    for (int i = 0; i < count.length; i++) {
        if (count[i] % 2 == 1) {
            oddCount++;
        }
    }
    return oddCount <= k;
}
```
