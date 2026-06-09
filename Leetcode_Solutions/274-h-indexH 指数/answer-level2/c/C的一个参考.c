```
/*    执行用时 :60 ms, 在所有C提交中击败了40.00%的用户
      内存消耗 :7.3 MB, 在所有C提交中击败了81.82%的用户
至多有 h 篇论文分别被引用了至少 h 次，其余的 N - h 篇论文每篇被引用次数不
多于 h 次，如果 h 有多种可能的值，h 指数是其中最大的那个。
整体理解是：首先对发文数组进行升序排列，排序后依次对数组内每个数进行判断：
1，首先判断该数到数组末尾长度len与该数a大小比较，若a<len,则该数不满足 h 篇
论文分别被引用了至少 h 次。若a>len，则进行2；
2，在a与len中取较小值（为了满足至多有 h 篇论文分别被引用了至少 h 次），然后
记录当前值与之前满足条件的h相比较，取最大值（如果 h 有多种可能的值，h 指数
是其中最大的那个）
算法改进：在大结构不变的情况下，能省时间的地方就是排序，可以使用快排，这样
平均时间复杂度应该会减少，整体加快。*/
int Min(int a,int b){
	if(b<a) a=b;
	return a;
}
int Max(int a,int b){
	if(b>a) a=b;
	return a;
}
int hIndex(int* citations, int citationsSize){ 
	if(citationsSize==0) return 0;
/* 就是一个插入排序升序排列过程，这里换成快排会更快，只是我懒得写啦*/
	int i,j,key;
	for(i=1;i<citationsSize;i++){
		key=citations[i];
		j=i-1;
		while(j>=0&&citations[j]>key){
			citations[j+1]=citations[j];
			j--;
		}
		citations[j+1]=key;
	}
	int h=0;
	for(int i=0;i<citationsSize;i++){
		if(citations[i]<(citationsSize-i)) continue;
		int min=Min(citations[i],citationsSize-i);
		h=Max(h,min);
	} 
	return h;
}

```