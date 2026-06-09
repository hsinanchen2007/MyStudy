【想法】
     （1）将所给字符按照ASCII值 - a的ASCII为下标进行记录，数值作为数量的记录
     （2）遍历所需要计算的字符串数组，找到相关字母所对应的索引进行--并判断是否>0，进行计数
     （3）判断计数器是否与该字符串的长度相同，相同即为可以组成该单词，则进行最终计数器++操作

```
class Solution {
    public int countCharacters(String[] words, String chars) {
        char[] target = chars.toCharArray();
        int[] temp = new int[26];
        int result = 0;
        for (char c : target) {
            temp[c - 'a']++;
        }
        for (String word : words) {
            char[] src = word.toCharArray();
            int one = 0;
            int[] t = temp.clone();
            for (char c : src) {
                if(t[c - 'a']-- > 0){
                    one++;
                }
            }
            if (one == word.length()){
                result += one;
            }
        }
        return result;
    }
}
```
