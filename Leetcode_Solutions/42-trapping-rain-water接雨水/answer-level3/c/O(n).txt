很容易发现积水的多少取决于两头的柱子高度，所以一开始我想找到最高柱子的高度和位置。
后来发现遍历求最大值的过程有些冗余，在一遍遍脑补的过程中，我想到了更好的做法：
从左到右，将当前柱子的高度与以往的最高柱子比较：
若低，则其中可能有积水，temp加上以往最高与当前的差值（即可能的水深）；
若高，则将answer加上temp，视为计算了一个水坑的积水，同时更新最高柱子的高度。
这个算法依然不完善。当柱子遍历到还剩最后几根时，没有比最高柱子还要高的柱子，自然也无法累加之后的积水量。
可以发现，一段柱子图一定是由一个或若干个等高的山峰、以及其他的小山峰构成的。
在可能出现的最高的若干个山峰之间，之前的算法也没有问题。
于是想到倒着遍历柱子一直到最高的那根，补全之后没有记录的积水量。
结束。

int trap(int* height, int heightSize){
    if(heightSize==0)return 0;
    int peak,ans=0,temp=0,max=0;
    for(int i=0;i<heightSize;i++){
        if(max<=height[i]){
            ans+=temp;
            temp=0;
            max=height[i];
        }
        if(max>height[i])
            temp+=(max-height[i]);
    }
    peak=max;
    max=0;
    temp=0;
    for(int i=heightSize-1;height[i]!=peak;i--){//这里理所当然地被0柱子卡住了，heightSize-1=-1,没有height[i]
        if(max<=height[i]){
            ans+=temp;
            temp=0;
            max=height[i];
        }
        if(max>height[i])
            temp+=(max-height[i]);
    }
    ans+=temp;
    return ans;
}