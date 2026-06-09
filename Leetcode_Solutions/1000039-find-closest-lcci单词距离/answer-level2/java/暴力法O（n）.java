### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findClosest(String[] words, String word1, String word2) {
        Map<String, List<Integer>> map=new HashMap<>();
        for (int i=0;i<words.length;i++){
            if (map.containsKey(words[i])){
                List<Integer> mid=map.get(words[i]);
                mid.add(i);
                map.put(words[i],mid);
            }
            else{
                List<Integer> mid=new ArrayList<>();
                mid.add(i);
                map.put(words[i],mid);
            }
        }
        List<Integer> w1=map.get(word1);//记录第一个单词的所有位置
        List<Integer> w2=map.get(word2);//记录第二个单词的所有位置
        int i=0;//第一个单词的位置索引
        int j=0;//第二个单词的位置索引
        int min=Math.abs(w1.get(0)-w2.get(0));
        while(i<w1.size() && j<w2.size()){
            int gap=w1.get(i)-w2.get(j);
            if (Math.abs(gap)<min)
                min=Math.abs(gap);
            if (gap>=0)
                j++;
            else
                i++;
        }
        return min;
    }
}
```