### 解题思路
此处撰写解题思路
分析字母发现根据g,u,w,x,z可以唯一确定数字84260，
然后再根据s,v,o,t,i,针对于已知，推断未知解方程，得出，7，5，1，3，9，

### 代码

```java
class Solution {
    public String originalDigits(String s) {
     StringBuilder stringBuilder = new StringBuilder();

        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < 10; i++) {
            map.put(i, 0);
        }
        Map<Character, Integer> map2 = new HashMap<>();
        map2.put('s', 0);
        map2.put('v', 0);
        map2.put('o', 0);
        map2.put('t', 0);
        map2.put('i', 0);
        String[] a = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

        char[] chars = s.toCharArray();

        for (int i = 0; i < chars.length; i++) {
            char aChar = chars[i];
            if (aChar == 'g') {
                map.put(8, map.get(8)+1);
            } else if (aChar == 'u') {
                map.put(4, map.get(4)+1);
            } else if (aChar == 'w') {
                map.put(2, map.get(2)+1);
            } else if (aChar == 'x') {
                map.put(6, map.get(6)+1);
            } else if (aChar == 'z') {
                map.put(0, map.get(0)+1);
            } else if (aChar == 's') {
                map2.put('s', map2.get('s')+1);
            } else if (aChar == 'v') {
                map2.put('v', map2.get('v')+1);
            } else if (aChar == 'o') {
                map2.put('o', map2.get('o')+1);
            } else if (aChar == 't') {
                map2.put('t', map2.get('t')+1);
            } else if (aChar == 'i') {
                map2.put('i', map2.get('i')+1);
            }
        }
        Integer s1 = map2.get('s');
        map.put(7, s1 - map.get(6));
        Integer s2 = map2.get('v');
        map.put(5, s2 - map.get(7));
        Integer s3 = map2.get('o');
        map.put(1, s3 - map.get(0) - map.get(2) - map.get(4));

        Integer s4 = map2.get('t');
        map.put(3, s4 - map.get(2)-map.get(8));
        Integer s5 = map2.get('i');
        map.put(9, s5 - map.get(5) - map.get(6) - map.get(8));
        for (Integer integer : map.keySet()) {
            Integer value = map.get(integer);
            if (value != 0) {
                for (int i = 0; i < value; i++) {
                    stringBuilder.append(integer);
                }
            }
        }
        return stringBuilder.toString();
    }
}
```