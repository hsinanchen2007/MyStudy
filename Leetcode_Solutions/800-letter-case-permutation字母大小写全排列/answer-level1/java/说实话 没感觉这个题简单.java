这个题类似全排列 不过我们不需要将s转为数组 因为charAt可以直接定位当前字符 需要考虑大小写2种情况

假如s为 a123b
画出决策树

可以看出我们只需要在当前字符为字母的时候 有一个新分支

             
```
            root
    a123b           A123b
a123b   a123B    A123b  A123B  
```

转为回溯算法之后 只需要在index == S.length的时候 返回即可

```
 public List<String> letterCasePermutation(String S) {
        List<String> res = new ArrayList<>();
        dfs(new StringBuilder(S), 0, res);
        return res;
}


private void dfs (StringBuilder s, int index, List<String> res) {
        if (index == s.length()) {
            res.add(s.toString());
            return;
        }
        char ch = s.charAt(index);
        dfs(s, index + 1, res);
        if (Character.isLetter(ch)) {
            s.setCharAt(index, (char) (ch ^ 32));
            dfs(s, index + 1, res);                    // 搜索转换字母大小写后的组合
        }
}

```

