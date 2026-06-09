首先打表，获取26个字母的对应莫斯密码表，对于每一个单词，通过 StringBuilder 转化每一个单词，
再判断list中是否有这样的字符串，如果没有就添加，最后list的大小即为最终的答案。

```
class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String[] target = new String[]{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        List<String> list = new ArrayList<>();
        for(String word : words){
            StringBuilder sb = new StringBuilder();
            for(int i = 0;i < word.length();i++){
                sb.append(target[word.charAt(i) - 'a']);
            }
            if(list.contains(sb.toString()) == false) list.add(sb.toString());
        }
        return list.size();
    }
}
```
