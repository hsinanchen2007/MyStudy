     这道题和第1160题拼写单词考察的内容相同，就是使用data indexed array来储存数据。相当于自己建立的一个简单的HashMap，key是数组下标，value是字母出现的频率。
```java
       public int maxNumberOfBalloons(String text) {
        int[] cnt=new int[26];
        for(char c:text.toCharArray()){
            cnt[c-'a']++;
        }
        int min = Integer.MAX_VALUE;
        min = Math.min(min, cnt['b' - 'a']);
        min = Math.min(min, cnt['a' - 'a']);
        min = Math.min(min, cnt['l' - 'a'] / 2);
        min = Math.min(min, cnt['o' - 'a'] / 2);
        min = Math.min(min, cnt['n' - 'a']);
        return min;
    }
```
