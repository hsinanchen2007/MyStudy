改成用其实位置标记后，比之前快了一些。。
执行结果：
通过
显示详情
执行用时 :
103 ms
, 在所有 Java 提交中击败了
5.04%
的用户
内存消耗 :
55.4 MB
, 在所有 Java 提交中击败了
5.69%
的用户
```
class Solution {
    int index = 1;
	 Map<Integer,Boolean> map = new HashMap<Integer,Boolean>();
    String ss1=null;
    String ss2=null;
	    public boolean isScramble(String s1, String s2) {
	        int l1 = s1.length();
	        if(l1!=s2.length())return false;
	        int x = l1;
	        while(x>0) {
	        	index*=10;
	        	x=x/10;
	        }
            ss1=s1;
            ss2=s2;
	        return cal(0,l1,0,l1);
	    }
	    private boolean cal(int s1s,int s1e, int s2s, int s2e){
	        String s1 = ss1.substring(s1s,s1e);
	        String s2 = ss2.substring(s2s,s2e);
	        int l1 = s1e-s1s;
	        if(l1==0)return true;
	        
	        if(s1.equals(s2))return true;
	        if(l1==1){
	            return s1.equals(s2);
	        }
	        Integer sb = s1s*index*index+s2s*index+l1;
	        if(map.get(sb)!=null){
	            return map.get(sb);
	        }
	        for(int middle=1;middle<l1;middle++){
	            boolean res = cal(s1s,s1s+middle,s2s,s2s+middle)&&cal(s1s+middle,s1e,s2s+middle,s2e)||
	                cal(s1s,s1s+middle,s2e-middle,s2e)&&cal(s1s+middle,s1e,s2s,s2e-middle);
	            if(res){
	                map.put(sb,true);
	                return true;
	            }
	        }
	        map.put(sb,false);
	        return false;
	    }
}
```

直接迭代计算超时，所以用map记录已经计算过的字符串，后续可以优化为<开始，结束>位置记录。

执行结果：
通过
显示详情
执行用时 :
187 ms
, 在所有 Java 提交中击败了
5.04%
的用户
内存消耗 :
77.5 MB
, 在所有 Java 提交中击败了
5.69%
的用户
```
class Solution {
    Map<String,Boolean> map = new HashMap<String,Boolean>();
    public boolean isScramble(String s1, String s2) {
        if(s1.length()!=s2.length())return false;
        return cal(s1,s2);
    }
    private boolean cal(String s1, String s2){
        int l1 = s1.length();
        if(l1==0)return true;
        
        if(s1.equals(s2))return true;
        if(l1==1){
            return s1.equals(s2);
        }
        if(map.get(s1+"-"+s2)!=null){
            return map.get(s1+"-"+s2);
        }
        for(int middle=1;middle<l1;middle++){
            boolean res = cal(s1.substring(0,middle),s2.substring(0,middle))&&cal(s1.substring(middle,l1),s2.substring(middle,l1))||
                cal(s1.substring(0,middle),s2.substring(l1-middle,l1))&&cal(s1.substring(middle,l1),s2.substring(0,l1-middle));
            if(res){
                map.put(s1+"-"+s2,true);
                return true;
            }
        }
        map.put(s1+"-"+s2,false);
        return false;
        
    }
}
```
