大众解法：

1、遍历字符串，数每一个字符的个数，并放入到map中。
2、对map按照value进行降序排序。
3、组装成新的字符串。

```
import java.util.*;
/**
 * 451. 根据字符出现频率排序
 *
 * @author xiaocuner
 * @since 2020-3-4
 */
public class FrequencySort451 {
    public String frequencySort(String s) {
        int len = s.length();
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < len; i++) {
            char ch = s.charAt(i);
            if (map.containsKey(ch)) {
                map.put(ch, map.get(ch) + 1);
            } else {
                map.put(ch, 1);
            }
        }

        // 对map进行排序
        List<Map.Entry<Character, Integer>> list = new ArrayList<>(map.entrySet());
        Collections.sort(list, (a, b) -> b.getValue() - a.getValue());

        StringBuilder sb = new StringBuilder();
        for (Map.Entry<Character, Integer> obj : list) {
            Integer count = obj.getValue();
            Character ch = obj.getKey();
            for (int i = 0; i < count; i++) {
                sb.append(ch);
            }
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        FrequencySort451 ins = new FrequencySort451();
        System.out.println(ins.frequencySort("tree"));
        System.out.println(ins.frequencySort("cccaaa"));
        System.out.println(ins.frequencySort("Aabb"));
    }
}
```

