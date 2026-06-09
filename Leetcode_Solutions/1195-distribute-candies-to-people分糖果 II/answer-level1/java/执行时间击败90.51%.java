### 解题思路
直接迭代完成

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] ans=new int[num_people];
        if(0>=candies)
			return ans;
		else {
			int n=0;
			for(;n+1<candies;) {
				ans[n%num_people]=ans[n%num_people]+(++n);
				candies-=n;
			}
			ans[n%num_people]=ans[n%num_people]+candies;
			return ans;
			}
    }
}
```