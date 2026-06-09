因为本人新手，看了很多大佬都是先求小的，而我是从大的开始的，不确定是不是贪心，请各位大佬多提出一些见解。
思路：若饥饿值为[1,2]  饼干为[1,3]。
最大的饼干（3）能满足的最大的饥饿值（2），第二大的饼干（1）不一定能满足（很绕口）。
这样每次循环都能找到还没分发的饼干里面能满足的最大饥饿值得孩子。
然后从该孩子开始往前继续推进。

```
class Solution {
    public int findContentChildren(int[] g, int[] s) {
    	int ans=0;
    	int i,j;
    	j=g.length-1;
    	Arrays.sort(g);
    	Arrays.sort(s);
    	for(i=s.length-1;i>=0;--i)
    	{
    		for(;j>=0;--j)
    		{
    			if(s[i]<g[j])
    				continue;
    			
    			ans++;
    			j--;
    			break;
    		}
    	}
    	return ans;
    }
}
```
