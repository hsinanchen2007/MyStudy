### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    static Map<Integer, String> map = new HashMap<Integer, String>()
    {
        {
            put(1, "I");
            put(5, "V");
            put(10, "X");
            put(50, "L");
            put(100, "C");
            put(500, "D");
            put(1000, "M");

        }
    };

    public String intToRoman(int num) {
        int mos = 1;
        StringBuilder val = new StringBuilder();
        while (num > 0) {
            int pop = num % 10;
            if (pop < 4) {
                while (pop>0) {
                    pop--;
                    val.insert(0, map.get(mos));
                }
            }else if (pop == 4) {
                val.insert(0, map.get(mos)+map.get(5 * mos));
            }else if (pop == 5) {
                val.insert(0, map.get(5 * mos));
            }else if (pop == 6) {
                val.insert(0, map.get(5 * mos) + map.get(mos));
            }else if (pop <9) {
                String tmp = map.get(5 * mos);
                while (pop - 5>0) {
                    pop--;
                    tmp = tmp + map.get(mos);
                }
                val.insert(0, tmp);
            }else if (pop == 9) {
                val.insert(0, map.get(mos) + map.get(10 * mos));
            }
            mos *= 10;
            num /= 10;
        }
        return val.toString();
    }
}
```