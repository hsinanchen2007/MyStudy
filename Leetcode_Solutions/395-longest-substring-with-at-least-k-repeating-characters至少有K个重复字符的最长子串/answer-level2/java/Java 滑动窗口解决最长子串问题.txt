### 解题思路
此处撰写解题思路
     *  使用滑动窗口来解决
     *  使用两个指针，  start指向子传开始位置， complete 指向结束位置（必须是一个符合条件的子传）
     *  临时子串，保存当前正在检验的子串
     *  destList， 满足条件的子串列表
     *
     *  一开始start和complete都指向首字符
     *  检查当前字符出现次数是否大于等于k
     *      -  若满足，则将该字符放入临时子串
     *          -  然后检查临时子串是否符合要求
     *              - 符合，则将临时子串放入 destList中, 同时记录complete的位置
     *  若小于K 或  当前到达字符串尾部
     *      -  则返回到上次complete的地方重新检查
     *  返回destList中最长的子串的长度

### 代码

```java
class Solution {
  public  static int longestSubstring(String s, int k) {
        Map<String, Long> charMap = Stream.of(s.split("")).collect(Collectors.groupingBy(e->e, Collectors.counting()));
        char[] array = s.toCharArray();
        List<String> destList = new ArrayList<>();

        int start = 0;
        int complete = 0;
        Map<String, Long> tmpMap = new HashMap<>();
        for (int i = 0; i < s.length(); i++){
            if (charMap.get(String.valueOf(array[i])) >= k) {
                if (checkTmpMap(tmpMap, String.valueOf(array[i]), k)){
                    complete = i;
                    destList.add(String.valueOf(array, start, complete - start +1));
                }else {
                    if (i == s.length()-1){
                        i = complete;
                        start = i+1;
                        complete = start;
                        tmpMap.clear();
                    }
                }
            }else {
                if (complete != start){
                    destList.add(String.valueOf(array, start, complete - start +1));
                }

                i = complete;

                start = i + 1;
                complete = start;
                tmpMap.clear();
            }
        }

        if (destList.isEmpty()){
            return 0;
        }

        String dest = destList.stream().max(Comparator.comparing(String::length)).orElse("");

        return dest.length();
    }

    private static boolean checkTmpMap(Map<String, Long> tmpMap, String cur, int count){
        if (tmpMap.get(cur) == null){
            tmpMap.put(cur, 1L);
        }else {
            Long v = tmpMap.get(cur);
            v += 1;
            tmpMap.put(cur,v);
        }
        return tmpMap.values().stream().allMatch(e->e >= count);
    }
}
```