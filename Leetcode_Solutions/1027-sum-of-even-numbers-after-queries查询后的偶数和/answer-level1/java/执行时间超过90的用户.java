### 解题思路
1、设置变量sum，将开始的偶数和求出
2、设置变量ans数组，开始遍历queries数组
3、若是当前位置对应的A中元素本来是偶数，那么先在sum中减去这个偶数，若是A中对应元素加上对应的数值之后是偶数，那么加上这个偶数，并将更新后的sum存储到ans中
4、返回ans即可

### 代码

```java
class Solution {
    public int[] sumEvenAfterQueries(int[] A, int[][] queries) {
        int sum=0;
		  for(int i=0;i<A.length;i++)
	     {
	    	 if(A[i]%2==0)
	    		 sum+=A[i];
	     }
		  int[] ans=new int[queries.length];
		  for(int i=0;i<queries.length;i++)
		  {
			  if(A[queries[i][1]]%2==0)
				  sum-=A[queries[i][1]];
			  A[queries[i][1]]+=queries[i][0];
			  if(A[queries[i][1]]%2==0) sum+=A[queries[i][1]];
			  ans[i]=sum;
		  }
		  return ans;
    }
}
```