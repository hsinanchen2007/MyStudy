***我的[leetcode解题集](https://github.com/JuiceZhou/Leetcode)，持续更新。***

创建一个Map储存Pairs的对应关系，因为同一个词可能出现多个对应词，所以使用Map<String,List<String>>来保存。注意两个单词的对应关系都需要保存，比如["great","fine"]保存为=>great->fine和fine->great。

这里还需要注意一点是相同的单词也为对应关系，


```
 public boolean areSentencesSimilar(String[] words1, String[] words2, List<List<String>> pairs) {
        if(words1.length != words2.length) return false;
        Map<String,List<String>> map = new HashMap<>();
        if(!pairs.isEmpty()){
            for(List<String> pair : pairs){
                List<String> val1 = map.get(pair.get(0));
                if(val1 == null) val1 = new ArrayList<>();
                val1.add(pair.get(1));
                map.put(pair.get(0),val1);
                List<String> val2 = map.get(pair.get(1));
                if(val2 == null) val2 = new ArrayList<>();
                val2.add(pair.get(0));
                map.put(pair.get(1),val2);
            }
        }

        //2.逐一比较两个单词
        for(int i = 0;i < words1.length;i++){
            //相等的单词也是对应词
            if(words1[i].equals(words2[i]))
                continue;
            if(!map.isEmpty()){
                //获取对应的词
                List<String> list = map.get(words1[i]);
                if(list == null  || !list.contains(words2[i]))
                    return false;
            }
        }
        return true;
}
```