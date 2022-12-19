### 递归回溯法C语言
char str[]; 存字符串
id   表示字符串str中的位置
l    表示‘（’的个数
r    表示‘）’的个数
步骤一，第一个字符一定是‘（’，因此，id=0、str[id]='('；
步骤二，str[id++]的字符只有两种情况，'('或者')'；
       当l 小于 n时，str中可以放入'('；
       当r 小于 l（r < n,l < n）时，str中可以放入‘)’;
步骤三，重复步骤二，直到l==n并且r==n，返回一种解；

使用回溯递归既可以得出所有解；
     
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void backTrack(char **res,char str[],int id,int n,int l,int r,int *returnSize){
	//PrintS(str,id);
	if(l==n&&r==n)
	{
		str[id] = '\0';
		res[*returnSize] = (char*)malloc(sizeof(char)*(id+1));
		strcpy(res[*returnSize],str);
		//Print(res,returnSize);
		(*returnSize)++;
		return;
	}
	if(l<n)
	{
		str[id] = '(';
	    backTrack(res,str,id+1,n,l+1,r,returnSize);
	}
	if(r<l)
	{
		str[id] = ')';
		backTrack(res,str,id+1,n,l,r+1,returnSize);
	}
	
}
char ** generateParenthesis(int n, int* returnSize){
	char **res = (char**)malloc(sizeof(char*)*1000000);
	char str[n*2+1];
	*returnSize = 0;
	backTrack(res,str,0,n,0,0,returnSize);
	return res;
} 

```