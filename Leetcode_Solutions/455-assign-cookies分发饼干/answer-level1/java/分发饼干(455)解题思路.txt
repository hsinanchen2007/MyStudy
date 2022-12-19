### 解题思路
先将饼干和孩子所需大小都进行排序(升序)，把饼干分配给能满足的胃口最小的小朋友

### 代码

```java
class Solution {
    public int findContentChildren(int[] g, int[] s) {
        int child = 0;
		int cookie = 0;
        //先将饼干和孩子所需大小都进行排序(升序)
		Arrays.sort(g);  
        Arrays.sort(s);
        //把饼干分配给能满足的胃口最小的小朋友
        while(child < g.length && cookie < s.length)
        {
        	if(g[child] <= s[cookie])
        	{
        		child++;
        	}
        	cookie++;
        }
		return child;
    }
}
```