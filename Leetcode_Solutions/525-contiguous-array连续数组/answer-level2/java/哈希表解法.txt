### 解题思路
考虑cnt[i]：
	当nums[i]==0时cnt[i]=cnt[i-1]-1
	当nums[i]==1时cnt[i]=cnt[i-1]+1
那么问题就转化为，寻找(i,j)使得cnt[i]==cnt[j],使j-i尽可能大
使用HashMap记录每一个cnt第一次出现的位置，当再次出现cnt时即可得到连续子数组的长度。

### 代码

```java
class Solution {
    public int findMaxLength(int[] nums) {
    	HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
    	map.put(0, -1);
    	int cnt = 0;
    	int maxLen = 0;
    	for(int i = 0; i < nums.length; i++) {
    		if(nums[i] == 1) {
    			cnt++;
    		}
    		else {
    			cnt--;
    		}
    		if(!map.containsKey(cnt)) {
    			map.put(cnt, i);
    		}
    		else {
    			if(i - map.get(cnt) > maxLen) {
    				maxLen = i - map.get(cnt);
    			}
    		}
    	}
    	return maxLen;
    }
}
```