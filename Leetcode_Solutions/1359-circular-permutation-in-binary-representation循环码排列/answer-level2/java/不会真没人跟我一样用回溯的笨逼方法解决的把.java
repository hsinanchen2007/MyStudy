我的思路是对于每个数的每一位进行修改，如果之前这一位是1，那么就将这一位改为 0，得到一个数，然后继续搜索，反之亦然。
这里本来使用栈来存放路径，但是会发现整个搜索过程中不会出现栈需要 pop 的情况，那么就可以直接存入最后的结果。


```
class Solution {
    boolean[] marked;
    int len;
    boolean flag;
    List<Integer> ans;
    public List<Integer> circularPermutation(int n, int start) {
        len = 1 << n;
        marked = new boolean[len];
        flag = false;
        ans = new ArrayList<>();
        dfs(start, 0, n);
        return ans;
    }

    public void dfs(int val, int index, int n) {
        if (index == len) {
            flag = true;
            return;
        }
        if (marked[val]) {
            return;
        }
        marked[val] = true;
        ans.add(val);
        int num = val;
        for (int i = 0; i < n; i++) {
            int t = num & 1;
            int next;
            if (t == 0) {
                next = val + (1 << i);
            } else {
                next = val - (1 << i);
            }
            dfs(next, index + 1, n);
            if (flag) {
                return;
            }
            num >>= 1;
        }
    }
}
```
