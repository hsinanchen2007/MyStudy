找寻字典里面只有一个字母不一样的单词，可以考虑使用map暴力解决，**key为单词长度，value就是同一长度的单词集合**，遍历集合就行。

```java
public class MagicDictionary {
    private HashMap<Integer, ArrayList<String>> wordMap;

    public MagicDictionary() {
        wordMap = new HashMap();
    }

    public void buildDict(String[] words) {
        for (String word : words) {
            wordMap.computeIfAbsent(word.length(), s -> new ArrayList()).add(word);
        }
    }

   public boolean search(String word){
       int length = word.length();
       List<String> sameLenList = wordMap.get(length);
       if (sameLenList == null || sameLenList.size() <= 0) {
           return false;
       }
       for (String s : sameLenList) {
           if (s.equals(word)) {
               continue;
           }
           int unSameCharNum = 0;
           for (int i = 0; i < length; i++) {
               if (unSameCharNum > 1) {
                   break;
               }
               if (word.charAt(i) != s.charAt(i)) {
                   unSameCharNum++;
               }
           }
           if (unSameCharNum == 1) {
               return true;
           }
       }
       return false;
   }

}

```