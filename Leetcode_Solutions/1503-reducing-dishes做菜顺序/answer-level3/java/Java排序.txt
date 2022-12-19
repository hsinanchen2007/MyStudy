### 解题思路
这一题的主旨就是用多的满意时间贪满意程度大的菜，为了贪的更多，可以做一些不令人满意的菜。
首先对 `satisfaction 数组`进行升序排序，将满意程度大的菜放在后面。
之后从后往前遍历，步骤如下：
1. 设定一个变量 `tar`，为要做的菜的数量，当 `tar == satisfaction.length` 时，进行最后一次计算并结束过程（已经做了所有的菜）；
2. 从尾开始根据题目要求计算当前方案的总喜爱时间res，根据其大小改变最终结果：
	`ans = Math.max(ans,res)`；
3. 返回`ans`即可。

（PS：困难难度的题这样就做出来了感觉可能我做的方法有考虑不周到的地方，希望各位大佬能指出相应的问题。本人也会抽时间进行思考。）

### 代码

```java
class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);
	int tar = 1,n = satisfaction.length,ans = 0;
        if(satisfaction[n - 1] <= 0) return 0;
	while(tar <= n) {
	    int res = 0;
	    for(int i = n - tar;i < n;i++) {
		res += satisfaction[i] * (i - n + tar + 1);
	    }
	    ans = Math.max(ans, res);
	    tar++;
    	}
	return ans;
    }
}
```