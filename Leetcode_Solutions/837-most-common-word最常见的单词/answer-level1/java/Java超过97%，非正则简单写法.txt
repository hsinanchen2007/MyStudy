## 解题思路：
1. 遍历paragraph字符串，使用双指针记录两个相邻非字母字符的下标。
2. 这两个指针之间即为一个单词。
3. 判断此单词是否在banned数组中。存在则继续遍历，不存在则增加map中以该单词为的key的元素的value。
4. 增加map中元素的value时，判断是否为最大value，避免了再次遍历求最大值。

## 要点：
- 先将banned数组转为Set类型，便于之后查询单词是否在banned中。
- Set中要加入空字符串""，以排除连续非字母字符的情况。
- paragraph字符串末尾需补加一个非字母字符，这样可简化逻辑。

## 代码及注释：
```Java
class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        //数组转Set
        Set<String> set = new HashSet<>(Arrays.asList(banned));
        set.add("");
        paragraph += ".";
        //结果单词
        String res = " ";
        //最大单词出现次数
        int times = 0;
        //记录单词出现次数的map
        Map<String, Integer> map = new HashMap<>();
        //i,k为双指针
        int i = 0;
        for (int k = 0; k < paragraph.length(); k++) {
            char c = paragraph.charAt(k);
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                continue;
            } else {
                //利用双指针截取出一个单词
                String word = paragraph.substring(i, k);
                //统一将单词转为小写
                word = word.toLowerCase();
                if (!set.contains(word)) {
                    map.put(word, map.getOrDefault(word, 0) + 1);
                    //最大值的获取
                    if (map.get(word) > times) {
                        res = word;
                        times = map.get(word);
                    }
                }
                i = k + 1;
            }
        }
        return res;
    }
}
```