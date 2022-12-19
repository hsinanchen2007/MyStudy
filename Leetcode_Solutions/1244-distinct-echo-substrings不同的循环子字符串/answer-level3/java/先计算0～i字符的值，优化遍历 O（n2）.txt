### 解题思路
参照top排行的解法
先计算0～i字符的值，优化遍历 O（n2）

```
sum(i,j) * hSqr = sum(j,2j-i+1)
```


### 代码

```java
class Solution {
    public int distinctEchoSubstrings(String text) {
		Set<Integer> table = new HashSet<Integer>();
        
		int MAXN = 2000 + 50;
		int CHASH = 37;
		int[] hCode = new int[MAXN];
			int [] hSqr = new int[MAXN];
		
        hCode[0] = 0;
        hSqr[0] = 1;
        int n = text.length();
        for (int i = 1; i <= n; i++) {
            hCode[i] = hCode[i - 1] * CHASH + text.charAt(i - 1);
            hSqr[i] = hSqr[i - 1] * CHASH;
        }
        
        for (int i = 1; i <= n; i++){
            int curCode = 0;
            for (int j = i; j <= n; j++){
                curCode = curCode * CHASH + text.charAt(j - 1);
                int len = (j - i + 1);
                int x = j + 1, y = j + len;
                if (y > n) break;
                int left = (hCode[j] - hCode[i - 1]) * hSqr[len];
                int right = hCode[y] - hCode[x - 1];
                if (left == right) {
                	table.add(curCode);
            	}
            }
        }
        
        return table.size();
	}
}
```