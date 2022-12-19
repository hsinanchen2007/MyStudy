```
// 先通过两个字符串的长度判断可能的变换情形
// 再依次处理三种操作：
// 替换 遍历获取差异个数
// 删除 穷举
// 插入 比较插入前后的子串是否相同
class Solution {
    public boolean isOneEditDistance(String s, String t) {
        if (s.length() == t.length() + 1) {
            return isDelete(s, t);
        } else if (s.length() == t.length()) {
            return isReplace(s, t);
        } else if (s.length() == t.length() - 1) {
            return isInsert(s, t);
        } else {
            return false;
        }
    }
    
    public boolean isDelete(String a, String b) {
        List<String> list = new ArrayList<String>();
        for (int i = 0; i < a.length(); i++) {
            if (i == 0) {
                list.add(a.substring(1,a.length()));
            } else {
                list.add(a.substring(0, i) + a.substring(i+1, a.length()));
            }
        }
        return list.contains(b) ? true : false;
    }
    
    public boolean isReplace(String a, String b) {
        int diff = 0;
        for (int j = 0; j < a.length(); j++) {
            if (a.charAt(j) != b.charAt(j)) {
                diff += 1;
            }
        }
        return diff == 1 ? true : false;
    }
    
    public boolean isInsert(String a, String b) {
        int m = 0;
        int n = 0;
        int diff = 0;
        while (m < a.length()) {
            if (a.charAt(m) == b.charAt(n)) {
                m += 1;
                n += 1;
            } else {
                diff += 1;
                n += 1;
            }
            if (diff >= 2) {
                break;
            }
        }
        return diff <= 1 ? true : false;
    }
}
```
