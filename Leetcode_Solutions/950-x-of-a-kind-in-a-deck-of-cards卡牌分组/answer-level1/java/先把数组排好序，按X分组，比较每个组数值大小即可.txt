### 解题思路
1.该题的意思是说是否把整副牌分成x组并且每组牌的数值都一样
2.运用枚举的方法，把每个X都试一遍，2<=X<=deck.length
3.比较每组中的数值是否一样。刚开始我还想把每组都分出来，但是只要记录每组的标兵就可以比较了
4.break的用法是跳出一个循环，这里我们也可以用continue去找到指定循环

### 代码

```java
public class Solution {
	public boolean hasGroupsSizeX(int[] deck) {
		Arrays.sort(deck);
		int m = 0;
		int x;
		search:for (x = 2; x <= deck.length; x++) {
			if (deck.length % x == 0) {
				for (int i = 0; i < deck.length; i++) {
					if (i % x == 0) {
						m = deck[i];
					}
					if (deck[i] != m) {
						continue search;
					} else if (i == deck.length - 1) {
						return true;
					}
				}
			} else {
				continue;
			}
		}
		return false;
	}
}


```