# 解题思路：
    先把字符串转换成char[]类型
    可以利用异或操作：1^1=0,0^1=1
# 实现代码：
```
public class Solution {
    public int[] MaxDepthAfterSplit(string seq) {
        var res = new int[seq.Length];
        int isZero = 1;
        var ch = seq.ToCharArray();
        for(int i = 0; i < seq.Length; i++){
            if(ch[i] == '('){
                isZero ^= 1;
                res[i] = isZero;
            }
            else{
                res[i] = isZero;
                isZero ^= 1;
            }
        }
        return res;
    }
}
```

    