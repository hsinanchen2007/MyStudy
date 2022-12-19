执行用时 : 3 ms , 在所有 Java 提交中击败了 97.81% 的用户
内存消耗 : 36.1 MB , 在所有 Java 提交中击败了 53.59% 的用户
```
class Solution {
    //使用个指针i，k，j然后判断0---i-1，i---k-1,k---j-1,j-1---s.length-1是否都满足要求即可
    //可以知道0<i<=3,s.length()-3<=j<s.length
    public List<String> restoreIpAddresses(String s) {
        List<String>rs=new ArrayList();
        if(s.length()<4||s.length()>12){
            return rs;
        }
        for(int i=1;i<=3;i++){
            for(int j=s.length()-1;j>=s.length()-3;j--){
                if(j-i<2){
                    break;
                }
                if(judge(s.substring(0,i))&&judge(s.substring(j))){
                    for(int k=i+1;k<j;k++){
                        if(judge(s.substring(i,k))&&judge(s.substring(k,j))){
                            rs.add(s.substring(0,i)+"."+
                                  s.substring(i,k)+"."+
                                  s.substring(k,j)+"."+
                                  s.substring(j));
                        }
                    }
                }
            }
        }
           return rs;
        
    }
    public boolean judge(String s){
        if(s.length()>3||s.length()<1){
            return false;
        }
        if(s.length()!=1&&s.charAt(0)=='0'){
            return false;
        }
        int num=0;
        for(int i=0;i<s.length();i++){
            num=num*10+(s.charAt(i)-'0');
        }
        if(num>255){
            return false;
        }else{
            return true;
        }
    }
}
```
