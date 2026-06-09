### 解题思路
暴力法

### 代码

```java
class Solution {
    public String sortString(String s) {
        char[] arr = s.toCharArray();
        TreeMap<Character, Integer> map = new TreeMap<>();
        for (char c : arr)
            map.put(c, map.getOrDefault(c, 0) + 1);
        StringBuilder sb = new StringBuilder();
        //拼接 如果所有的字符都用到了则停止循环
        boolean flag = true;
        while (flag){
            flag = false;
            for (char c : arr) {
                if(map.get(c)!=0) {
                    flag = true;
                    sb = appendChar(sb,map);
                }
            }
        }
        return sb.toString();
    }

    private StringBuilder appendChar(StringBuilder sb, TreeMap<Character, Integer> map) {
        // 从到大
        StringBuilder desc = new StringBuilder();
        for (Character key : map.keySet()) {
            Integer val = map.get(key);
            if(val!=0){
                sb.append(key);
                map.put(key,--val);
            }
        }
        for (Character key : map.keySet()) {
            Integer val = map.get(key);
            if(val!=0){
                desc.append(key);
                map.put(key,--val);
            }
        }
        sb.append(desc.reverse());
        return sb;
    }
}
```