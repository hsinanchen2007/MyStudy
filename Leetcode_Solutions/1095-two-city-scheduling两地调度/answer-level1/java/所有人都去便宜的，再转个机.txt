### 解题思路
执行用时 :1 ms, 在所有 Java 提交中击败了99.19% 的用户
内存消耗 :37.5 MB, 在所有 Java 提交中击败了100.00%的用户
	 * 核心思想：假设两城转机只需要两地花销差值（转机费），先让所有人都去便宜的城市，再让城中人少的、转机费最少的转机到另一城市
	 * 1.取所有人都去最便宜的城市的和，并记录两城的人数和每人两城的转机费。若转机为0，则不录入到城中人数，记录下转机为0的人数free（用于随意分配城市）。
	 * 2.用两城人数差减去free再除二，得到需要转机的人change
	 * 3.再从人数多的城市找出change个最少的转机费，累加得到最低花销
第一次发布题解，小白一枚，思维还比较直，写的比较繁琐。

### 代码

```java
class Solution {
    public int twoCitySchedCost(int[][] costs) {
        int sum = 0;
		int[] costA2B = new int[costs.length]; //A城换B城的花销
		int[] costB2A = new int[costs.length]; //B城换A城的花销
		int numA = 0, numB = 0; //位于A、B城的人数
		int freeChange = 0; //花销相等的人数
		for (int i = 0; i < costs.length; i++) {
			if (costs[i][0] > costs[i][1]) {
				sum += costs[i][1];
				costB2A[numB++] = costs[i][0] - costs[i][1];
			} else if ( costs[i][0] < costs[i][1]) {
				sum += costs[i][0];
				costA2B[numA++] = costs[i][1] - costs[i][0];
			}else {
				sum += costs[i][0];
				//costA2B[indexA++] = 0;
				freeChange++;
			}
		}
		Arrays.sort(costA2B); //末尾是花销
		Arrays.sort(costB2A);
		//7 4 3
		//9 4 3
		//5 4 3
		int change = (Math.abs(numA - numB) - freeChange ) / 2;
		if (change <= 0) {
			return sum;
		} else {
			//从倒数人数开始，取出最小差值
			int startA = costA2B.length - numA;
			int startB = costB2A.length - numB;
			for (int i = 0; i < change; i++) {
				//哪个城人少，就加上另一城转当前城的花销差
				if (numA < numB) {
					sum += costB2A[startB++];					
				} else {
					sum += costA2B[startA++];
				}
			}
		}
		return sum;
    }
}
```