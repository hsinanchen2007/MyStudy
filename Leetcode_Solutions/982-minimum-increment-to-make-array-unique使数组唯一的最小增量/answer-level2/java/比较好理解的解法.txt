执行用时 :5 ms, 在所有 Java 提交中击败了97.81%的用户
内存消耗 :46.1 MB, 在所有 Java 提交中击败了90.20%的用户
### 解题思路
cnts对每一个数字出现次数计数
遍历记数数组，每一层重复的元素只有一个元素不需要加一，其他的都得加一次，所以是cnts[i]-1
而每一层cnts[i]-1个元素加完一以后则属于下一个数的重复元素，所以是cnts[i+1] += (cnts[i] - 1)
最后一个while循环是看最后一个数字40000是否本身有重复元素，如果有也得再按照上面步骤算一遍。
### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
		int cnts[] = new int[40002] ;
		int ans = 0 ;
		for(int i=0;i<A.length;i++) {
			cnts[A[i]]++ ;
		}
		for(int i=0;i<40001;i++) {
			if(cnts[i]!=0) {
				ans += cnts[i] - 1 ;
				cnts[i+1] += (cnts[i] - 1) ;
			}
		}
		int fnl = cnts[40001] ;
		if(fnl!=0) {
			while(fnl!=0) {
				ans += (fnl-1) ;
				fnl-- ;
			}
		}
		return ans ;
    }
}
```