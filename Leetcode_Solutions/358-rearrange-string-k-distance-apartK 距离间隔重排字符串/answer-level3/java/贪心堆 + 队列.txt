![image.png](https://pic.leetcode-cn.com/baea84d4e90b7312f2bc8230fa60a4dc168b82cd848d9d9918cd023fda0385c3-image.png)

```
class Solution {
    public String rearrangeString(String s, int k) {
        int[] map = new int[26];
        for(char c : s.toCharArray()){
            map[c - 'a']++;
        }
        PriorityQueue<Integer> heap = new PriorityQueue<>((o1, o2) -> map[o2] - map[o1]);
        StringBuilder ans = new StringBuilder();
        Queue<Integer> temp = new LinkedList<>();
        for(int i = 0; i < map.length; i++){
            if(map[i] > 0) heap.add(i);
        }
        while(!heap.isEmpty()){
            int curr = heap.poll();
            temp.add(curr);
            map[curr]--;
            ans.append((char)('a' + curr));
            if(temp.size() >= k){
                int mem = temp.poll();
                if(map[mem] > 0) heap.offer(mem);
            }
        }

        return ans.length() == s.length() ? ans.toString() : "";
    }
}
```
