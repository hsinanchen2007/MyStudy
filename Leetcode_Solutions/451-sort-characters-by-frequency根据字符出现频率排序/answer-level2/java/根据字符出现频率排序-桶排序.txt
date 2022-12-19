```java
class Solution {
    public String frequencySort(String s) {
        // 1.找出每个字符和它出现的频率，放到Hashmap中
        HashMap<Character, Integer> hashmap = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            if (hashmap.get(s.charAt(i)) == null) {
                hashmap.put(s.charAt(i), 1);
            } else {
                hashmap.put(s.charAt(i), hashmap.get(s.charAt(i)) + 1);
            }
        }

        // 2.将出现频率和对应的字符放到对应的数组列表中，数组的索引对应出现的频率，索引对应的列表对应该频率对应的字符
        List<Character>[] freqEles = new ArrayList[s.length() + 1];
        for (char key : hashmap.keySet()) {
            Integer freq = hashmap.get(key);
            if (freqEles[freq] == null) {
                freqEles[freq] = new ArrayList<>();
            }
            freqEles[freq].add(key);
        }
        // 3.根据出现的频率和对应的字符，生成最后的结果列表
        StringBuilder sb = new StringBuilder();
        for (int i = freqEles.length - 1; i >= 0; i--) {
            if (freqEles[i] == null) {
                continue;
            }
            List<Character> eles = freqEles[i];
            for (Character ele : eles) {
                for (int j = 0; j < i; j++) {
                    sb.append(ele);
                }
            }
        }
        return sb.toString();
    }
}
```