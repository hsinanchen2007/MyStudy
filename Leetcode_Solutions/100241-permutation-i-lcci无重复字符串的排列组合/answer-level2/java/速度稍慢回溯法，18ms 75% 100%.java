### 解题思路
创建了一个判断矩阵used来判断是否前面用过这个字母了
回溯法来一步步的找到没用过的字母迭代
当所有字母都被用了，就可以加入list

### 代码

```java
class Solution {
    public String[] permutation(String S) {
        if (S.length() == 0)
            return new String[0];
        List<String> res = new ArrayList<>();
        char[] s = S.toCharArray();
        boolean[] used = new boolean[s.length];
        res=helper(s, used, "", res);
        String [] ret=new String[res.size()];
        return res.toArray(ret);
    }
    private List<String> helper(char[] s, boolean[] used, String cur, List<String> res) {
        if (cur.length() == s.length) {
            res.add(cur);
            return res;
        }
        for (int i=0;i<s.length;i++){
            if (!used[i]){
                used[i]=true;
                res=helper(s,used,cur+s[i],res);
                used[i]=false;
            }
        }
        return res;
    }
}
```