题目不难，就是坑点较多，我们根据\t进行分层，然后要记得可能会用空格代替\t，因此你需要提前将串整理好，然后将父目录与子目录或者文件连边，跑一边dfs求最大值即可，当然你要标记形成的数的树根是不是文件哦！
```
import java.util.Vector;
class Solution {
    int len=0;
    int[] a;
    int[] dp;
    Map<Integer,String> map=new HashMap<>();
    Map<Integer,List<Integer>> map1=new HashMap<>();
    Vector<Integer>[] q;
    public int lengthLongestPath(String input) {
    	int n=input.length();
    	a=new int[n];
    	StringBuilder str=new StringBuilder();
    	boolean flag=false;
    	int sum=0;
    	for(int i=0;i<input.length();i++) {
    		if(input.charAt(i)==' ') {
    			if(flag) {
    				if(sum<4) sum++;
    				else {flag=false;sum=0;}
    			}
    			if(i>0 && input.charAt(i-1)=='\n') {
    				flag=true;
    				str.append('\t');
    				sum=1;
    			}
    			else if(!flag)
    				str.append('a');
    			continue;
    		}
    		flag=false; sum=0;
    		str.append(input.charAt(i));
    	}
    	input=str.toString();
    	n=input.length();
    	str.delete(0,str.length());
        for(int i=0;i<n;i++) {
        	if(input.charAt(i)=='\t') 
        		continue;
        	if(input.charAt(i)=='\n')
        	{
        		if(str.length()==0) continue;
        		map.put(len++, str.toString());
        		str.delete(0, str.length());
        		continue;
        	}
        	if(str.length()==0) a[i]=len;
        	str.append(input.charAt(i));
        	if(i+1==n) {
        		if(str.length()==0) continue;
    			map.put(len++, str.toString());
    			str.delete(0, str.length());
    			continue;
        	}
        }
        int num=0;
        flag=false;
        dp=new int[len+1];
    	q=new Vector[len+1];
    	for(int i=0;i<=len;i++) q[i]=new Vector();
        map1.put(0, new ArrayList<>());
        map1.get(0).add(0);
        for(int i=0;i<n;i++) {
        	if(input.charAt(i)=='\t') {
        		flag=false;
        		num++;
        	}
        	if(input.charAt(i)=='\n') continue;
        	if(input.charAt(i)!='\t') {
        		if(num>0) {
	        		if(flag) continue;
	        		if(!map1.containsKey(num))
	        			map1.put(num, new ArrayList<Integer>());
	        		map1.get(num).add(a[i]);
	        		int p=map1.get(num-1).get(map1.get(num-1).size()-1);
	        		q[p].add(a[i]);
	        		flag=true;
	        		num=0;
        		}
        		else if(i>0 && input.charAt(i-1)=='\n')
        			map1.get(0).add(a[i]);
        	}
        }
        boolean mark=false;
        for(String s : map.values())
        	for(int i=0;i<s.length();i++) {
        		if(s.charAt(i)=='.' && i<s.length()-1)
        			mark=true;
        	}
        if(!mark) return 0;
        int ans=0;
        for(int i=0;i<map1.get(0).size();i++)
        	ans=Math.max(ans, dfs(map1.get(0).get(i)));
        return ans;
    }
    
    private int dfs(int id) {
    	dp[id]=map.get(id).length();
    	int tmp=0;
    	boolean flag=false;
    	for(int i=0;i<q[id].size();i++) {
    		flag=true;
    		tmp=Math.max(tmp, dfs(q[id].get(i))+1);
    	}
    	if(!flag && !map.get(id).contains(".")) 
    		dp[id]=Integer.MIN_VALUE; 
    	return dp[id]+tmp;
    }
}

```
