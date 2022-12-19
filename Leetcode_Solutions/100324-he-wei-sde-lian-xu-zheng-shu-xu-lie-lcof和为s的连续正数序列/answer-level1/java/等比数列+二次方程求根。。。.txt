执行用时 :14 ms, 在所有 Java 提交中击败了15.32%的用户
内存消耗 :37.4 MB, 在所有 Java 提交中击败了100.00%的用户
### 解题思路
先枚举起始位置的数字，利用二次方程求根式求末尾那个数字。用long是怕数字大了溢出。
### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
		List<int[]> list = new ArrayList<>();
		for(long i=1;i<target;i++) {
			if((target-i)<i)
				break ;
			long b24ac = 1-(4*( (-(i*i)) + i -(2*target) )) ;
			if(b24ac<0 || b24ac%((int)(Math.sqrt(b24ac)))!=0 )
				continue ;
			int b_b24ac = -1 + (int)(Math.sqrt(b24ac)) ;
			if(b_b24ac<0 || b_b24ac%2!=0)
				continue ;
			int e = b_b24ac/2 ;
			int nums[] = new int[(int)(e-i+1)] ;
			int temp = (int)i ;
			for(int j=0;j<((int)(e-i+1));j++,temp++) {
				nums[j] = temp ;
			}
			list.add(nums) ;
		}

		int[][] ans =new int[list.size()][] ;
		for(int i=0;i<list.size();i++) {
			ans[i] = list.get(i) ;
		}
		return ans ;
//		return list.toArray(new int[0][]);
    }
}
```