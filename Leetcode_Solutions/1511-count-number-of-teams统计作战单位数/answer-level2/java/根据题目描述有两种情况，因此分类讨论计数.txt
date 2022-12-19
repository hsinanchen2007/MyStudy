### 解题思路
根据描述，有两种情况：
从大到小；从小到大
即`rating[i]>rating[j]>rating[k] 或者 rating[i]<rating[j]<rating[k]`
先确定中间j的取值范围为`1<=j<=rating.length-2`
以下分情况讨论：
`1.若rating[i]<rating[j]  --> 判断为从小到大的情况  --> rating[j]<rating[k]`
`2.若rating[i]>rating[j]  --> 判断为从大到小的情况  --> rating[j]>rating[k]`

### 代码

```java
class Solution {
    public int numTeams(int[] rating) {
        int count = 0;
		// 分为两种情况：1.从大到小；2.从小到大
		for (int j = 1; j < rating.length - 1; j++) {// 中间士兵从1到len-2
			for (int i = 0; i < j; i++) {
				// i的数大于j的数，则k的数应小于j的数
				if (rating[i] > rating[j]) {
					for (int k = rating.length - 1; k > j; k--) {
						if (rating[j] > rating[k]) {
							count++;
						}
					}
				} else if(rating[i] < rating[j]){// i的数小于j的数，则k的数大于j的数
					for (int k = rating.length - 1; k > j; k--) {
						if (rating[j] < rating[k]) {
							count++;
						}
					}
				}

			}
		}
		return count;
    }
}
```