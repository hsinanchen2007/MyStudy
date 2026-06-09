### 解题思路
先对数组进行快速排序
用一个从数组长度开始递减的整数k来表示每组的个数
如果deck.length%k == 0，说明数组正好能够被分为num = deck.length/k组
因为数组已经排好序了，我们只需要检测分成的每组数字中的第一个数字和最后一个数字是否相等，若每一组的第一个数字和最后一个数字都相等，及返回true；若有一组不相等，就k--，执行下一次取余操作

### 代码

```java
class Solution {
   public boolean hasGroupsSizeX(int[] deck) {
		Arrays.sort(deck);
		int k = deck.length;
		while(k>1) {
			if(deck.length%k==0) {
				int num = deck.length/k;
				for(int i = 0;i<num;i++) {
					if(deck[i*k]!=deck[i*k+k-1]) {
						break;
					}
					if(i == num-1&&deck[i*k]==deck[i*k+k-1]) {
						return true;
					}
				}
			}
			k--;
		}
		return false;
    }
}
```