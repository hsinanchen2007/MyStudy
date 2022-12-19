```
class Solution {
    public String[] permutation(String s) {
        HashSet<String> set = new HashSet<String>();
        char[] cs = s.toCharArray();
        dfs(cs, 0, set);
        String[] strs = new String[set.size()];
        int i = 0;
        for(String x : set) {
            strs[i++] = x;
        }
        return strs;
    }
    void dfs(char[] cs, int index, HashSet<String> set) {
        if(index == cs.length) {
            set.add(String.valueOf(cs));
        }
        for(int i = index; i < cs.length; i ++) {
            swap(cs, index, i);
            dfs(cs, index + 1, set);
            swap(cs, index, i);
        }
    }
    void swap(char[] cs, int i, int j) {
        char tmp = cs[i];
        cs[i] = cs[j];
        cs[j] = tmp;
    }
}
```
交换法
