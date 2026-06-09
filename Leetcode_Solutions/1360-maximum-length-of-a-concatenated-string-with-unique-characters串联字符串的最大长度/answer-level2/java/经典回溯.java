直接枚举当前要用的串即可，当前的串能用的条件是该串的所有字母在之前所有要用的串里都没出现过。
因此我们开一个标记数组标记每个字母出没出现过即可。
```
class Solution {
	int ans;
	boolean[] flag;
    public int maxLength(List<String> arr) {
    	ans=0;
    	boolean[] a=new boolean[30];
    	flag=new boolean[arr.size()];
    	for(int i=0;i<arr.size();i++)
    		for(int j=0;j<arr.get(i).length();j++)
    			for(int k=j+1;k<arr.get(i).length();k++)
    				if(arr.get(i).charAt(j)==arr.get(i).charAt(k)) {
    					flag[i]=true;
    					break;
    				}
    					
    	for(int i=0;i<arr.size();i++) {
    		if(flag[i]) continue;
    		flag[i]=true;
    		dfs(0,i,arr,a);
    		flag[i]=false;
    	}
    	return ans;
    }
    
    private void dfs(int sum,int id,List<String> arr,boolean[] a) {
    	if(id==arr.size()) return;
    	for(int i=0;i<arr.get(id).length();i++) {
    		if(a[arr.get(id).charAt(i)-'a']) {
    			for(int j=0;j<i;j++) a[arr.get(id).charAt(j)-'a']=false;
    			return;
    		}
    		a[arr.get(id).charAt(i)-'a']=true;
    	}
    	ans=Math.max(ans, sum+arr.get(id).length());
    	for(int i=id+1;i<arr.size();i++) {
    		if(flag[i]) continue;
    		flag[i]=true;
    		dfs(sum+arr.get(id).length(),i,arr,a);
    		flag[i]=false;
    	}
    	for(int i=0;i<arr.get(id).length();i++) {
    		a[arr.get(id).charAt(i)-'a']=false;
    	}
    }
}
```
