### 解题思路
1.找出每一个房子距离所有取暖器的最小值
2.找出所有距离的最大值
执行时间超过2000ms，肯定不是最优解，后续再更新

### 代码

```java
class Solution {
    public int findRadius(int[] houses, int[] heaters) {
    	int a = Integer.MIN_VALUE;
    	for (int i = 0; i < houses.length; i++) {
    		int b = Integer.MAX_VALUE;
    		for (int j = 0; j < heaters.length; j++) {
				b = Math.min(b, Math.abs(houses[i] - heaters[j]));
			}
    		a = Math.max(a, b);
		}
    	return a;
    }
}
```