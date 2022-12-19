申请一个数组用来保存当前最大子序列的个数，直到个数为S自妇产的长度就说明是子序列，否则就不是子序列
```
class Solution {
    public boolean isSubsequence(String s, String t) {
        if (s.length() == 0) {
            return true;
        }
        if (t.length() == 0) {
            return false;
        }
        int data[] = new int[t.length()];
        int slength = s.length();
        
        data[0] = s.charAt(0) == t.charAt(0) ? 1 : 0;
        for (int i = 1; i < t.length(); i++) {
            if (s.charAt(data[i-1]) == t.charAt(i)) {
                data[i] = data[i-1]+1;
                if(data[i] == slength) {
                    return true;
                }
            } else {
                data[i] = data[i-1];
            }
        }
        return false;
    }
}
```
