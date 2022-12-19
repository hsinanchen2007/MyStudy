

一、按照出现频率将元素和出现次数放到map中。

二、通过map的value进行排序。

三、取出排序后的前k个元素。


class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
          Map<Integer,Integer> count = new HashMap<>();
        for(int i=0;i<nums.length;i++){
            int element = nums[i];
            if(count.containsKey(element)){
               int value = count.get(element);
                count.put(element,value+1);
            }else{
                count.put(element,1);
            }
        }
        Comparator<Map.Entry<Integer, Integer>> valueComparator = new Comparator<Map.Entry<Integer,Integer>>() {
            @Override
            public int compare(Map.Entry<Integer, Integer> o1,
                               Map.Entry<Integer, Integer> o2) {
                return o2.getValue()-o1.getValue();
            }
        };
        List<Map.Entry<Integer, Integer>> list = new ArrayList<Map.Entry<Integer,Integer>>(count.entrySet());
        Collections.sort(list,valueComparator);
        List<Integer> result = new ArrayList<>();
        for(int i=0; i<k; i++){
            result.add(list.get(i).getKey());
        }
        return result;
    }
}