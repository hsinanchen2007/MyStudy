
for 循环要从后往前扫描元素，倒着入栈，正着出栈。
while 循环是把两个较大元素之间的元素排除
```
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    *returnSize = TSize;
    int *ans = malloc(sizeof(int)*TSize);
    int stack[TSize+1];  //栈底不放元素，因此要多一个空间
    int top = 0;
    for(int i = TSize-1; i >= 0; i--)  //for 循环要从后往前扫描元素
    {
        while(top != 0 && T[stack[top]] <= T[i])//如果在栈中找不到比T[i]大的元素，则栈减，直至找到该元素或者top至0
             top--;
        ans[i] = top==0 ? 0 : (stack[top] - i);//利用下标得到索引间距，若top=0,说明栈中(即该元素后)没有比当前元素大的。
        stack[++top] = i;  //将下标放入栈
    }
    return ans;
}
```

