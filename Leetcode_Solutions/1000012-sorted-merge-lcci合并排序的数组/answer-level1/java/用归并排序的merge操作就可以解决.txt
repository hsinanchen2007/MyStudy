### 解题思路
归并排序，分到最后，就要合，合的时候，就是弄一个空的，然后前后两个儿子进行比较，归并排序有一个不一样的地方的话，是他的序号，这里是简版，不用去关心序号的问题，因为在归并里面，有的儿子是从3到6这种的，所以需要注意。

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
            int maxLength = m+n;
		  int[] temp = new int[maxLength];
		  int aStart = 0;
		  int bStart = 0;
		  for(int i =0 ;i<maxLength;i++){
			  if(aStart>=m){
				  temp[i]=B[bStart];
				  bStart++;
			  } else
			  if(bStart>=n){
				  temp[i]=A[aStart];
				  aStart++;
			  } else
			  if(A[aStart]>=B[bStart]){
				  temp[i] = B[bStart];
				  bStart++;
			  }else{
				  temp[i] = A[aStart];
				  aStart++;
			  }
		  }
		  System.arraycopy(temp, 0, A, 0, A.length);
    }
}
```