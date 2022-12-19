执行结果：
通过
显示详情
执行用时 :
10 ms
, 在所有 Java 提交中击败了
73.39%
的用户
内存消耗 :
36.6 MB
, 在所有 Java 提交中击败了
80.11%
的用户
```
public class Solution {
     boolean res=false;
	    Map<String,Boolean> resmap = new HashMap<String,Boolean>();
	    public boolean wordBreak(String s, List<String> wordDict) {
	        Short short1 = 1;
	        Map<String,Short> map = new HashMap<>();
	        Set<Integer> set = new TreeSet<Integer>();
	        for(String a:wordDict){
	            map.put(a,short1);
	            set.add(a.length());
	        }
	        Integer[] arr = set.toArray(new Integer[0]);
	        get(s,map,arr);
	        return res;
	        
	    }
	    private boolean get(String s,Map<String,Short> map,Integer[] set  ){
	        int slen = s.length();
	        if(s.length()==0)return false;
	        if(resmap.get(s)!=null)return resmap.get(s);
	        for(int k=set.length-1; k>=0;k--){
	            int len = set[k];
	            if(len>slen)continue;
	            String s1 = s.substring(0,len);
	            if(map.get(s1)!=null){
	                if(len==slen){
	                    res=true;
	                    return true;
	                }else{
	                    if(get(s.substring(len,slen),map,set)){
	                        return true;
	                    }
	                }
	            }
	        }
	        resmap.put(s, false);
	        return false;
}
}
```
