执行结果：
通过
显示详情
执行用时 :
5 ms
, 在所有 Java 提交中击败了
97.56%
的用户
内存消耗 :
35.8 MB
, 在所有 Java 提交中击败了
37.56%
的用户
```
class Solution {
    public int titleToNumber(String s) {
        int len = s.length();
        if(len==0)return 0;
        int res = 0;
        for(int i= 0; i<len; i++){
            char c = s.charAt(i);
            int k = c-'A'+1;    
           // System.out.println(k);
            res = res*26+k;
        }
        return res;
    }
}
```
