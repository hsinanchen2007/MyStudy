执行结果：
通过
显示详情
执行用时 :
272 ms
, 在所有 Java 提交中击败了
5.04%
的用户
内存消耗 :
53.4 MB
, 在所有 Java 提交中击败了
17.14%
的用户

黑体部分***（）***可以删除
```
class Solution {
    Map<String,Boolean> map = new HashMap<String,Boolean>();
    public boolean isMatch(String s, String p) {
        int sl = s.length();
        int pl = p.length();
        
        if(pl==0&&sl!=0)return false;
        if(pl==0&&sl==0)return true;
        
        StringBuffer sb = new StringBuffer();
        sb.append(p.charAt(0));
        int count=p.charAt(0)=='*'?1:0;
        for(int i=1; i<pl;i++){
            if(p.charAt(i)==p.charAt(i-1)&&(p.charAt(i)=='*')){
                count++;
                continue;
            }else if(p.charAt(i)=='*'){
                count++;
            }
             sb.append(p.charAt(i));
        }
        p = sb.toString();
        
         
        if(sl<pl-count)return false;
        
        return mm(s,p);
    }
    private boolean mm(String s,String p){
        if(map.get(s+"-"+p)!=null)return map.get(s+"-"+p);
        int sl = s.length();
        int pl = p.length();
        if(pl==0&&sl!=0)return Boolean.FALSE;
        if(pl==0&&sl==0)return true;
        if(sl==0&&pl!=0){
            if(pl==1&&p.charAt(0)=='*'){
                return true;
            }else{
                map.put(s+"-"+p,Boolean.FALSE);
                return Boolean.FALSE;
            }
        }
        //both !=0
        if(p.charAt(0)=='?'||p.charAt(0)==s.charAt(0)){
            boolean bb =  mm(s.substring(1,sl),p.substring(1,pl));
            map.put(s+"-"+p,bb);
            return bb;
        }else if(p.charAt(0)=='*'){
            boolean bb =  mm(s,p.substring(1,pl))||***mm(s.substring(1,sl),p.substring(1,pl))***||mm(s.substring(1,sl),p);
            map.put(s+"-"+p,bb);
            return bb;
        }else{
            map.put(s+"-"+p,Boolean.FALSE);
            return Boolean.FALSE;
        }
        
    }
}
```
