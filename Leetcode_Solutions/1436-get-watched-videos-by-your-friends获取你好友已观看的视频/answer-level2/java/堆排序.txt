### 解题思路
感觉没啥特别的，就是一层一层找朋友，出现过的朋友用set标记一下。
然后用哈希表计数，最后用堆排序，将结果输出就行。

### 代码

```java
class Solution {
    public List<String> watchedVideosByFriends(List<List<String>> watchedVideos, int[][] friends, int id, int level) {
        Queue<Integer> myfriends = new LinkedList<>();
        //set来记录已出现的朋友
        Set<Integer> set = new HashSet<>();
        set.add(id);
        myfriends.add(id);
        while (level-- != 0){
            int len = myfriends.size();
            while (len-- != 0){
                Integer temp = myfriends.poll();
                for (int i : friends[temp]) {
                    if (!set.contains(i)){
                        myfriends.add(i);
                        set.add(i);
                    }
                }
            }
        }
        Map<String,Integer> map = new HashMap<>();
        for (Integer myfriend : myfriends) {
            List<String> strings = watchedVideos.get(myfriend);
            for (String string : strings) {
                if (map.containsKey(string))
                    map.put(string,map.get(string)+1);
                else
                    map.put(string,1);
            }
        }
        PriorityQueue<String> pq = new PriorityQueue<>(new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                if (map.get(o1).equals(map.get(o2)))
                    return o1.compareTo(o2);
                return map.get(o1)-map.get(o2);
            }
        });
        pq.addAll(map.keySet());
        List<String> res = new ArrayList<>();
        while (!pq.isEmpty())
            res.add(pq.remove());
        return res;
    }
}
```