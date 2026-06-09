
```
class Solution {
    public int tribonacci(int n) {
      if (n==0) {
			return 0;
		}
		int T1 = 0;
		int T2 = 1;
		int T3 = 1;
		for (int i = 4; i <= n+1; i++) {
			int T4 = T1 + T2 + T3;
			T1 = T2;
			T2 = T3;
			T3 = T4;
		}
		
		return T3;
    }
}
```