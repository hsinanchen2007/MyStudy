### 分析
新建一个Map<String, List<String>> map，key为单词中每个字母出现的次数组成的字符串，value为包含相对应字符的字符串list。本题有两种解法。
1、第一种统计每个单词中字母出现的次数。比如eat和aet我们都会统计出a1,e1,t1。 在map中，这种会被当做统一的key，即a1e1t1。对于strs = {"eat", "tea", "tan", "ate", "nat", "bat"}，我们会统计出如下的map。
{a1b1t1=[bat], a1n1t1=[tan, nat], a1e1t1=[eat, tea, ate]}。map的value即为我们所求。
2、第二种将每个单词按照字母表顺序排序。比如eat，aet排序好以后都是aet。遍历原数组，取出每个单词按字母表排序后的结果。将其加入map。对于strs = {"eat", "tea", "tan", "ate", "nat", "bat"}，我们会统计出如下的map。{aet=[eat, tea, ate], abt=[bat], ant=[tan, nat]}。map的value即为我们所求。
### 代码
```java
public List<List<String>> groupAnagrams1(String[] strs) {
        if (strs == null || strs.length == 0) {
            return new ArrayList<>();
        }
        Map<String, List<String>> map = new HashMap<>();
        for (String str : strs) {
            int[] table = new int[26];
            for (int i = 0; i < str.length(); i++) {
                table[str.charAt(i) - 'a']++;
            }
            StringBuffer keySb = new StringBuffer();
            for (int i = 0; i < 26; i++) {
                if(table[i] == 0){
                    continue;
                }
                keySb.append((char)('a'+i)).append(table[i]);
               // keySb.append(table[i] + "#");
            }
            String key = keySb.toString();
            if (map.containsKey(key)) {
                map.get(key).add(str);
            } else {
                List<String> list = new ArrayList<>();
                list.add(str);
                map.put(key, list);
            }
        }

        return new ArrayList<>(map.values());

    }
	
	public List<List<String>> groupAnagrams2(String[] strs) {
        if (strs == null || strs.length == 0) {
            return new ArrayList<>();
        }
        Map<String, List<String>> map = new HashMap<>();
        for (String str : strs) {
            char[] chars = str.toCharArray();
            Arrays.sort(chars);
            String key = String.valueOf(chars);
            if (map.containsKey(key)) {
                map.get(key).add(str);
            } else {
                List<String> list = new ArrayList<>();
                list.add(str);
                map.put(key, list);
            }
        }
        return new ArrayList<List<String>>(map.values());
```