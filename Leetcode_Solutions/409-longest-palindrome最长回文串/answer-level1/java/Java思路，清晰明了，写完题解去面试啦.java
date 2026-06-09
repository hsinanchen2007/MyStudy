### 解题思路
大体上和前几天做的一道题差不多，用数组统计出现的各个字符的次数，比较坑的是，大写字符和小写字符在ASCII中不连续，所以要多开辟一点数组的空间，大写A也在小写a前面，所以这个地方也要注意。

还有一个坑点是我自己脑子瓦特了没想到，为单数的字符只要减1之后,可以编程偶数或是0，这样就能拼到回文串里面了，最后判断如果出现了这样的情况，再把结果加一个字符就可以了，当做中心点的字符。

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        int sum = 0;
        boolean hasSingle = false;
        //根据ASCII表，大写字母和小写字母不是连贯的，所以不能直接开辟52个空间
        int[] arr = new int[58];
        for (int i = 0; i < s.length(); i++) {
            //'A'在'a'前面，所以减去'A'当做索引下标的标准
            arr[s.charAt(i) - 'A']++;
        }
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] % 2 == 0) {
                sum += arr[i];
            } else {
                //为单数时，减1则表示能成为最多的使用可的字符
                sum += (arr[i] - 1);
                //表示可以添加一个字符当做回文串的中心
                hasSingle = true;
            }
        }
        return hasSingle ? sum + 1 : sum;
    }
}
```