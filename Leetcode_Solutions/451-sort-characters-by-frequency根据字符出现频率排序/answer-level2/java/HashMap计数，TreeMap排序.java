执行结果：
通过
显示详情
执行用时 :
133 ms
, 在所有 Java 提交中击败了
11.36%
的用户
内存消耗 :
50 MB
, 在所有 Java 提交中击败了
38.05%
的用户
```
class Solution {
    public String frequencySort(String s) {
        Map<Integer, List<Character>> map = new TreeMap(new Comparator<Integer>(){
            public int compare(Integer i1, Integer i2){
                return i2.compareTo(i1);
            }
        });
        
        Map<Character,Integer> map2 = new HashMap<Character,Integer>();
        int len = s.length();
        for(int i=0; i<len; i++){
            char c = s.charAt(i);
            map2.put(c,map2.getOrDefault(c,0)+1);
        }
        
        Iterator<Map.Entry<Character,Integer>> it = map2.entrySet().iterator();
        while(it.hasNext()){
            Map.Entry<Character,Integer> entry = it.next();
            List ll = map.getOrDefault(entry.getValue(),new ArrayList<Character>());
            ll.add(entry.getKey());
            map.put(entry.getValue(),ll);
        }
        //System.out.println(map2.size()+"--"+map.size());
        Iterator<Map.Entry<Integer, List<Character>>> it2 = map.entrySet().iterator();
        StringBuffer sb = new StringBuffer();
          while(it2.hasNext()){
            Map.Entry<Integer, List<Character>> entry = it2.next();
            entry.getValue().forEach( c->{
                Integer iii = map2.get(c);
                while(iii>0){
                    sb.append(c);
                    iii--;
                }
               
            });
        }
        return sb.toString();
        
    }
}
```
