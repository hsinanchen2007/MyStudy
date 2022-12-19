
比下面最初方法去掉map中间层
执行结果：
通过
显示详情
执行用时 :
532 ms
, 在所有 Java 提交中击败了
20.63%
的用户
内存消耗 :
57.8 MB
, 在所有 Java 提交中击败了
64.86%
的用户
```
class Solution {
   
        List<List<String>> res = new ArrayList<>();
	    Map<String,List<List<String>>> mid = new HashMap<>();
	    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
	    	wordList.remove(beginWord);
	        int max = 1+wordList.size();
	        if(wordList.isEmpty()||!wordList.contains(endWord))return res;
            
	        Set<String> set=new HashSet<>();
            set.add(beginWord);
	        
	        List<List<String>> midl = new ArrayList<>();
	        List<String> midl2 = new ArrayList<>();
	        midl.add(midl2);
            mid.put(beginWord,midl);
	        int cur=0;
	        while(!set.isEmpty()){
                Set<String> toremove = new HashSet<>();
	            for(String a:set) {
	            	List<List<String>> kk = mid.get(a);
                    
                    if(a.equals(endWord)){
                        for(List<String> ll2:kk) {
                            ll2.add(a);
                            res.add(ll2);
                        }
                        continue;
                    }

                    for(String b:wordList){
                        if(adj(a,b)){
                            toremove.add(b);
                            if(mid.get(b)==null) {
                                List<List<String>> midl3 = new ArrayList<>();
                                mid.put(b,midl3);
                            }
                            for(List<String> ll2:kk) {
                                List<String> ll = new ArrayList<>(ll2);
                                ll.add(a);
                                
                                mid.get(b).add(ll);
                            }
                        }
                    }
                    mid.remove(a);
	            }
                wordList.removeAll(toremove);
	            set=toremove;
	            
	            if(!res.isEmpty()||++cur>max){
	                return res;
	            }
	        }
	        return res;
	        
	    }
	    
	    private boolean adj(String a, String b){
	        int len = a.length();
	        int diff=0;
	        for(int i=0; i<len; i++){
	            if(a.charAt(i)!=b.charAt(i)){
	                diff++;
	                if(diff>1)return false;
	            }
	        }
	        return true;
	    }
}
```


执行结果：
通过
显示详情
执行用时 :
459 ms
, 在所有 Java 提交中击败了
25.11%
的用户
内存消耗 :
56.3 MB
, 在所有 Java 提交中击败了
68.92%
的用户
```
class Solution {
   
        List<List<String>> res = new ArrayList<>();
	    Map<String,Set<String>> mapping = new HashMap<>();
	    Map<String,List<List<String>>> mid = new HashMap<>();
	    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
	    	wordList.remove(beginWord);
	         int max = 1+wordList.size();
	         
	        if(wordList.isEmpty()||!wordList.contains(endWord))return res;
	        pro(Arrays.asList(beginWord),wordList);
            
	        Set<String> set=new HashSet<>();
            set.add(beginWord);
	        
	        List<List<String>> midl = new ArrayList<>();
	        List<String> midl2 = new ArrayList<>();
	        midl.add(midl2);
            mid.put(beginWord,midl);
	        int cur=0;
	        while(!set.isEmpty()){
	            Set<String> list = new HashSet<>();
	            for(String a:set) {
	            	List<List<String>> kk = mid.get(a);
	            		if(a.equals(endWord)){
                            for(List<String> ll2:kk) {
                                List<String> ll = new ArrayList<>(ll2);
                                ll.add(a);
                                res.add(ll);
                            }
                                continue;
	                    }
		                if(mapping.get(a)==null){
                            continue;
                        }
                        for(List<String> ll2:kk) {
                            List<String> ll = new ArrayList<>(ll2);
                            ll.add(a);
                            for(String b:mapping.get(a)){
                                if(mid.get(b)==null) {
                                    List<List<String>> midl3 = new ArrayList<>();
                                    mid.put(b,midl3);
                                }
                                mid.get(b).add(ll);
                                list.add(b);
                            }
                        }
	            }
	            set=list;
	            
	            if(!res.isEmpty()||++cur>max){
	                return res;
	            }
	        }
	        return res;
	        
	    }
	    
	    private void pro(List<String> beginWords,List<String> wordList){
	        Set<String> toremove = new HashSet<>();
	        for(String beginWord:beginWords){
	        	Set<String> set = new HashSet<String>();
	            mapping.put(beginWord,set);
	            for(String a:wordList){
	                if(adj(beginWord,a)){
	                    set.add(a);
	                    toremove.addAll(set);
	                }
	            }
	        }
	       
	        wordList.removeAll(toremove);
	        if(toremove.isEmpty()||wordList.isEmpty())return;
	        
	        pro(new ArrayList<String>(toremove),wordList);
	    }
	    private boolean adj(String a, String b){
	        int len = a.length();
	        int diff=0;
	        for(int i=0; i<len; i++){
	            if(a.charAt(i)!=b.charAt(i)){
	                diff++;
	                if(diff>1)return false;
	            }
	        }
	        return true;
	    }
}
```




