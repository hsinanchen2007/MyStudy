### 解题思路
使用Map<Integer,Integer>做数字频率统计，使用PriorityQueue<Map.Entry<Integer,Integer>>对键值对按照频率降序，从队列头弹出键值对，直到频率总和超过数组大小的一半。

### 代码

```java
class Solution {
    public int minSetSize(int[] arr) {
        //特殊情况
        if(arr==null || arr.length==0){
            return 0;
        }
        //频率统计
        Map<Integer,Integer> map = new HashMap<>();
        for(int i:arr){
            Integer one = map.get(i);
            if(one==null){
                map.put(i,1);
            }else{
                map.put(i,one+1);
            }
        }
        //按频率排序
        PriorityQueue<Map.Entry<Integer,Integer>> queue = new PriorityQueue<>(new Comparator<Map.Entry<Integer,Integer>>() {
            @Override
            public int compare(Map.Entry<Integer,Integer> o1, Map.Entry<Integer,Integer> o2) {
                return o2.getValue() - o1.getValue();
            }
        });
        for(Map.Entry<Integer,Integer> entry : map.entrySet()){
            queue.add(entry);
        }
        //数组减半
        int len = arr.length/2;
        int mid = 0;
        int ans = 0;
        while(mid<len){
            ans++;
            mid += queue.poll().getValue();
        }
        return ans;
    }
}
```