### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
   public int canCompleteCircuit(int[] gas, int[] cost) {
		for (int i = 0; i < gas.length; i++) {
			int index = i; // 尝试从i开始走
			int origin = gas[i];// 在i处加满油,gas[i]
			while (true) {
				if (origin < cost[index]) {// 到不了下一站i+1,
					break;
				} else {
					origin = origin - cost[index];// 减去到i+1耗费的油量
					if (index == gas.length - 1) {// 如果上个节点是最后一个节点，到达下一个节点则是0，做个判断
						index = -1;
					}
					origin = origin + gas[index + 1];// 到新的节点可以进行补给了
					index++;// 更新到达节点
					if (index == i) {//如果走了一圈又回到了i
						return i;
					}
				}
			}
		}
		return -1;
	}
}
```