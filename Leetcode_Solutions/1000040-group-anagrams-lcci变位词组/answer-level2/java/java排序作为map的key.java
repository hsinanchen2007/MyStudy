### 解题思路
1. 循环传入的数组，将数组中的每个元素进行字符串排序
2. 将排序后的字符串作为map的key，原始字符串放入list作为map的value
3. 每次排序后判断该字符串是否在map中存在，如果存在将map的list取出来添加str，如果不存在，新建一个list添加str后放入map
### 代码

```java
class Solution {
   public List<List<String>> groupAnagrams(String[] strs) {

        if (strs == null || strs.length == 0) {
            return null;
        }

        Map<String, List<String>> map = new HashMap<>();

        for (String str : strs) {
            String sortStr = this.sort(str);
            if (map.containsKey(sortStr)) {
                map.get(sortStr).add(str);
                continue;
            }

            ArrayList<String> list = new ArrayList<>();
            list.add(str);
            map.put(sortStr, list);
        }

        List<List<String>> list = new ArrayList<>();
        map.forEach((key, value) -> {
            list.add(value);
        });
        return list;
    }

    // 字符串排序
    private String sort(String str) {
        if (str == null && str.length()==0) {
            return "";
        }

        char[] chars = str.toCharArray();
        Arrays.sort(chars);

        StringBuffer sb = new StringBuffer();
        for (char aChar : chars) {
            sb.append(aChar);
        }
        return sb.toString();

    }

}
```