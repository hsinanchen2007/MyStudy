# 思路 使用indexOf方法判断是否有两个A，如果有两个A 那么indexOf("A")!=lastIndexOf("A");
```
class Solution {
    public boolean checkRecord(String s) {
        return !((s.indexOf("A")!=s.lastIndexOf("A"))||(s.indexOf("LLL")!=-1));
    }
}
```

