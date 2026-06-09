### 解题思路
遍历数组，手中无值则记录改值，否则判断新出现的这个值是否与手中的值相同。若相同则增加计数，否则减少计数，计数为零表示手中无值。
由于多数元素保证出现次数大于n/2，所以这个算法可以保证在遍历整个数组后手中的值为答案。

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
		int ans = 0;
		int cnt = 0;
		for(int i : nums)
		{
			if(cnt == 0)
			{
				ans = i;
			}
			if(ans == i)
			{
				cnt++;
			}
			else
			{
				cnt--;
			}
		}
		return ans;
    }
}
```