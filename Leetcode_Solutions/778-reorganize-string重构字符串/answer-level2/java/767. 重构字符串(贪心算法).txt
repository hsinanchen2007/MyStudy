![image.png](https://pic.leetcode-cn.com/9da9bca3ef6602c70baad09f56952dc3f518d2b18a44ded4f8439ce84a0fa5ef-image.png)

```
class Solution {
    public String reorganizeString(String S) {
        PriorityQueue<int[]> pq;
        int i;
        int[] map, next, last;
        StringBuilder answer;

        answer = new StringBuilder();   
        pq = new PriorityQueue<>((a, b) -> b[1] - a[1]);
        map = new int[26];
        for(i = 0; i < S.length(); i++)
            map[S.charAt(i)-'a']++;
        for(i = 0; i < 26; i++)
            if(map[i] > 0)
                pq.add(new int[]{i, map[i]});
        next = pq.remove();
        answer.append((char) (next[0] + 'a'));
        next[1]--;
        while(!pq.isEmpty()){
            last = next;
            next = pq.remove();
            answer.append((char) (next[0] + 'a'));
            next[1]--;
            if(last[1] > 0)
                pq.add(last);
        }
        if(answer.length() == S.length())
            return answer.toString();
        return "";
    }
}
```
