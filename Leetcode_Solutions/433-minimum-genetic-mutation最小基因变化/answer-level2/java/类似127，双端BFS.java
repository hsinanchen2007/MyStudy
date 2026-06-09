### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private char[] res = {'A', 'C', 'G', 'T'};
    public int minMutation(String start, String end, String[] bank) {
        HashSet<String> st = new HashSet<>();
        st.add(start);
        HashSet<String> ed = new HashSet<>();
        ed.add(end);
        HashSet<String> banks = new HashSet<>();
        for(String str : bank){
            banks.add(str);
        }
        if(!banks.contains(end)) return -1;
        return bfs(st, ed, banks, 1);
    }
    public int bfs(HashSet<String> st, HashSet<String> ed, HashSet<String> banks, int dep){
        if(st.size() > ed.size()) return bfs(ed, st, banks, dep);
        banks.removeAll(st);
        HashSet<String> next = new HashSet<>();
        for(String str : st){
            char[] c = str.toCharArray();
            for(int i = 0; i < c.length; i++){
                char tmp = c[i];
                for(int j = 0; j < res.length; j++){
                    c[i] = res[j];
                    String word = new String(c);
                    if(banks.contains(word)){
                        if(ed.contains(word)){
                            return dep;
                        }
                        next.add(word);
                    }
                }
                c[i] = tmp;
            }
        }
        if(st.isEmpty()) return -1;
        return bfs(next, ed, banks, dep + 1);
    }
}
```