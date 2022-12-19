>执行用时 : 4 ms, 在Jewels and Stones的Java提交中击败了79.88% 的用户<br>
内存消耗 : 34.7 MB, 在Jewels and Stones的Java提交中击败了90.87% 的用户

一心想着直接用String来弄，还手撸一个删除指定字符串的方法，就是没想着把String直接转成char <br>
还是看的太少<br>
继续努力(ง •_•)ง

```Java
class Solution {
    public int numJewelsInStones(String J, String S) {
        int num=0;
        for(int i =0;i<J.length();i++){
            for(int j=0;j<S.length();j++){
                if (S.charAt(j)==J.charAt(i)) {
                    num++;
                    S=removeCharAt(S,j);
                    j--;
                }
            }
        }
        return num;
    }
    public static String removeCharAt(String s, int pos) {//删除字符串指定位置字符
      return s.substring(0, pos) + s.substring(pos + 1);
   }
}
```