### 解题思路
1. 遍历字符串，存储每个字母的第一次出现的位置和最后一次的位置
2. 将存储位置存入堆，每次从堆中取出起始位置最小的
3. 用start和end标记当前的区间范围

### 代码

```java
class Solution {
    public List<Integer> partitionLabels(String S) {
        List<Integer> res = new ArrayList<>();
        if (S.length() == 1){
            res.add(1);
            return res;
        }
        Map<Character,int[]> map = new HashMap<>();
        for(int i = 0;i < S.length(); i++){
            if (map.containsKey(S.charAt(i))){
                int[] ints = map.get(S.charAt(i));
                ints[1] = i;
            }
            else {
                int[] ints = new int[2];
                ints[0] = i;
                ints[1] = i;
                map.put(S.charAt(i),ints);
            }
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0] - o2[0];
            }
        });
        pq.addAll(map.values());
        int[] remove = pq.remove();
        int start = remove[0];
        int end = remove[1];
        while (!pq.isEmpty()){
            int[] temp = pq.remove();
            if (temp[0] > end){
                res.add(end - start + 1);
                start = temp[0];
                end = temp[1];
            }
            else {
                if (temp[1] > end)
                    end  = temp[1];
            }
        }
        res.add(end - start + 1);
        return res;
    }
}
```