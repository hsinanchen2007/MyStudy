### 解题思路
从高位到低位依次转换数字为罗马字
转换成功后，原来的数值高位舍去，继续转换剩下的数值

### 代码

```java
class Solution {
    public String intToRoman(int num) {
        if(num < 1 || num > 3999) {
            return "";
        }
        Map<Integer, String> map = new LinkedHashMap<>();

        map.put(1000, "M");
        map.put(500, "D");
        map.put(100, "C");
        map.put(50, "L");
        map.put(10, "X");
        map.put(5, "V");
        map.put(1, "I");
        StringBuilder builder = new StringBuilder();

        int bit = 1000;
        while (bit >= 1) {
            String roman = getHighRoman(num, bit, map);
            if (!roman.isEmpty()) {
                builder.append(roman);
                num %= bit; //转换最高位成功后，将最高位去掉，继续转换下面的数字
            }
            bit /= 10; //进位向下移动一格
        }

        return builder.toString();

    }

    /**
     * 把最高位数字转换为罗马数字返回
     * @param num 数值
     * @param bit 进位 个位1 十位10 百位100 千位 1000
     * @param map 罗马数字映射map
     * @return
     */
    private String getHighRoman(int num, int bit, Map<Integer, String> map) {
        StringBuilder builder = new StringBuilder();
        int mCount = num / bit;
        while(mCount > 0) {
            if(mCount < 4) { //小于4的情况 直接拼接
                for(int i = 0; i < mCount; i++) {
                    builder.append(map.get(bit));
                }
                mCount = 0;
            } else if(mCount == 4) { //等于4的情况 
                builder.append(map.get(bit)).append(map.get(bit * 5));
                mCount = 0;
            } else if(mCount > 4 && mCount < 9) { //大于4小于9的情况 先把5拼接，然后继续循环
                builder.append(map.get(bit* 5));
                mCount -= 5;
            } else { //等于9的情况
                builder.append(map.get(bit)).append(map.get(bit * 10));
                mCount = 0;
            }
        }

        return builder.toString();
    }
}
```