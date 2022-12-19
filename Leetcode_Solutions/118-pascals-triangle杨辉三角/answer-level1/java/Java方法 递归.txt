执行用时 :1 ms, 在所有 Java 提交中击败了99.81%的用户
内存消耗 :33.7 MB, 在所有 Java 提交中击败了30.97%的用户
```
List<List<Integer>> listw = new ArrayList<List<Integer>>();

public List<List<Integer>> generate(int numRows) {
	List<Integer> listn = new ArrayList<Integer>();
	if(numRows == 0) return listw;
	generate(numRows-1);
	for(int i = 0; i < numRows; i++)
	{
		if(i == 0)
		{
			listn.add(1);
			continue;
		}
		else if(i == numRows-1)
		{
			listn.add(1);
			continue;
		}
		else if(i == numRows-2)
		{
			listn.add(listw.get(numRows-2).get(i-1)+ 1);
			continue;
		}
		else
		{
			listn.add(listw.get(numRows-2).get(i-1)+listw.get(numRows-2).get(i));
		}
	}
	listw.add(listn); 
	return listw;
}
```

