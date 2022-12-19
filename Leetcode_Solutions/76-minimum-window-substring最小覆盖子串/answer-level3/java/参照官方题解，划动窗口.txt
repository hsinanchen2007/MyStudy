执行结果：
通过
显示详情
执行用时 :
69 ms
, 在所有 Java 提交中击败了
39.18%
的用户
内存消耗 :
40 MB
, 在所有 Java 提交中击败了
56.57%
的用户
```
class Solution {
    public String minWindow(String s, String t) {
        int slen = s.length();
        int tlen = t.length();
        if(slen==0||tlen==0)return "";
        if(slen<tlen)return "";
        
        Map<Character,Integer> map = new HashMap<>();
        Map<Character,Integer> mapt = new HashMap<>();
        Map<Character,Integer> redudant = new HashMap<>();
        for(int i=0; i<tlen; i++){
            map.put(t.charAt(i),map.getOrDefault(t.charAt(i),0)+1);
            mapt.put(t.charAt(i),1);
        }
        
        int left = 0;
        int right=0;
        int min=Integer.MAX_VALUE;
        String mins= "";
        for(int i=0; i<slen; i++){
            if(mapt.get(s.charAt(i))!=null){
                if(get(s,i,map,redudant)){
                    right = i;
                    int nmin = right-left;
                    if(nmin<min){
                        min=nmin;
                        mins=right+"-"+left;
                    }
                    for(int j = left; j<i;j++){
                        left = j+1;
                        if(mapt.get(s.charAt(j))!=null){
                            if(remove(s,j,map,redudant)){
                                nmin = right-left;
                                if(nmin<min){
                                    min=nmin;
                                    mins=right+"-"+(left-1);
                                } 
                                break;
                            }
                        }else{
                           nmin = right-left;
                            if(nmin<min){
                                min=nmin;
                                mins=right+"-"+(left);
                            }  
                        }
                        
                    }
                    
                }
            }
        }
        if(!"".equals(mins)){
            String[] spi=mins.split("-");
            return s.substring(Integer.valueOf(spi[1]),Integer.valueOf(spi[0])+1);
        }
        
        return "";
    }
    private boolean get(String s,  int cur, Map<Character,Integer> leftMap,Map<Character,Integer> redudant){
        
        Integer cc = leftMap.get(s.charAt(cur));
        if(cc!=null){
            int count=cc;
            if(count==1){
                leftMap.remove(s.charAt(cur));
                if(leftMap.isEmpty())return true; 
            }else{
                leftMap.put(s.charAt(cur),count-1);
            }
            
        }else{
            redudant.put(s.charAt(cur),redudant.getOrDefault(s.charAt(cur),0)+1);
        }
        return false;
    }
    
     private boolean remove(String s,  int cur, Map<Character,Integer> leftMap,Map<Character,Integer> redudant){
        
        Integer cc = redudant.get(s.charAt(cur));
        if(cc!=null){
            int count=cc;
            if(count==1){
                redudant.remove(s.charAt(cur));
            }else{
                redudant.put(s.charAt(cur),count-1);
            }
            
        }else{
            leftMap.put(s.charAt(cur),leftMap.getOrDefault(s.charAt(cur),0)+1);
            return true;
        }
        return false;
    }
    
}
```



暴力统计，超时。。
```
class Solution {
    public String minWindow(String s, String t) {
        int slen = s.length();
        int tlen = t.length();
        if(slen==0||tlen==0)return "";
        if(slen<tlen)return "";
        
        Map<Character,Integer> map = new HashMap<>();
        Map<Character,Integer> map2 = new HashMap<>();
        List<Integer> list= new ArrayList<>();
        Map<Integer,Map<Character,Integer>> res = new HashMap<>();
        for(int i=0; i<tlen; i++){
            map.put(t.charAt(i),map.getOrDefault(t.charAt(i),0)+1);
        }
        for(int i=0; i<slen; i++){
            map2.put(s.charAt(i),map2.getOrDefault(s.charAt(i),0)+1);
        }
        for(Character cc:map.keySet()){
            if(map2.get(cc)==null)return "";
            if(map2.get(cc).compareTo(map.get(cc))<0){
                return "";
            }
        }
        for(int i=0; i<=slen-tlen; i++){
            if(map.get(s.charAt(i))!=null){
                list.add(i);
                res.put(i,new HashMap<Character,Integer>(map));
            }
        }
        
        
        int index=0;
        
        while(list.size()!=0){
            List<Integer> exc = new ArrayList<>();
            for(Integer i:list){
                if(i+index<slen){
                    boolean bb = get(s, i, i+index, res.get(i));
                    if(bb){
                        return s.substring(i,i+index+1);
                    }
                }else{
                    exc.add(i);
                }
            }
            list.removeAll(exc);
            index++;
        }
        
        return "";
    }
    private boolean get(String s, int start, int cur, Map<Character,Integer> leftMap){
        
        Integer cc = leftMap.get(s.charAt(cur));
        if(cc!=null){
            int count=cc;
            if(count==1){
                leftMap.remove(s.charAt(cur));
                if(leftMap.isEmpty())return true; 
            }else{
                leftMap.put(s.charAt(cur),count-1);
            }
            
        }
        return false;
    }
    
}
```
