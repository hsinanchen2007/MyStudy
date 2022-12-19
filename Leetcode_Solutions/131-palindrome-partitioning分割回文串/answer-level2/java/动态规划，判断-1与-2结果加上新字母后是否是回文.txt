执行结果：
通过
显示详情
执行用时 :
5 ms
, 在所有 Java 提交中击败了
94.03%
的用户
内存消耗 :
38.7 MB
, 在所有 Java 提交中击败了
97.10%
的用户
```
class Solution {
     public List<List<String>> partition(String s) {
	        List<List<String>> res = new ArrayList<List<String>>();
	        if(s.length()==0)return res;
	        List<String> l1 = new ArrayList<String>();
	        l1.add(s.substring(0,1));
	        res.add(l1);
	        char[] cs = s.toCharArray();
	        for(int i=1; i<s.length(); i++){
	        	 List<List<String>> subres = new ArrayList<List<String>>();
	            String a = String.valueOf(cs[i]);
	            for(int j=0; j<res.size(); j++){
	                List<String> jl = res.get(j);
	                int size = jl.size();
	                if(get(jl.get(size-1)+a)){
	                    List<String> new1 = new ArrayList<>(jl);
	                    new1.remove(size-1);
	                    new1.add(jl.get(size-1)+a);
	                    subres.add(new1);
	                }else if(size-2>=0){
	                   if(get(jl.get(size-2)+jl.get(size-1)+a)){
	                        List<String> new1 = new ArrayList<>(jl);
	                        new1.add(jl.get(size-2)+jl.get(size-1)+a);
	                        new1.remove(size-1);
	                        new1.remove(size-2);
	                        subres.add(new1);
	                    }
	                }
	                jl.add(a);
	            }
	            res.addAll(subres);
	        }
	        return res;
	    }
	    private boolean get(String s){
	        int len = s.length()-1;
	        int h = (len)/2;
	        int i=0;
	        while(i<=h){
	            if(s.charAt(i)!=s.charAt(len-i)){
	                return false;
	            }
	            i++;
	        }
	        return true;
	    }
}
```
