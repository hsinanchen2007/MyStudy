其实第一眼看上去就是回溯，乘法的部分需要细心地处理一下，其他没什么难点。
```
class Solution {
	List<String> ans=new ArrayList();
    public List<String> addOperators(String num, int target) {
    	
    	if(num.length()==0) return new ArrayList<String>();
    	
    	List<Integer> list1=new ArrayList();
    	List<Character> list2=new ArrayList();
    	
        dfs(0,num.length(),target,num,new StringBuilder(),list1,list2);
        
        return ans;
    }
    
    private void dfs(int nowlen,int len,int target,String num,StringBuilder str,List<Integer> list1,List<Character> list2)
    {
    	if(nowlen==len)
    	{
    		List<Integer> list3=new ArrayList();
    		List<Character> list4=new ArrayList();
    		//System.out.println(list1); System.out.println(list2);
    		//if(list1.size()<=1) return;
    		while(!list2.isEmpty() && list2.get(list2.size()-1)=='*')
    		{
    			int tmp1=list1.get(list1.size()-1);
    			int tmp2=list1.get(list1.size()-2); 
    			list3.add(tmp1); list3.add(tmp2);
    			list1.remove(list1.size()-1); 
    			list1.remove(list1.size()-1);
    			list1.add(tmp1*tmp2); list4.add('*');
    			list2.remove(list2.size()-1);
    		}
    		if(check(list1,list2,target))
    			ans.add(str.toString());
    		if(list3.size()>0) list1.remove(list1.size()-1);
    		for(int i=list3.size()-1;i>=0;i--) list1.add(list3.get(i));
    		for(int i=0;i<list4.size();i++) list2.add(list4.get(i));
    		return;
    	}
    	
    	if(nowlen==0)
    	{
    		str.append(num.charAt(nowlen));
        	list1.add(num.charAt(nowlen)-'0');
    		dfs(nowlen+1,len,target,num,str,list1,list2);
    	}
    	else
    	{
    		int temp=list1.get(list1.size()-1);
    		int nownum=temp*10+(num.charAt(nowlen)-'0');
    		if(temp>0 && nownum>0)
    		{
        		str.append(num.charAt(nowlen));
	    		list1.remove(list1.size()-1);
	    		list1.add(nownum);
	    		dfs(nowlen+1,len,target,num,str,list1,list2);
	    		str.deleteCharAt(str.length()-1);
	    		list1.remove(list1.size()-1);
	    		list1.add(temp);
    		}
    		boolean flag=false;
    		List<Integer> list3=new ArrayList();
    		List<Character> list4=new ArrayList();
    		while(!list2.isEmpty() && list2.get(list2.size()-1)=='*')
    		{
    			flag=true;
    			int tmp1=list1.get(list1.size()-1);
    			int tmp2=list1.get(list1.size()-2); 
    			list3.add(tmp1); list3.add(tmp2);
    			list1.remove(list1.size()-1); 
    			list1.remove(list1.size()-1);
    			list1.add(tmp1*tmp2); list4.add('*');
    			list2.remove(list2.size()-1);
    		}
    		str.append('+');
    		str.append(num.charAt(nowlen));
    		list1.add(num.charAt(nowlen)-'0');
    		list2.add('+');
    		dfs(nowlen+1,len,target,num,str,list1,list2);
    		str.deleteCharAt(str.length()-1);
    		str.deleteCharAt(str.length()-1);
    		if(!list1.isEmpty()) list1.remove(list1.size()-1);
    		if(!list2.isEmpty()) list2.remove(list2.size()-1);
    		str.append('-');
    		str.append(num.charAt(nowlen));
    		list1.add(num.charAt(nowlen)-'0');
    		list2.add('-');
    		dfs(nowlen+1,len,target,num,str,list1,list2);
    		str.deleteCharAt(str.length()-1);
    		str.deleteCharAt(str.length()-1);
    		if(!list1.isEmpty()) list1.remove(list1.size()-1);
    		if(!list2.isEmpty()) list2.remove(list2.size()-1);
    		str.append('*');
    		str.append(num.charAt(nowlen));
    		list1.add(num.charAt(nowlen)-'0');
    		list2.add('*');
    		dfs(nowlen+1,len,target,num,str,list1,list2);
    		str.deleteCharAt(str.length()-1);
    		str.deleteCharAt(str.length()-1);
    		if(!list1.isEmpty()) list1.remove(list1.size()-1);
    		if(!list2.isEmpty()) list2.remove(list2.size()-1);
    		
    		if(flag)
    		{
    			list1.remove(list1.size()-1);
    	   		for(int i=list3.size()-1;i>=0;i--) list1.add(list3.get(i));
        		for(int i=0;i<list4.size();i++) list2.add(list4.get(i));
    		}
    	}
    }
    
    private boolean check(List<Integer> list1,List<Character> list2,int target)
    {
    	int sum=list1.get(0);
    	for(int i=1;i<list1.size();i++)
    	{
    		char c=list2.get(i-1);
    		int tmp=list1.get(i);
    		if(c=='+')
    			sum=sum+tmp;
    		else
    			sum=sum-tmp;
    	}
    	return sum==target;
    }
}
```
