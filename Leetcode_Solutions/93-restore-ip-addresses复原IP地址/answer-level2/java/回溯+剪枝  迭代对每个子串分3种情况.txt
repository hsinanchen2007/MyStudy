执行结果：
通过
显示详情
执行用时 :
3 ms
, 在所有 Java 提交中击败了
97.44%
的用户
内存消耗 :
36.4 MB
, 在所有 Java 提交中击败了
46.25%
的用户
```
class Solution {
     List<String> res = new ArrayList<String>();
    public List<String> restoreIpAddresses(String s) {
        
        get(s,1,new StringBuffer());
        return res;
    }
    private void get(String s, int seg,StringBuffer sb){
        if(seg>4)return;
        int len = s.length();
        if(len<(5-seg)||len>3*(5-seg))return;
        
        
        String s1 = s.substring(0,1);
        StringBuffer sb1 = new StringBuffer(sb);
        sb1.append(s1);
        if(seg==4&&s.substring(1,len).length()==0){
            res.add(sb1.toString());
        }else{
            sb1.append(".");
        }
        get(s.substring(1,len),seg+1,sb1);
        
        if(s.length()>=2){
            String s2 = s.substring(0,2);
            if(Integer.parseInt(s2)>=10){
                 StringBuffer sb2 = new StringBuffer(sb);
                sb2.append(s2);
                if(seg==4&&s.substring(2,len).length()==0){
                    res.add(sb2.toString());
                }else{
                    sb2.append(".");
                }
                get(s.substring(2,len),seg+1,sb2);
            }
           
        }
       
        
        if(s.length()>=3){
            String s3 = s.substring(0,3);
            if(Integer.parseInt(s3)>99&&Integer.parseInt(s3)<256){
                StringBuffer sb3 = new StringBuffer(sb);
                sb3.append(s3);
                if(seg==4&&s.substring(3,len).length()==0){
                    res.add(sb3.toString());
                }else{
                    sb3.append(".");
                }
                get(s.substring(3,len),seg+1,sb3);
            }
        }
        
        
    }
}
```
