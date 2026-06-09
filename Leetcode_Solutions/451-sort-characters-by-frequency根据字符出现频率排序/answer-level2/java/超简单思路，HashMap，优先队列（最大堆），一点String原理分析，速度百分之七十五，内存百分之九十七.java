  此题思路主要可以分为特别简单的两步，第一步遍历字符串，在hashmap中统计出不同字符的数量，第二部将哈希表中的数据拿出来建成大根堆。剩下的扫尾工作就是从堆顶开始一个个拿出来拼接字符串了。

ps。还有一个小小的拓展楼主因为这个被困扰了很久，String是final class，每次字符串拼接的时候就会创建一个新的字符串，当处理很多字符的时候内存就会超出，所以用StringBuilder拼接。

class Solution {
    public static String frequencySort(String s) {
        Map<Character,Integer> sMap=new HashMap<>();
        //字符串扫描，按不同字符统计出个数。
        for(int i=0;i<s.length();i++){
            int count=sMap.getOrDefault(s.charAt(i),0);
            sMap.put(s.charAt(i),count+1);
        }
        //使用了lambda表达式建立大根堆
        PriorityQueue<Character> heap =
                new PriorityQueue<Character>((n1, n2) -> sMap.get(n2)-sMap.get(n1));
        Set a=sMap.keySet();
        for(Character n:sMap.keySet()){
            heap.add(n);
        }

        //stringbuilder创建结果。
        StringBuilder res = new StringBuilder();
        while(heap.isEmpty()==false){
            Character c=heap.poll();
            int count=sMap.get(c);
            for(int i=0;i<count;i++){
                res.append(c);
            }
        }
        return res.toString();
    }
}