**方法一：HashMap记录字符个数**
```
class Solution {
    /**
    * 思路：
    * 由题回文串最多只有一个中心字目可以是奇数个，其余字母全是偶数个。
    * (1) 创建 HashMap 存储每个字母出现的次数；
    * (2) 遍历 HashMap 存储的次数，
    *   如果字符有偶数个则回文串长度全部添加，为奇数则添加奇数个-1；
    * (3) 最后判断回文串长度小于原字符串则长度+1，否则直接返回回文串长度。
    */
    public int longestPalindrome(String s) {
        int ans = 0;
        Map<Character,Integer> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++){
            if(map.containsKey(s.charAt(i))){
                map.put(s.charAt(i),map.get(s.charAt(i)) + 1);
            }else {
                map.put(s.charAt(i),1);
            }
        }
        for (int num : map.values()) {
            if(num % 2 == 0){
                ans += num;
            }else {
                ans += num - 1;
            }
        }
        return ans < s.length() ? ans + 1 : ans;
    }
}
```

**方法二：HashMap记录字符一次循环**
```
class Solution {
    /**
    * 思路：
    * (1) 创建 HashMap 存储每个字母出现的次数；
    * (2) 遍历字符串中字符存入HashMap，
    *   只要字母出现第二次回文串长度就+2并且将map中该字母移除；
    * (3) 最后比较回文串长度和原字符串长度，如果小于则+1，否则直接返回。
    */
    public int longestPalindrome(String s) {
        int ans = 0;
        Map<Character,Integer> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++){
            if(map.containsKey(s.charAt(i))){
                ans += 2;
                map.remove(s.charAt(i));
            }else {
                map.put(s.charAt(i),1);
            }
        }
        return ans < s.length() ? ans + 1 : ans;
    }
}
```

**方法三：ASCII字符编码表计数**
```
class Solution {
    /**
    * 思路：
    * (1) 创建字符集数组存储字母个数；
    * (2) 回文串长度累加所有遍历出现偶数次的字母；
    * (3) 最后比较回文串长度和原字符串长度，如果小于则+1，否则直接返回。
    */
    public int longestPalindrome(String s) {
        int ans = 0;
        int[] count = new int[128];
        for (char c: s.toCharArray()){
            if(count[c] == 1){
                ans += 2;
                count[c]--;
            }else {
                count[c]++;
            }
        }
        return ans < s.length() ? ans + 1 : ans;
    }
}
```
