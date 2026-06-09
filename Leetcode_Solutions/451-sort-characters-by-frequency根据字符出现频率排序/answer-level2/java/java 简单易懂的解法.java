一、按照出现频率将元素和出现次数放到map中。

二、通过map的value进行排序。

三、然后取出排序后的key和value，通过循环value次将key拼接到string中。

class Solution {
    public String frequencySort(String s) {
      Map<Character,Integer> count = new HashMap<>();
        for(int i=0;i<s.length();i++){
            char element = s.charAt(i);
            if(count.containsKey(element)){
                int value = count.get(element);
                count.put(element,value+1);
            }else{
                count.put(element,1);
            }
        }
        Comparator<Map.Entry<Character,Integer>> valueComparator = new Comparator<Map.Entry<Character, Integer>>() {
            @Override
            public int compare(Map.Entry<Character, Integer> o1, Map.Entry<Character, Integer> o2) {
                return o2.getValue()-o1.getValue();
            }
        };
        List<Map.Entry<Character,Integer>> list= new ArrayList<>(count.entrySet());
        Collections.sort(list,valueComparator);
        StringBuffer sb = new StringBuffer();
        for(int i=0;i<list.size();i++){
            char ele = list.get(i).getKey();
            int num = list.get(i).getValue();
            for(int j=0;j<num;j++){
                sb.append(ele);
            }
        }
        return sb.toString();  
    }
}