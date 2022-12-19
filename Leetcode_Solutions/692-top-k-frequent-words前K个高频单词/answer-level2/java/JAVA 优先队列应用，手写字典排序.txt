一开始不知道String的compareTo是不是符合要求的所以没用，后来发现手写的比较方法还更快点
步骤是先构建单次出场次数的哈希表
遍历一边单词O(n)
之后建立符合题目规则的大顶堆使用优先队列，重写比较方法
假设有N个单词，每个单词插入大顶堆的时间复杂度是logk次
总时间复杂度是 **O(n) + O(N*logk) + O(k) = O(N*logk)**
空间复杂度是单词最大数 O(n);

7ms 99.3%
```
class Solution {
    public List<String> topKFrequent(String[] words, int k) {

        HashMap<String,Integer> map = new HashMap();
        for(String word: words){
            map.put(word,map.getOrDefault(word,0)+1);
        }
        
        PriorityQueue<String> heap = new PriorityQueue(new Comparator<String>(){
            @Override
            public int compare(String a,String b){
                return map.get(b).equals(map.get(a)) ? alphOrder(a,b):(map.get(b)-map.get(a));
            }
        });

        for(String word:map.keySet()){
            heap.add(word);
        }

        List<String> ans = new ArrayList();
        for(int i=0;i<k;i++){
            if(!heap.isEmpty()){
                ans.add(heap.poll());
            }else{
                break;
            }
        }
        return ans;
    }

    public int alphOrder(String a,String b){
        int i=0;
        while(i<a.length() && i<b.length()){
            if(a.charAt(i) - b.charAt(i) == 0 ){
                i++;
                continue;
            }else{
                return a.charAt(i) - b.charAt(i);
            }
        }
        return a.length()-b.length();
    }
    
}
```

13ms  15%
```
class Solution {
    public List<String> topKFrequent(String[] words, int k) {

        HashMap<String,Integer> map = new HashMap();
        for(String word: words){
            map.put(word,map.getOrDefault(word,0)+1);
        }
        
        PriorityQueue<String> heap = new PriorityQueue(new Comparator<String>(){
            @Override
            public int compare(String a,String b){
                return map.get(b).equals(map.get(a)) ? a.compareTo(b):(map.get(b)-map.get(a));
            }
        });

        for(String word:map.keySet()){
            heap.add(word);
        }

        List<String> ans = new ArrayList();
        for(int i=0;i<k;i++){
            if(!heap.isEmpty()){
                ans.add(heap.poll());
            }else{
                break;
            }
        }
        return ans;
    }

    
}
```
