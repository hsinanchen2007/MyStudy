* 起始长度要大于B，这个很简单了，不大于B就不可能包含B
* 终止长度为A + B，可以这么考虑，最糟糕的情况也就是最长的情况是从A的最后一个字符开始匹配，那么后面最小要有个B的长度，所以终止长度为A + B(评论区那么多`2A+B`，我感觉把问题想复杂了)
* 因此至多判断两次，首先将A凑到长度大于B，然后判断；如果不包含，再添加A继续判断；如果仍旧不包含，那么就直接返回-1，因为此时的长度已经大于等于A+B了
```
class Solution {
    public int repeatedStringMatch(String A, String B) {
        StringBuilder sb = new StringBuilder(A);
        int cnt = 1;
        while(sb.length() < B.length()){
            sb.append(A);
            cnt++;
        }
        if(sb.indexOf(B) != -1){
            return cnt;
        }
        sb.append(A);
        cnt++;
        return sb.indexOf(B) != -1 ? cnt: -1;
    }
}
```