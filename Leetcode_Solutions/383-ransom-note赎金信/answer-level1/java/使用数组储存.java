### **思路：** 
    复习一下如何获取某个字符在26个字母中所在位置，c-'a'，因为字符在计算器中是
    通过ascii编码储存为二进制的，所以字符其实也是一种特殊的数组.
    当前字符减去最小的字符后就是字符所在的26位中的哪一位。
    用这个方法，将第二个字符串的字符的数量储存在一个26位的数组中，
    获取第一个字符串的字符下标，减去数组中对于位置的值，表示当前字符被使用的
    剩余数量，当数量小于0，说明字符串二无法找到多余与字符一匹配的字符了，按照
    题意，返归false.
```java []
public boolean canConstruct(String ransomNote, String magazine) {
        int[] ints = new int[26];
        for (char c:magazine.toCharArray()
             ) {
           ints[c-'a']++;
        }
        for (char c:ransomNote.toCharArray()
        ) {
            ints[c-'a']--;
            if(ints[c-'a']<0)return false;
        }
        return true;
    }
```

