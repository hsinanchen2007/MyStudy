写了2次，先是用深搜，从头向后，但是发现在有一组数据中会超时，主要是因为999到9999999，每次返回上层循环因为差值太大，都需要重复做很多次，且没有想到很好的方法避免。
后来更换了解法，从后向前解。因为从前向后的话，很明显能确定的只有0->1是1，而从后往前的话，可以知道最后一个与上一个之间的k值，且第二个和第一个之间是1我们同样知道，相当于多拥有了一个条件。于是在深度搜索的途中，我们只要沿着必须的路径走到0，然后看最后一次的k值是不是1就可以了。
代码是这样的：
#include<bits/stdc++.h>
using namespace std;

bool judge(int k,int index,vector<int>& stones)
{
	if(index==1&&(k==1||k==2))
		return 1;
	if(index==1||index==0)
		return 0;
	int i=1;
	long long cur,pre;
	pre = stones[index-i];
	cur = stones[index];
	while((index-i>=0)&&(pre+1+k>=cur))
	{
		if(pre+1+k==cur)
		{
			if(judge(k+1,index-i,stones)==1)
				return 1;
		}
		else if(pre+k==cur)
		{
			if(judge(k,index-i,stones)==1)
				return 1;
		}
		else if(pre-1+k==cur)
		{
			if(judge(k-1,index-i,stones)==1)
				return 1;
		}
		i++;
		if(index-i>=0)
			pre = stones[index-i];
		else
			break;
	}
	return 0;
}

class Solution {
public:
    bool canCross(vector<int>& stones) 
	{
        int length=stones.size()-1;
        if(stones[1]!=1)
        	return 0;
        int k=stones[length]-stones[length-1];
        int i=1;
        while(length-i>=0)
        {
        	if(judge(stones[length]-stones[length-i],length,stones)==1)
        		return 1;
        	i++;
		}
        return 0;
    }
};
最终用时超过84%，内存消耗超过100%
