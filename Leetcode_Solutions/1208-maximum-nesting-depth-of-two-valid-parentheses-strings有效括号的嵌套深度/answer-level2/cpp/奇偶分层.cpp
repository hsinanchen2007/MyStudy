- 题目意思是，尽可能的让拆开的两个括号的 最大嵌套深度 最小
- 那就按照深度分成奇数层、偶数层，分别拿出来就行了
[更多解题](https://blog.csdn.net/qq_21201267/article/details/100577842)

![在这里插入图片描述](https://pic.leetcode-cn.com/9fb503b587cfd0516591fb6176e6cc75557a6219a2a89c6f2ab5287c85c0e1f7.png)

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
    	int i, j = 0, depth = 0;
    	vector<int> ans(seq.size(),0);
        char prev = '*';
    	for(i = 0; i < seq.size(); ++i,++j)
    	{
            if(prev == ')')
                depth--;
    		if(seq[i] == '(')
    			depth++;
    		if(depth & 1)//奇数层
                ans[j] = 1;
            prev = seq[i];
            // cout << depth << " ";
    	}
    	return ans;
    }
};
```
![在这里插入图片描述](https://pic.leetcode-cn.com/ff3f9462cb41ecce97227b6bfb9615b0d10b2bab091987c2c8f5d5bd84286e86.png)