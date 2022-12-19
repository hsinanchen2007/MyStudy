执行结果：
通过
显示详情
执行用时 :
2 ms
, 在所有 Java 提交中击败了
54.07%
的用户
内存消耗 :
35.5 MB
, 在所有 Java 提交中击败了
82.75%
的用户
```
class Solution {
    public int lengthOfLastWord(String s) {
        char[] chars = s.toCharArray();
        int len = chars.length;
        if(len==0)return 0;
        int j=0;
        int k=0;
        int last=0;
        while(j<len){
            if(chars[j]==' '){
                if(k>0){
                    last=k;
                    k=0; 
                }
            }else{
                k++;
            }
            j++;
        }
        if(k>0){
            last=k;
        }
        
        return last;
    }
}
```
