```

class Solution {
	static boolean[] used;
    public String[] permutation(String S) {
    	List<String> list = new ArrayList<>();
    	used = new boolean [S.length()];
    	char[] tmp = S.toCharArray();
    	Arrays.sort(tmp);
    	String t = "";
    	for(int i = 0 ; i< S.length();i++) {
    		t+=tmp[i];
    	}
    	dfs(t,0,S.length(),list,new StringBuilder());
    	String [] res = new String [list.size()];
    	for(int i = 0 ;i<list.size();i++) {
    		res[i]=list.get(i);
    	}
    	return res;
    }
    public void dfs(String str,int floor, int n,List<String> list,StringBuilder path) {
    	if(floor >= n) {
    		list.add(path.toString());
    	}
    	for(int i = 0 ; i<str.length();i++) {
    		if(!used[i]) {
    			if(i>0&&str.charAt(i)==str.charAt(i-1)&&used[i-1])
    				return;
    			used[i] = true;
    			path.append(str.charAt(i));
    			dfs(str,floor+1,n,list,path);
    			used[i] = false;
    			path.deleteCharAt(path.length()-1);
    		}
    	}
    }
    public static  void main(String[] args) {
    	Solution x = new Solution();
    	x.permutation("qwe");
    }
}
```
