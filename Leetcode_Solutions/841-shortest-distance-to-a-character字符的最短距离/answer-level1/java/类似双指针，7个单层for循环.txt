执行用时 :1 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :36.2 MB, 在所有 Java 提交中击败了84.48%的用户

先分别找两边出现的第一个C，也可以用S.IndexOf(C)找。
两边第一次出现C之前的最近距离是分别直接减去两边第一次出现的角标值。
中间的字符串分别左右遍历一遍，取最小值。
加起来七次单层for，有点乱，但可以用打包起来的方法简化，思路是这样。
```
class Solution {
    public int[] shortestToChar(String S, char C) {
        
        int[] Lans = new int[S.length()];
		int[] Rans = new int[S.length()];
		int Lfirst = 0;
		int Rfirst = S.length() - 1;
		int [] ans = new int[S.length()];
		
		for (int i = 0; i < S.length(); i++) {
			if (S.charAt(i) == C) {
				Lfirst = i;
				break;
			}
		}
		for (int i = S.length() - 1; i >= 0; i--) {
			if (S.charAt(i) == C) {
				Rfirst = i;
				break;
			}
		}
        
        
		for (int i = 0; i <= Lfirst; i++) {
			ans[i] = Lfirst - i;
		}
		for (int i = S.length() - 1; i >= Rfirst; i--) {
			ans[i] = i - Rfirst;
		}

        
		int p = Lfirst;
		for (int i = Lfirst + 1; i <= Rfirst - 1; i++) {
			if (S.charAt(i) == C) {
				Lans[i] = 0;
				p = i;
			} else {
				Lans[i] = i - p;
			}
		}
        
		p = Rfirst;
		for (int i = Rfirst - 1; i >= Lfirst + 1; i--) {
			if (S.charAt(i) == C) {
				Rans[i] = 0;
				p = i;
			} else {
				Rans[i] = p - i;
			}
		}
        
        
		for (int i = Lfirst; i <= Rfirst; i++) {
			ans[i] = Math.min(Lans[i], Rans[i]);
		}

		return ans;
    }
}
```
