### 解题思路
1.高赞解释牛皮
2.高赞解释牛皮
3.高赞解释牛皮

0.最后返回的数字A的下标一定是0
1.A在上一轮的下标可以用当前下标index，步长m，上一轮数组长度i来计算：
index = (index + m) % i
### 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {
    	int index = 0;
    	for (int i = 2; i <= n; i++) {
			index = (index + m) % i;
		}
    	return index;
    }
}
```