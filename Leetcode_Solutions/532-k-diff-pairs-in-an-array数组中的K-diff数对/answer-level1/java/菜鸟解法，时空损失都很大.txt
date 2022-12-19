### 解题思路
先去重

### 代码

```java
class Solution {
    public int findPairs(int[] nums, int k) {
        int[] b = new int[nums.length];
        int[] b1 = new int[nums.length];
        int l = 0,i = 0,p = 0,j;
		int coun = 0;
		Set s = new HashSet();
        Set s1 = new HashSet();
		for(int x:nums) {
			if(s.add(x)) {
				b[l] = x;
				l++;
			}else{
                if(s1.add(x)) {
					b1[p] = x;
					p++;
				}
            }
		}
		for(i = 0;i < l - 1;i++) {
			for(j = i + 1;j < l;j++) {
				if(Math.abs(b[i] - b[j]) == k) {
					coun++;
				}
			}
		}
        if(k == 0){
            coun = p;
        }
        return coun;
    }
}
```