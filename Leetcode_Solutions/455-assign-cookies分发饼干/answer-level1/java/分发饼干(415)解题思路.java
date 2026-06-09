### 解题思路
先将饼干和孩子所需大小都进行排序，计算这些饼干能够被多少个小朋友吃掉
### 代码

```java
class Solution {
    public int findContentChildren(int[] g, int[] s) {
        int result = 0;
		int child = g.length - 1;
		int cookie = s.length - 1; 
        //先将饼干和孩子所需大小都进行排序
		Arrays.sort(g);  
        Arrays.sort(s);
        //计算这些饼干能够被多少个小朋友吃掉
        while(child >= 0 && cookie >= 0)
        {
        	if(g[child] <= s[cookie])
        	{
        		cookie--;
        		result++;
        	}
        	child--;
        }
		return result;
    }
}
```