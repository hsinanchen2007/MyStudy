//看了“熊猫刷题Python3”大佬的栈的讲解有部分案列没考虑到做些更正
```
int MIN(int a,int b){return  a>b?b:a;}
int trap(int* height, int heightSize){
	int s[100005];  //模拟栈 
	int top=-1; 
	int sum = 0,h,c;
	for(int i=0;i<heightSize;i++){
		while(top>-1&&height[i]>height[s[top]]){
			c = s[top];
			if((--top)==-1) break;  //栈空结束 
			h = MIN(height[s[top]]-height[c],height[i]-height[c]);
			sum+=(h*(i-s[top]-1));
		}
		s[++top]=i;
	} 
	return sum;
}
```

![无标题.png](https://pic.leetcode-cn.com/7607a6897e194e0a314f35d389671575960d29ca446a155692595a5f2409dc41-%E6%97%A0%E6%A0%87%E9%A2%98.png)
