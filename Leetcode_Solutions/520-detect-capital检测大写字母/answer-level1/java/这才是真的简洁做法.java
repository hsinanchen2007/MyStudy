遍历数组统计个数太慢了，这道题判断对错基本上只有以下规则：
    1. 首字母大写 - 后续字母大写
    2. 首字母大写 - 后续字母小写
    3. 首字母小写 - 后续字母小写
除去这三种都是错误的，判断前两个字母的大小写是否符合规则后，后续所有字母的大小写必须和第二个字母一样，否则返回false。
```
    boolean detectCapitalUse(String word)
    {
        if (word.length() < 2) return true;
        boolean isSecondCap = word.charAt(1) < 97;//第二个字母的大小写就是后续字母的大小写
        if (word.charAt(0) > 96 && isSecondCap) return false;//只有首字母小写和第二个字母大写不符合规则
        for (int i = 2; i < word.length(); i++)
        {
            if (word.charAt(i) < 97 != isSecondCap) return false;
        }
        return true;
    }
```
