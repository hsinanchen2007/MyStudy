### 解题思路
先用哈希表存储基础罗马数字，当罗马数字中小的数字在大的数字的右边，就做加法，否则做减法。注意处理最后一个数字。
### 代码

```java
class Solution {
    public int romanToInt(String s) {
        HashMap<Character,Integer> map = new HashMap(){
            {
                put('I',1);
                put('V',5);
                put('X',10);
                put('L',50);
                put('C',100);
                put('D',500);
                put('M',1000);
            }
        };
        int sum = 0;
        int len = s.length();
        for(int i = 1; i < len;i++){
            int cur = map.get(s.charAt(i));
            int pre = map.get(s.charAt(i - 1));
            sum += cur > pre ? -pre : pre;
        }
        sum += map.get(s.charAt(len - 1));
        return sum;
    }
}
```