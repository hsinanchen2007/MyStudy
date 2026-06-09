### 解题思路
简单的java循环

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;
		for(int a:A) {
			sum+=a;
		}
		if(sum%3!=0)return false;
		sum/=3;
		int c1 = 0;
		for(int i=0;i<A.length;i++) {
			c1+=A[i];
			if(c1==sum) {
				for(int j=i+1;j<A.length;j++) {
					c1+=A[j];
					if(c1==2*sum && j+1<A.length)return true;
				}
			}
		}
		
		return false;
    }
}
```