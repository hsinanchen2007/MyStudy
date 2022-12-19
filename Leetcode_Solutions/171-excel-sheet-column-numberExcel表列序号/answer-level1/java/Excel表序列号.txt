### 解题思路


### 代码

```java
class Solution {
    public int titleToNumber(String s) {
        HashMap<String, Integer> hashmap = new HashMap<>();
        hashmap.put("A", 1);hashmap.put("B", 2);hashmap.put("C", 3);hashmap.put("D", 4);
        hashmap.put("E", 5);hashmap.put("F", 6);hashmap.put("G", 7);hashmap.put("H", 8);
        hashmap.put("I", 9);hashmap.put("J", 10);hashmap.put("K", 11);hashmap.put("L", 12);
        hashmap.put("M", 13);hashmap.put("N", 14);hashmap.put("O", 15);hashmap.put("P", 16);
        hashmap.put("Q", 17);hashmap.put("R", 18);hashmap.put("S", 19);hashmap.put("T", 20);
        hashmap.put("U", 21);hashmap.put("V", 22);hashmap.put("W", 23);hashmap.put("X", 24);
        hashmap.put("Y", 25);hashmap.put("Z", 26);

        StringBuilder sb = new StringBuilder(s);
        char[] chars = sb.reverse().toString().toCharArray();
        int res = 0;

        for(int i = 0; i < chars.length; i++){
            res = (hashmap.get(new Character(chars[i]).toString())) * (int)Math.pow(26, i) + res;
        }
        return res;
    }
}
```