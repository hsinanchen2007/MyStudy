### 解题思路
整体思路是偶数个数的相同字符一定可以构建对称，最后再判断是否有奇数个数的对称情况。
（1）构建数组hash，统计次数，借助ASCII码知识，A-65，Z-90，a-97，z-122，Z和a之间隔了6个字符。个数设为52也可以。
（2）遍历一遍hash数组，值为偶数直接加，为奇数则减去1再加（只处理恰好的偶数对称）。
（3）最后查看是否有类似于`aacaa`的情况出现，所以判断次数，只要字符串个数不是偶数，就再加上1。

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        if(s == null){
            return 0;
        }

        char[] chars = s.toCharArray();
        int[] hash = new int[58];
        for(char ch : chars){
            hash[ch - 'A'] += 1;
        }

        int count = 0;
        for(int i = 0; i < hash.length; i++){
            if(hash[i] % 2 == 0){
                count += hash[i];
            }else{
                count += --hash[i];
            }
        }

        if(s.length() > count){
            count++;
        }

        return count;
    }
}
```