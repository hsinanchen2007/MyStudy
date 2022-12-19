### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<Integer> diffWaysToCompute(String input) {
        // 利用该 map 来记录重复的计算结果
        Map<String, List<Integer>> map = new HashMap<>();
        return compute(input, map); 
    }
    
    private List<Integer> compute(String input, Map<String, List<Integer>> map) {
        // 查询 map, 如果存在 input, 就直接返回对应的结果
        if (map.containsKey(input)) {
            return map.get(input);
        }
        List<Integer> result = new LinkedList<>();
        for(int i = 0; i < input.length();i++) {
            char c = input.charAt(i);
            // 遇到运算符就进行分割, 没有遇到运算符, 那么就是连续数字, 分割没有意义
            if (c == '-' || c == '+' || c == '*') {
                // 用两个 list 来存放该运算符左右两边的结果
                List<Integer> left = compute(input.substring(0, i), map);
                List<Integer> right = compute(input.substring(i + 1), map);
                // 遍历两个 list 来取出所有的结果.
                for(int l : left) {
                    for(int r : right) {
                        if (c == '-') {
                            result.add(l - r);
                        } else if (c == '+') {
                            result.add(l + r);
                        } else {
                            result.add(l * r);
                        }
                    }
                }
            }
        }
        // 如果 result 长度为 0 , 那么就是没有遇到一个运算符, 说明是一连串的数字
        if (result.size() == 0) {
            result.add(Integer.valueOf(input));
        }
        // map 中不存在就放进去
        if (!map.containsKey(input)) {
            map.put(input, result);   
        }
        return result;
    }
}
```