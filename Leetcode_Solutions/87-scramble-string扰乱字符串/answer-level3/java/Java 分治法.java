
由于是二叉树，所以对于根节点来说只有两种情况：左右子树交换过或者没交换过。
如果左右子树交换过，那么肯定可以找到s1的前缀“等于”s2的后缀，如果没交换过，那么s1的前缀“等于”s2的前缀，递归找下去即可。这里的“等于”是指组成的字符相同。直到某个枝条上两个字符串相等了，那就说明这种树是可以通过交换找到的。

```
class Solution {
    public boolean isScramble(String s1, String s2) {
        return check(s1,s2);
        
    }
    public boolean check(String a,String b){
        int k = ifsame(a,b);
        if (k==1) return true;
        if (k==-1) return false;
        String la;
        String lb;
        int n = a.length();
        for (int i = 1;i<n;i++){
            la = a.substring(0,i);
            lb = b.substring(0,i);
            if (ifsame(la,lb)>=0) {
                boolean a1 = check(la,lb)&&check(a.substring(i),b.substring(i));
                if (a1 == true) return true;
            }
            
            if (ifsame(la,b.substring(n-i))>=0) {
                boolean a1 = check(la,b.substring(n-i))&&check(a.substring(i),b.substring(0,n-i));
                if (a1) return true;
            }
        }
        return false;

    }

    public int ifsame(String a,String b){
        if (a.equals(b)) return 1;
        int[] aa = new int[26];
        int[] bb = new int[26];
        for (char c:a.toCharArray()){
            aa[c-'a']++;
        }
        for (char c:b.toCharArray()){
            bb[c-'a']++;
        }
        for (int i = 0;i<26;i++){
            if (aa[i]!=bb[i]) return -1;
        }
        return 0;
    }

}
```