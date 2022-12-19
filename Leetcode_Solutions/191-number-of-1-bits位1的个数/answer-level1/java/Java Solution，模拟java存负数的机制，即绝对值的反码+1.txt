执行结果：
通过
执行用时 :2 ms, 在所有 java 提交中击败了66.54%的用户
内存消耗 :33.5 MB, 在所有 java 提交中击败了17.09%的用户
```
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        // System.out.println(n);
        String s="";
        //转成二进制，注意负数的二进制是其绝对值的反码+1；所以模拟此规则，加一后计算‘1’的数量
        //取反后的数量是32减去之前的数量
        if(n<0){
            s = Integer.toString(n+1,2);
        }else{
            s = Integer.toString(n,2);
        }
        
                // System.out.println(s);

        char[] cs = s.toCharArray();
        int res = 0;
        for(int i=0; i<cs.length;i++){
            if(cs[i]=='1'){
                res++;
            }
        }
        if(n<0){
            res = 32-res;
        }
        return res;
    }
}
```

