### 解题思路
做次方運算後跟原本值做比較

### 代码

```java
class Solution {
    public boolean isArmstrong(int N) {
        String a = String.valueOf(N);
		int n = N;
		int sum = 0;
		
		while(n != 0) {
			sum += Math.pow((n % 10),a.length());
			n /= 10;
		}
		
		if(sum == N) {
			return true;
		}
		return false;
    }
}
```