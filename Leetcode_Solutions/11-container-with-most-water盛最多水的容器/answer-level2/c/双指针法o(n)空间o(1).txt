### 解题思路
此处撰写解题思路

### 代码

```c
int maxArea(int* height, int heightSize){
    int maxspace=0;int space=0;
	int i=0,j=heightSize-1;
	while(i<j){
		if(height[i]<height[j]){
			space=height[i]*(j-i);
			maxspace=(maxspace>space)?maxspace:space;
			i++;
		}else{
			space=height[j]*(j-i);
			maxspace=(maxspace>space)?maxspace:space;
			j--;
		}
	}
	//printf("%d",maxspace);
	return maxspace;
}
```