感觉就是在调用API。。。
```java
class Solution {
    public String[] findWords(String[] words) {
        String[] dicts = new String[] {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        List<String> res = new ArrayList<>();
        for(String word : words) {
            String myDict = "";
            //找到合适的字典
            for(String dict : dicts) {
                if(dict.indexOf(Character.toLowerCase(word.charAt(0))) != -1) {
                    myDict = dict;
                    break;
                }
            }
            char[] wordArr = word.toCharArray();
            //案例中会出现中间的字母是大写的情况，同一将大写字母转化为小写
            for(int i = 0; i < wordArr.length; i++) {
                if(myDict.indexOf(Character.toLowerCase(wordArr[i])) == -1) break;
                if(i == wordArr.length - 1 && myDict.indexOf(Character.toLowerCase(wordArr[i])) != -1) {
                    res.add(word);
                }
            }
        }
        return res.toArray(new String[res.size()]);
    }
}
