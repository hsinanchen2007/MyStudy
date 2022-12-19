执行用时 :1 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :38.3 MB, 在所有 java 提交中击败了93.66%的用户

思路：找出数组中最大最小值即可，若max和min之差小于2K，则max和min在进行加减K时可以取得相等，这样两者可以取得最小值0，否则最小值为max-min-2*K。特殊情况是数组只有一个元素，可以取到最小值0；

```
    public int smallestRangeI(int[] A, int K) {
    	if (A.length == 1) {
    		return 0;
    	}
        int min = A[0];
        int max = A[0];
        for (int a:A) {
        	if (a > max) {
        		max = a;
        	}
        	if (a < min) {
        		min = a;
        	}
        }
        if (max-min <= 2*K) {
        	return 0;
        }
        return max-min-2*K;
    }
```
