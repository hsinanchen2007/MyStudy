数据是有范围限制的所以可以使用桶排序O（n）复杂度
再顺序扫一遍，把第i个桶中bucket[i]-1个数全部加一放进下一个桶，这个过程也是O（n）的
最后判断最后一个桶40000如果大于1一共要多加n*(n-1)/2个，用res加上即可
int minIncrementForUnique(int* A, int ASize){
	int bucket[40001]={0};
	int i;
	for(i=0;i<ASize;i++){
		bucket[A[i]]++;
	}
	int res=0;
	for(i=0;i<40000;i++){
		if(bucket[i]>1){
			res+=bucket[i]-1;
			bucket[i+1]+=bucket[i]-1;
		}
	}
	if(bucket[40000]>1){
		res+=(bucket[40000]-1)*bucket[40000]/2;
	}
	return res;
}