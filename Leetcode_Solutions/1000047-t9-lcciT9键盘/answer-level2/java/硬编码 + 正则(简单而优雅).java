# 思路
方案1：将`num`转为正则表达式，去匹配每个`word`。
正则表达式匹配`word`的**每个字符**时，要判断3次或4次(`3`次就如`[a-c]`，`4`次就如`[w-z]`)，
可以理解为每个字符判断都形如：`if(ch == 'a' || ch == 'b' || ch == 'c')`。
方案1优点是**代码简洁**，缺点是**速度慢**。

方案2：将每个`word`映射为`num`，再与`num`匹配。这样与`num`的**每个字符**比较时只需要判断1次，
形如`if(ch == '1')`。
方案2的优点是**速度快**，缺点是**代码长**。
# 代码
```java [-方案1]
class Solution {
    public List<String> getValidT9Words(String num, String[] words) {
        String[] pattern_arr = new String[]{"[a-c]", "[d-f]", "[g-i]", "[j-l]", "[m-o]", "[p-s]", "[t-v]", "[w-z]"};
        int len = num.length();
        StringBuilder sb = new StringBuilder(len * 5);
        for (int i = 0; i < len; ++i)
            sb.append(pattern_arr[num.charAt(i) - '2']);
        LinkedList<String> res = new LinkedList<>();
        String pattern = sb.toString();
        for (String word : words)
            if (word.matches(pattern))
                res.addLast(word);
        return res;
    }
}
```
```java [-方案2]
class Solution {
    public List<String> getValidT9Words(String num, String[] words) {
        HashMap<Character, Character> map = new HashMap<>(26);
        map.put('a', '2');
        map.put('b', '2');
        map.put('c', '2');

        map.put('d', '3');
        map.put('e', '3');
        map.put('f', '3');

        map.put('g', '4');
        map.put('h', '4');
        map.put('i', '4');

        map.put('j', '5');
        map.put('k', '5');
        map.put('l', '5');

        map.put('m', '6');
        map.put('n', '6');
        map.put('o', '6');

        map.put('p', '7');
        map.put('q', '7');
        map.put('r', '7');
        map.put('s', '7');

        map.put('t', '8');
        map.put('u', '8');
        map.put('v', '8');

        map.put('w', '9');
        map.put('x', '9');
        map.put('y', '9');
        map.put('z', '9');
        LinkedList<String> res = new LinkedList<>();
        search:
        for (String word : words) {
            int idx = 0;
            for (char c : word.toCharArray())
                if (map.get(c) != num.charAt(idx++))
                    continue search;
            res.addLast(word);
        }
        return res;
    }
}
```
