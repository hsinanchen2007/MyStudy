### 解题思路
此处撰写解题思路

### 代码

```c
int maxArea(int* height, int heightSize){
    int high=0;int maxspace=0;int space=0;
	for(int i=0;i<heightSize;i++){
		for(int j=i+1;j<heightSize;j++){
			high=(height[i]<height[j])?height[i]:height[j];
			space=high*(j-i);
			maxspace=(maxspace>space)?maxspace:space;
		}
	}
	//printf("%d",maxspace);
	return maxspace;
}
```