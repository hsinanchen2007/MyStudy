核心思路：仔细观察数据和图示可以发现，不管最初给定什么样的数组，最后结果都是一个先单调非降，后单调非增的数列。因此，本题转化为用尽可能少的材料填补柱子空隙，使其先单调非降，后单调非增。
第一步：找到最高的柱子的位置并记录下来，设为MAX_pos
第二步：从左边往右“填”，到MAX_pos为止，使其单调非降，把所有填补消耗的材料加起来为rain_left
第三步：从右边往左“填”，同样到MAX_pos为止，使其单调非增，把所有填补消耗的材料加起来为rain_right
最后把rain_left和rain_right加起来为最终结果
算法复杂度分析：
1、时间复杂度：完整地扫了两遍数组，时间开销2n，即O(n)
2、空间复杂度：仅使用了MAX_pos，MAX_height，rain，pos四个int变量，复杂度O(1)
int trap(int* height, int heightSize){
    if(heightSize<3)return 0;
	int pos,MAX_pos,MAX_height=-1;
	for(pos=0;pos<heightSize;pos++){
		if(height[pos]>MAX_height){
			MAX_height=height[pos];
			MAX_pos=pos;
		}
	}
	int rain=0;
	//MAX's left is ascending
	for(pos=1;pos<MAX_pos;pos++){
		if(height[pos]<height[pos-1]){
			rain+=height[pos-1]-height[pos];
			height[pos]=height[pos-1];
		}
	}
	//MAX's right is descending
	for(pos=heightSize-2;pos>MAX_pos;pos--){
		if(height[pos]<height[pos+1]){
			rain+=height[pos+1]-height[pos];
			height[pos]=height[pos+1];
		}
	}
	return rain;
}