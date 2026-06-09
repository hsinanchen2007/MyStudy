思路: 先用判断能否构成回文序列,不可以就直接返回空数组
     可以的话看回文序列长度是否为奇数,为奇数的话把奇数字符查出来,
     然后在map中把这个key对应个数减1,为偶数的话就不管
     由于回文序列是两边对称的,所以我只计算一边的全排列,计算
     完了之后再加上他的反序列即可,当然，有奇数字符就把它加到中间。

代码如下:
```
class Solution {
    public List<String> generatePalindromes(String s) {

        if (s.length() == 0) {
            return new ArrayList<>();
        }
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0) + 1);
        }
        int count = 0;
        int size = 0;
        Character ch = null;
        for (char key : map.keySet()) {
            if (map.get(key) % 2 == 1) {
                ch = key;
                count += 1;
                map.put(key, map.get(key) - 1);
            }
            size += map.get(key) / 2;
        }

        if (count > 1) {
            return new ArrayList<>();
        }

        char[] chars = new char[size];
        int i = 0;
        for (char key : map.keySet()) {
            for (int j = 0; j < map.get(key) / 2; j++) {
                chars[i++] = key;
            }
        }

        boolean[] visited = new boolean[size];
        List<String> resultList = new ArrayList<>();
        dfs(chars, visited, new StringBuilder(), resultList, ch);

        return resultList;

    }

    private void dfs(char[] chars, boolean[] visited, StringBuilder sb,
                     List<String> resultList, Character ch) {

        if (sb.length() == chars.length) {
//            String reverse = "";
//            for (int i = tmp.length() - 1; i >= 0; i--) {
//                reverse += tmp.charAt(i);
//            }
            StringBuilder tmp = new StringBuilder(sb.toString());
            String reverse = new StringBuilder(sb.toString()).reverse().toString();
            resultList.add(ch == null ? tmp.append(reverse).toString() : tmp.append(ch).append(reverse).toString());
            return;
        }

        for (int i = 0; i < chars.length; i++) {
            if (visited[i]) {
                continue;
            } else {
                if (i > 0 && chars[i] == chars[i - 1] && !visited[i - 1]) {
                    continue;
                }
                sb.append(chars[i]);
                visited[i] = true;
                dfs(chars, visited, sb, resultList, ch);
                sb.deleteCharAt(sb.length() - 1);
                visited[i] = false;
            }
        }
    }

}
```
