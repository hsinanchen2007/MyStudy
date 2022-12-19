比之间解法改为Map保存中间结果
执行结果：
通过
显示详情
执行用时 :
13 ms
, 在所有 Java 提交中击败了
78.28%
的用户
内存消耗 :
38.4 MB
, 在所有 Java 提交中击败了
73.33%
的用户
```
class Solution {
    Set<String> set = new HashSet<>();
    
    boolean found =false;
    int maxl = 0;
    Map<String,List<StringBuffer>> map = new HashMap<>();
    public List<String> wordBreak(String s, List<String> wordDict) {
        
        for(String a:wordDict){
            if(a.length()>maxl)maxl=a.length();
            set.add(a);
        }
        List<StringBuffer> res = pro(s);
        List<String> ll = new ArrayList<>();
        if(!found)return ll;
        for(StringBuffer sb:res){
            ll.add(sb.toString());
        }
        return ll;
    }
    private List<StringBuffer> pro(String s){
        if(map.get(s)!=null)return map.get(s);
       
        List<StringBuffer> res = new ArrayList<>();
        int len = s.length();
        int xlen = Math.min(len,maxl);
        for(int i = 1; i<=xlen; i++){
            
            String sub = s.substring(0,i);
            if(set.contains(sub)){
                    if(i==len){
                        StringBuffer nsb = new StringBuffer();
                        nsb.append(sub);
                        
                        res.add(nsb);
                        found=true;
                        return res;
                    }
                    List<StringBuffer> nlist = new ArrayList<StringBuffer>();
                    List<StringBuffer> list = pro(s.substring(i,len));
                    for(StringBuffer sb:list){
                        StringBuffer nsb = new StringBuffer();
                        
                        nsb.append(sub);
                        nsb.append(" ");
                        nsb.append(sb);
                        nlist.add(nsb);
                    }
                    
                    res.addAll(nlist);
                 
            }
        }
        map.put(s,res);
        return res;
    }
}
```



遍历可能的单词然后递归，不出意外的超时了。
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
```
class Solution {
    Set<String> set = new HashSet<>();
    List<StringBuffer> res = new ArrayList<>();
    boolean found =false;
    public List<String> wordBreak(String s, List<String> wordDict) {
        
        for(String a:wordDict){
            set.add(a);
        }
        pro(s,null);
        List<String> ll = new ArrayList<>();
        if(!found)return ll;
        for(StringBuffer sb:res){
            ll.add(sb.toString());
        }
        return ll;
    }
    private void pro(String s,List<StringBuffer> list){
        int len = s.length();
        for(int i = 1; i<=len; i++){
            
            String sub = s.substring(0,i);
            if(set.contains(sub)){
                if(list==null){
                    List<StringBuffer> nlist = new ArrayList<StringBuffer>();
                    
                    StringBuffer sb = new StringBuffer();
                    nlist.add(sb);
                    sb.append(sub);
                    if(i!=len){
                        sb.append(" ");
                    }
                    
                    if(i==len){
                        res.addAll(nlist);
                        found=true;
                        return;
                    }
                    pro(s.substring(i,len),nlist);
                }else{
                    List<StringBuffer> nlist = new ArrayList<StringBuffer>();
                    for(StringBuffer sb:list){
                        StringBuffer nsb = new StringBuffer();
                        nsb.append(sb);
                        nsb.append(sub);
                        if(i!=len){
                           nsb.append(" ");
                        }
                        nlist.add(nsb);
                    }
                    if(i==len){
                        res.addAll(nlist);
                        found=true;
                        return;
                    }
                     pro(s.substring(i,len),nlist);
                    
                }
            }
        }
    }
}
```
