### 解题思路
    前两行是固定的，后面的只需要利用前面的即可，其实每一行都是对称的，所以还可以继续改进，只需要赋值到一半的位置，后面一般的位置进行复制即可。

### 代码

```java
class Solution {
    public List<List<Integer>> generate(int numRows) {
         List<List<Integer>> ans=new ArrayList<List<Integer>>();
	      if(numRows==0) return ans;
	      if(numRows==1) 
	      {
	    	  List<Integer> tmp=Arrays.asList(1);
	    	  ans.add(tmp);
	    	  return ans;
	      }
	    	  List<Integer> tmp=Arrays.asList(1);
	    	  ans.add(tmp); 
	    	  List<Integer> tmp2=Arrays.asList(1,1);
	    	  ans.add(tmp2);
	    	  if(numRows==2)
	    	  return ans;
	      for(int i=2;i<numRows;i++)
	      {
	    	  List<Integer> t=new ArrayList<Integer>();
	    	  for(int j=0;j<=i;j++)
	    	  {
	    		  if(j==0||j==i)
	    			  t.add(1);
	    		  else
	    			  t.add(ans.get(i-1).get(j-1)+ans.get(i-1).get(j));
	    	  }
	    	  ans.add(t);
	      }
	     return ans;
    }
}
```