### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private Set<String> set=new HashSet<>();
    public String[] permutation(String S) {
        if (S.length() == 0)
            return new String[0];
        char[] s = S.toCharArray();
        Arrays.sort(s);//字符串排序
        boolean[] used = new boolean[s.length];//用来标志当前char有没有用过
        helper(s, used, "");
        String[] ret=new String[set.size()];//把map中的String写入
        return set.toArray(ret);
    }
    private void helper(char[] s, boolean[] used, String cur) {
        if (cur.length() == s.length) {
            set.add(cur);
            return;
        }
        for (int i=0;i<s.length;i++){//回溯法
            if (!used[i]){
                used[i]=true;
                helper(s,used,cur+s[i]);
                used[i]=false;
            }
        }
    }
}
```