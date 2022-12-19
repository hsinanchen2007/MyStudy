回文串，首先很明显看到需要回文得字母出现次数必然是偶数，在偶数之外，如果存在1个以上奇数，就可以加1个奇数次数得字母进来。所以只需要遍历一次字符串所有字符，用Hash统计所有字符出现得次数，当任一个字母出现次数达到2得倍数得时候，结果长度加2。在统计偶数次数同时，记录一个奇数标识，每当奇数次数出现时加1，偶数出现后-1。一次遍历完就可以得出长度。

```
public static int isRectangleOverlap(String s) {
    HashMap<String, Integer> count = new HashMap<>();
    int result = 0;
    int extra = 0;
    for (String t :  s.split("")) {
        if (count.containsKey(t)) {
            int c = count.get(t) + 1;
            count.put(t, c);
            if (c % 2 == 0) {
                result += 2;
                extra -= 1;
            } else {
                extra += 1;
            }
        } else {
            count.put(t, 1);
            extra += 1;
        }
    }
    return extra > 0 ? result + 1 : result;
}
```
