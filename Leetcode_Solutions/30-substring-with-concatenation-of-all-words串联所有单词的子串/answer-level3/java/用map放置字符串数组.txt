执行结果：
通过
显示详情
执行用时 :
225 ms
, 在所有 Java 提交中击败了
48.98%
的用户
内存消耗 :
50.4 MB
, 在所有 Java 提交中击败了
45.74%
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
        Map<String,Integer> map = new HashMap<String,Integer>();
        for(int i=0; i<words.length; i++){
            list.add(words[i]);
            map.put(words[i],map.getOrDefault(words[i],0)+1);
        }
        String ss="";
        char[] chars = s.toCharArray();
        for(int i=0; i<len; i++){
            ss+=chars[i];
        }
        if(map.containsKey(ss)){
            Map<String,Integer> nmap = new HashMap<String,Integer>(map);
            removeFromMap(nmap,ss);
            calc(s,nmap,0,len,len);
        }
        
        for(int i=1; i<=slen-totallen;i++){
            ss = ss.substring(1)+chars[i+len-1];
           // System.out.println(i+"_"+ss);
            if(map.containsKey(ss)){
                 Map<String,Integer> nmap = new HashMap<String,Integer>(map);
                removeFromMap(nmap,ss);
                calc(s,nmap,i,i+len,len);
            }
        }
        return res;
        
    }
    private void removeFromMap(Map<String,Integer> map, String s){
        if(map.get(s)>1){
            map.put(s,map.get(s)-1);
        }else{
            map.remove(s);
        }
        
    }
    private void calc(String s, Map<String,Integer> map, int start, int cur,int len){
        if(map.isEmpty()){
            res.add(start);
            return;
        }
        String curs = s.substring(cur,cur+len);
        if(map.containsKey(curs)){
            removeFromMap(map,curs);
            calc(s,map,start,cur+len,len);
        }
    }
}
```
