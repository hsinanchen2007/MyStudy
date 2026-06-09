思路：先用哈希表存放所给出数组的单词以及出现次数，之后将HashMap进行排序（注意题目要求，**在出现次数相同时，需要按照单词字典序升序进行排序**）
最后将值符合要求的键存入 List<String> 中并返回即可。

```
import java.util.Map.Entry;

class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        List<String> list = new ArrayList<>();
        HashMap<String,Integer> map = new HashMap<>();
        for(int i = 0;i < words.length;i++) {
            map.put(words[i],map.getOrDefault(words[i],0) + 1);
        }
        List<Map.Entry<String,Integer>> res = new ArrayList<>(map.entrySet());
        Collections.sort(res,new Comparator<Map.Entry<String,Integer>>() {
	    public int compare(Entry<String, Integer> o1, Entry<String, Integer> o2) {
                if(o1.getValue() != o2.getValue()) return o1.getValue() - o2.getValue();
                else {
                    return o2.getKey().compareTo(o1.getKey());
                }
	    }
        });
        //System.out.println(res);
        for(int i = map.size() - 1;i >= map.size() - k;i--) {
            list.add(res.get(i).getKey());
        }
        map.clear();
        return list;
    }
}
```
