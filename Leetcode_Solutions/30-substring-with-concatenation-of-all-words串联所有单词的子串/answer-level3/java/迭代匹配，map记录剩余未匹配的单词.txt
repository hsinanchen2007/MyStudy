执行结果：
通过
显示详情
执行用时 :
528 ms
, 在所有 Java 提交中击败了
8.47%
的用户
内存消耗 :
65.4 MB
, 在所有 Java 提交中击败了
32.67%
的用户
```
class Solution {
    List<Integer> res = new ArrayList<Integer>();
    public List<Integer> findSubstring(String s, String[] words) {
        int slen = s.length();
        if(slen==0){return res;}
        if(words.length==0)return res;
        int len = words[0].length();
        int totallen = words.length*len;
        if(totallen>slen)return res;
        List<String> list = new ArrayList<String>();
        for(int i=0; i<words.length; i++){
            list.add(words[i]);
        }
        String ss="";
        char[] chars = s.toCharArray();
        for(int i=0; i<len; i++){
            ss+=chars[i];
        }
        if(list.contains(ss)){
            List<String> newl = new ArrayList<String>(list);
            newl.remove(ss);
            calc(s,newl,0,len,len);
        }
        
        for(int i=1; i<=slen-totallen;i++){
            ss = ss.substring(1)+chars[i+len-1];
           // System.out.println(i+"_"+ss);
            if(list.contains(ss)){
                List<String> newl = new ArrayList<String>(list);
                newl.remove(ss);
                calc(s,newl,i,i+len,len);
            }
        }
        return res;
        
    }
    private void calc(String s, List<String> left, int start, int cur,int len){
        if(left.isEmpty()){
            res.add(start);
            return;
        }
        String curs = s.substring(cur,cur+len);
        if(left.contains(curs)){
            left.remove(curs);
            calc(s,left,start,cur+len,len);
        }
    }
}
```
