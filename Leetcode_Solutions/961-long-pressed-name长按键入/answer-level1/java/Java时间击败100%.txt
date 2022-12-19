执行用时 :1 ms, 在所有 Java 提交中击败了100.00%的用户  
内存消耗 :34.4 MB, 在所有 Java 提交中击败了87.43%的用户  
```
class Solution {
    public boolean isLongPressedName(String name, String typed) {
        int i = 0;
        int j = 0;
        while(i<name.length() && j<typed.length()) {
            if(name.charAt(i)==typed.charAt(j)) {
                //System.out.println(name.charAt(i));
                //System.out.println(typed.charAt(j));
                i++;
                j++;
                continue;
            }
            else if(j>0 && typed.charAt(j)!=typed.charAt(j-1) || j==0) {
                return false;
            }
            while(j>0 && j<typed.length() && typed.charAt(j)==typed.charAt(j-1)) {
                j++;
            }
        }
        return i == name.length();
    }
}
```