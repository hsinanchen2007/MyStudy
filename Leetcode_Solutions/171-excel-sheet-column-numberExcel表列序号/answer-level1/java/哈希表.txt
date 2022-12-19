### 解题思路
先用哈希表把所有的字母的值存储起来，然后找到数学关系进行运算就可以了。

### 代码

```java
class Solution {
    public int titleToNumber(String s) {
        HashMap<Character, Integer> hashmap = new HashMap<>();
        hashmap.put('A', 1);hashmap.put('B', 2);hashmap.put('C', 3);hashmap.put('D', 4);
        hashmap.put('E', 5);hashmap.put('F', 6);hashmap.put('G', 7);hashmap.put('H', 8);
        hashmap.put('I', 9);hashmap.put('J', 10);hashmap.put('K', 11);hashmap.put('L', 12);
        hashmap.put('M', 13);hashmap.put('N', 14);hashmap.put('O', 15);hashmap.put('P', 16);
        hashmap.put('Q', 17);hashmap.put('R', 18);hashmap.put('S', 19);hashmap.put('T', 20);
        hashmap.put('U', 21);hashmap.put('V', 22);hashmap.put('W', 23);hashmap.put('X', 24);
        hashmap.put('Y', 25);hashmap.put('Z', 26);

        int res = 0;
        char[] chars = s.toCharArray();

        for(int i = chars.length - 1, j = 0; i >= 0; i--, j++){
            res = res + (int)Math.pow(26, j)*hashmap.get(chars[i]);
        }
        return res;
    }
}
```