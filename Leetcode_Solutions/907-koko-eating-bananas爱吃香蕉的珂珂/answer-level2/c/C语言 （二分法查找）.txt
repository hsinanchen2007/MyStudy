1.答案一定在1和数组中最大值之间
2.从1开始遍历，找到一个最小的K，满足吃完所有香蕉的时间小于H，则直接返回。【运行超时】
3.改用二分法，找到一个最小值，满足吃完所有香蕉，需要的时间小于H；
int calcTime(int* piles, int pilesSize, int k)
{
    int i, sum;
	sum = 0;
    for(i=0;i<pilesSize;i++){
        sum += ((piles[i] + k) -1)/k;
    }
   
	return sum;
}
int minEatingSpeed(int* piles, int pilesSize, int H){
    int i, k, max, sum, start, end;
    
    if (pilesSize>H){
        return -1;
    }
    //找最大值
    max = 0;
    for(i=0;i<pilesSize;i++){
        if(max<piles[i]){
            max = piles[i];
        }
    }

    //二分法从1到maxz之间找
    start = 1;
    end = max;
    while(start<end){
        sum = 0;
        k = (end+start)/2; //k在向start靠近
        sum = calcTime(piles,pilesSize,k) ;
        if(sum > H){//不满足H以内的条件
            start = k+1;//跳过K，从K的下一个值开始
        } else {//k有可能是最小值
            end = k;//end在向start靠近
        }
    }
    return start;
}