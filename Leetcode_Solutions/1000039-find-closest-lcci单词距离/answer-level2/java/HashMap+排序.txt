### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
      
 
    public int findClosest(String[] words, String word1, String word2) {
        HashMap<String,List<Integer>> map = new HashMap<>();
        for(int i = 0;i<words.length;i++){
            map.put(words[i],map.getOrDefault(words[i],new ArrayList<>()));
            map.get(words[i]).add(i);
        }
        List<Integer> list = map.get(word1);
        List<Integer> list1 = map.get(word2);
        Collections.sort(list);
        Collections.sort(list1);
        int res = Integer.MAX_VALUE;
        int index1 = 0;
        int index2 = 0;
        while(index1<list.size()&&index2<list1.size()){
            if(list.get(index1)<list1.get(index2)){
                if(res>(list1.get(index2)-list.get(index1))){
                    res = (list1.get(index2)-list.get(index1));
                }
                index1++;
            }else {
                if(res>(list.get(index1)-list1.get(index2))){
                    res = (list.get(index1)-list1.get(index2));
                }
                index2++;
            }
        }
        return res;
    }
    
}
```