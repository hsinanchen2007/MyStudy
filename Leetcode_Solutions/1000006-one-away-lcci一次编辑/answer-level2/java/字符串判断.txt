
```java
class Solution {
    public boolean oneEditAway(String first, String second) {
        String a = first;
        String b = second;
        if (a.equals(b) || ins(a, b) || del(a, b) || rep(a, b)) { 
            return true;
        }
        return false;
    }
    
    // 对a进行所有的"插入"操作后是否可以还原b
    public boolean ins(String a, String b) {
        if(Math.abs(a.length() - b.length()) != 1) return false;
        
        int c = 0;
        char[] chs1 = a.toCharArray();
        char[] chs2 = b.toCharArray();
        for (int i = 0; i < chs1.length; i++) {
            c ^= chs1[i];
        }
        for (int i = 0; i < chs2.length; i++) {
            c ^= chs2[i];
        }
        
        StringBuilder stra = new StringBuilder(a);
        for (int i = 0; i < a.length() + 1; i++) {
            stra.insert(i, (char)c);
            if (stra.toString().equals(b)) return true;
            stra.deleteCharAt(i);
        }
        return false;
    }
    
    // 对a进行所有的"删除"操作后是否可以还原b
    public boolean del(String a, String b) {
        // 判断A中删除某个字符能否得到B可以转换B中添加某个字符能否得到A。
        return ins(b, a);
    }
    
    // 对a进行所有的"替换"操作后是否可以还原b
    public boolean rep(String a, String b) {
        if (a.length() != b.length()) return false;
        int n = 0;
        char[] chs = a.toCharArray();
        for (int i = 0; i < chs.length; i++) {
            if (chs[i] != b.charAt(i)) n++;
        }
        return n == 1;
    }
}
```
