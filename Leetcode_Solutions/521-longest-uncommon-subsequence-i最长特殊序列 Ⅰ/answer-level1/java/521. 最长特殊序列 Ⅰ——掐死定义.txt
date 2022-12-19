1.两个字符串相同时，不是“特有”，返回-1；
2.两个字符串不同时，分两种情况
    （1）长度相同，这两个字符串互为特有，返回这个length即可。
    （2）长度不同，长度大的相对长度小的一定是特有，返回这个length即可。
三目运算符是右结合的，不用加括号，一行代码解决。
```
class Solution{
    public int findLUSlength(String a, String b){
        return a.equals(b) ? -1 : a.length()>b.length()?a.length():b.length();
    }
}
```
