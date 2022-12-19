### 解题思路
我大概看了一下题解，好像没有我这么写的。我的想法是按照indexes，从大到小处理字符串，这样就不会因为前面的长度变化而有影响了。还有就是按照其他大佬的代码稍微优化了一下。
发现了稍微有意思的东西。我第一次提交的原始代码，后面三次都是优化后的。
![TIM图片20200129212948.png](https://pic.leetcode-cn.com/9737b4451a1931619334509c322422e19a93c599c92ed56eb543c8e1018e0a2e-TIM%E5%9B%BE%E7%89%8720200129212948.png)

### 代码
初始的
```java
class Solution {
    public String findReplaceString(String S, int[] indexes, String[] sources, String[] targets) {
        String res=S;
        StringBuilder sb=new StringBuilder(S);
        for(int i=0;i<indexes.length;i++)
        {
        	for(int j=i+1;j<indexes.length;j++)
        	{
        		if(indexes[i]<indexes[j])
        		{
        			int m=indexes[i];
        			indexes[i]=indexes[j];
        			indexes[j]=m;
        			String s=sources[i];
        			sources[i]=sources[j];
        			sources[j]=s;
        			s=targets[i];
        			targets[i]=targets[j];
        			targets[j]=s;
        		}
        	}
        }
        for(int i=0;i<indexes.length;i++)
        {
        	int index=indexes[i];
        	String source=sources[i],target=targets[i];
        	if(S.indexOf(source,index)==index)
        	{
        		sb.replace(index,index+source.length(),target);
        	}
        }
        //System.out.println(sb);
        res=sb.toString();
        return res;
    }
}
```
优化后的
```
class Solution {
    public String findReplaceString(String S, int[] indexes, String[] sources, String[] targets) {
        String res=S;
        TreeMap<Integer,Integer> tm=new TreeMap();
        TreeSet<Integer> ts=new TreeSet();
        for(int i=0;i<indexes.length;i++)
        {
        	tm.put(indexes[i],i);
        	ts.add(indexes[i]);
        }
        StringBuilder sb=new StringBuilder(S);
        	
        while(!ts.isEmpty())
        {
        	
        	int i=tm.get(ts.pollLast()),index=indexes[i];
        	String source=sources[i],target=targets[i];
        	if(S.indexOf(source,index)==index)
        	{
        		sb.replace(index,index+source.length(),target);
        	}
        }
        //System.out.println(sb);
        res=sb.toString();
        return res;
    }
}
```
