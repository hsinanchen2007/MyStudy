**思路：** 依照题目描述可以根据第一个字符是1或2分情况处理。只有当第一个字符为1或2时需要考虑是否有#，其余情况正常处理即可



```
class Solution {
    public String freqAlphabets(String s) {
        StringBuilder ans = new StringBuilder();
        
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) == '1' || s.charAt(i) =='2'){
                if(i<s.length()-2 && s.charAt(i+2) =='#'){
                    int t = 10*(s.charAt(i)-'0');
                    t +=(s.charAt(i+1)-'0');
                    ans.append((char)(t+'a'-1));
                    i+=2;
                }else{
                    ans.append((char)(s.charAt(i)-'0'+'a' -1 ));

                }
            }else{
                ans.append((char)(s.charAt(i)-'0'+'a' -1 ));
            }
        }
        return ans.toString();
    }
}
```
