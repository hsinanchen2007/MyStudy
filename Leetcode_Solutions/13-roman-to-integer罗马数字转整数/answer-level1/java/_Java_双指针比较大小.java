### 解题思路
1. 将罗马数字-阿拉伯数字对应关系存入字段中，可以用map
2. 判断字符串以及字符的正确性
3. 使用两个指针指向当前位以及前一位，使用两个临时变量存储当前组数以及总数
4. 按位查询对应字典，规则如下
- 如果当前数与前一位数值相同，则当前组 = 当前组 + 当前位
- 如果当前数大于前一位数，则当前组 = 当前位 - 当前组
- 如果当前述小于前一位数，证明当前组计算完毕。则总数 = 总数 + 当前组，当前组重新计算，即当前组 = 当前位
5. 累加当前组至总数
### 代码

```java
class Solution {

        Map<Character, Integer> dictionary;
        {
            dictionary = new HashMap<>();
            dictionary.put('I', 1);
            dictionary.put('V', 5);
            dictionary.put('X', 10);
            dictionary.put('L', 50);
            dictionary.put('C', 100);
            dictionary.put('D', 500);
            dictionary.put('M', 1000);
        }


        public int romanToInt(String s) {
            if (s == null && "".equals(s)) throw new IllegalArgumentException("字符串为空");
            // 记录前一位数值，当前数值
            // 记录当前组数值，总数值
            int pre = 0, cur, group = 0, total = 0;
            for (Character c: s.toCharArray()) {
                if (!dictionary.containsKey(c)) throw new IllegalArgumentException("字典错误");
                cur = dictionary.get(c);
                if (cur == pre) {
                    group += cur;    // 累加当前组
                } else if (cur > pre) {
                    group = cur - group;  // 当前组 = 当前位 - 当前组，例如IV，原当前组=1，现当前组= 4 - 1 = 3 
                } else {
                    total += group;  // 总值累加
                    group = cur; // 重新计算当前组
                }
                pre = cur;  // 指针移动
            }
            total += group;  // 总值累加
            return total;
        }
    }
```