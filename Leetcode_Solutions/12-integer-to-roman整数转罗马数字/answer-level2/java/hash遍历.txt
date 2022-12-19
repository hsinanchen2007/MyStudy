### 解题思路
执行用时 :
21 ms
内存消耗 :
42.1 MB
使用哈希表，对当前数整除，就是对应存在多少个罗马字符：若能，则s加上整除的个数乘以值；若不能，则遍历下一个。

### 代码

```java
class Solution {
    public String intToRoman(int num) {
		Map<Integer,String> rmap = new TreeMap<>(new Comparator<Integer>() {
			@Override
			public int compare(Integer o1, Integer o2) {
				return o2.compareTo(o1);
			}
		});
		rmap.put(1000,"M");
		rmap.put(900,"CM");
		rmap.put(500,"D");
		rmap.put(400,"CD");
		rmap.put(100,"C");
		rmap.put(90,"XC");
		rmap.put(50,"L");
		rmap.put(40,"XL");
		rmap.put(10,"X");
		rmap.put(9,"IX");
		rmap.put(5,"V");
		rmap.put(4,"IV");
		rmap.put(1,"I");
		StringBuffer buf = new StringBuffer();
		for (Integer item : rmap.keySet()) {
			int re =num/item;
			if(re == 0 ){
				continue;
			}
			for (int i = 1; i < re+1; i++) {
				buf.append(rmap.get(item));
			}
			num = num % item;

		}
		String roman = new String(buf);
		return roman;

	}
}
```