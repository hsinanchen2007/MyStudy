 越界时表示比较到最短的字符串后面，比较应该就结束了，可用越界的异常来判断是否结束。

```
public static String longestCommonPrefix(String[] strs) {
		if(strs.length==0)
			return new String("");
		int size=strs.length;
		int i,j,max=0;
		try
		{
			for(j=0;;j++)
			{
				for(i=0;i<size;i++)
				{
					if(strs[0].charAt(j)!=strs[i].charAt(j))
						return strs[0].substring(0,max);
				}
				max++;	
				
			}
		}catch(StringIndexOutOfBoundsException e) //越界表示查找结束 直接返回
		{
			return strs[0].substring(0,max);
		}
		
		  
        
}
```



不知道这么写有什么坏处，还请大神指导 ，嘿嘿