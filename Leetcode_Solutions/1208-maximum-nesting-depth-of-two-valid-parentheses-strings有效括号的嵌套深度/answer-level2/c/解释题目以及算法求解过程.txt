### 解题思路
首先得理解嵌套深度的定义：
	题目的最下面中给出了嵌套深度的定义和例子；
	例如：""，"()()"，和 "()(()())" 都是有效括号字符串，嵌套深度分别为 0，1，2，而 ")(" 和   "(()" 都不是有效括号字符串。
	解释一下这三个嵌套深度的由来：
						*S = "()()";*
						*depth[s] = {1,2,2,1};*
						*S = "()(()())";*
						*depth[s] = {1,1,1,2,2,2,2,1};*
    也就是有“)”来匹配"(",最大嵌套深度不变，当前嵌套深度可以减1；并当紧接的下一个是"("时，嵌套深度不需加1；
了解这个之后，在根据题目的要求“max(depth(A), depth(B)) 的可能取值最小。”，就非常容易了。
	分别用两个计数器cA、cB,记录A和B当前的嵌套深度;
 	往cA、cB中较小的那个加“(”;
	往cA、cB中较大的那个加“）”，即使嵌套深度不变、不增加;
### 代码

```c
int* maxDepthAfterSplit(char * seq, int* returnSize){
	int len = strlen(seq);
	int *res = (int*)malloc(sizeof(int)*(len+1));
	int cA = 0;
	int cB = 0;
	for(int i=0;i<len;i++)
	{
		if(seq[i]=='(')
		{
			if(cA<=cB)
			{
				res[i] = 0;
				cA++;
			}
			else
			{
				res[i] = 1;
				cB++;
			}	
		}
		else
		{
			if(cA>=cB)
			{
				res[i] = 0;
				cA--;
			}
			else
			{
				res[i] = 1;
				cB--;
			}
		}
		
	}
	*returnSize = len;
	return res;
}
```