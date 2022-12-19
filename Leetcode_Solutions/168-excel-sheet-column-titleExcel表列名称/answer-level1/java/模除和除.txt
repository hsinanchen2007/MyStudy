执行结果：
通过
显示详情
执行用时 :
0 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
34.3 MB
, 在所有 Java 提交中击败了
83.37%
的用户
```
class Solution {
    public String convertToTitle(int n) {
        StringBuffer sb = new StringBuffer();
        
        while(n>0){
            int k=n%26;
            if(k==0){
                n-=26;
                k=26;
            }
            
            char c = (char)((k-1) +(int)'A');
            sb.insert(0,c);
            n = n/26;
        }
        return sb.toString();
    }
}
```
