### 解题思路
思路很简单，将所有数出现的次数存入一个HashMap中即可。然后判断所有值是否有公约数（需要>2）
这就意味着要先找到map中最小的value，然后保存value的所有不小于2的约数，然后逐个判断，能否除以map中所有的value(即都能平均分组)。
唯一的创意点在于：用一个flag保存map中整除的次数，当整除的次数恰好等于map的size，那就意味着所有数都可以按照X的大小分为若干份。若未整除，肯定有至少一个不能平分，这种情况不合适。
所以最后若未及时返回true，就只能返回false了。
### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
		int len = deck.length;
		if (len<2) return false;
		
		int min = Integer.MAX_VALUE; // map键值对中最小的值
		HashMap<Integer, Integer> map = new HashMap<>();
		// 将所有数出现的次数存入HashMap中
		for (int i=0; i<len; ++i) {
			int cur = deck[i];
			if (! map.containsKey(cur)) map.put(cur, 1);
			else map.put(cur, map.get(cur)+1);
		}
		// 找出出现次数最小的数，那么X的取值一定是这个数的约数
		for (int v : map.values()) min = Math.min(min, v);
		if (min < 2) return false;
		// 求出min的所有约数，然后逐个代入尝试
		ArrayList<Integer> list = new ArrayList<>();
		list.add(min); // 自身也是约数，先放入
		for (int v=2; v<=min/2; ++v) {
			if (min % v == 0) list.add(v);
		} 
		for (int value : list) {
			int flag = 0;
			for (int v : map.values()) {
				if (v % value != 0) break;
				flag ++;
			}
			if (flag == map.size()) return true;
		}
		return false;
    }
}
```