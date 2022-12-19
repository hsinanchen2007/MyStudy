有问题欢迎指正
```
class Solution {
    /*
    分析（非C字符的分类如下）：
    1.只有左边有C字符： sdafC...
    2.左右两边都有C字符：...CdsfsC...
    3.只有右边有C字符：...Cdsff
    (在后面可以用一句代码实现这三种情况)
    */
    public int[] shortestToChar(String S, char C) {
        
        int[] res = new int[S.length()];
        int cur = S.indexOf(C), pre = cur;//双指针，cur表示下一个C的下标， pre表示前一个C的下标；通过这里的赋值使在上面情况1（此时pre = cur）的时候，pre也在当前字符的右边，否则在情况2的时候，当前字符必在cur和pre的中间。
        for(int i = 0; i < S.length(); i++){
            if(S.charAt(i) == C){//其实就是每当遍历到C就更新cur和pre
                res[i] = 0;
                pre = i;
                cur = S.indexOf(C, i+1);//注意：这里如果当前是最后一个C时，此时cur为-1，这也保证了上面的情况3

            }else{
                res[i] = Math.min(Math.abs(pre - i), Math.abs(cur - i));//
            }
        }
        return res;
    }
}
```
