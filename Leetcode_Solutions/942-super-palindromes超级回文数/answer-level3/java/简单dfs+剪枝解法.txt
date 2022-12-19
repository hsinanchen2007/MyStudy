### 解题思路
思路都在代码里面了,这个题考的是数学思维
by the way,提交的时间有点奇怪

![image.png](https://pic.leetcode-cn.com/dd50906b4a2c8dfd42829cd67524c331a8365d45bee8e708e94d4dce39f4909e-image.png)

### 代码

```java
class Solution {
   public int superpalindromesInRange(String L, String R) {

		int len = R.length();
		long a = new Long(L);
		long b = new Long(R);

		list.add(1L);
		list.add(4L);
		list.add(9L);
		list.add(121L);
		list.add(484L);
		for (int i = 3; i <= Math.min(9, len/2+1); i++) {

			char[] cs = new char[i];

			for (int j = '1'; j <= '2'; j++) {//首尾巴位只能是1或者2,很容易通过观察证明^_^
				Arrays.fill(cs, '0');
				cs[0] = (char) j;
				cs[i - 1] = (char) j;
				func(cs, 1, i - 2);
			}
		}

		int res = 0;
		for (long l : list) {
			if (l >= a && l <= b) {
				res++;
			}
		}
		return res;
	}

	List<Long> list = new ArrayList<>();

	void func(char[] cs, int start, int end) {
		if (end < start) {
            long l=new Long(new String(cs)) ;
			if (check(l*l)) {
				list.add(l*l);
			}
			return;
		}
		for (int i = '0'; i <= '3'; i++) {
			cs[start] = (char) i;
			cs[end] = (char) i;
			func(cs, start + 1, end - 1);
		}
	}
    	boolean check(long l) {
		if (l < 0) {
			return false;
		}
		String s = l + "";
		for (int i = 0; i < s.length() / 2; i++) {
			if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
				return false;
			}
		}
		return true;
	}
}
```