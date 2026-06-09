1.不明白为什么这个题目大家都再用hash表做，然后做出来的答案看了几个热门，都不考虑重复的场景。求指点。
2.因为这个题目要求的是时间要再N*logN,那么排序就可以选择用qsort;
先对输入按照值，从小到大排序；方便后面统计相同值的次数；
统计完次数之后，再将次数按从大到小排序，方便后面从0开始，取前K个值作为返回值；

typedef struct _NODE{
    int val;
    int times;
}NODE;
int CmpNum(const void * a, const void * b){
	int *p1 = (int*)a;
	int *p2 = (int*)b;
    return *p1 - *p2;
}

int CmpNode(const void * a, const void * b){
	 NODE* p1 = (NODE*)a;
	 NODE* p2 = (NODE*)b;
    return (p2->times - p1->times);
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    NODE *input;
    int *rslt;
    int i, j;

    * returnSize = k;

    //先对输入的数组按数值从小到大排序
    qsort(nums, numsSize, sizeof(int), CmpNum);

    j = 0;
    input = (NODE*)malloc(numsSize*sizeof(NODE));
	memset(input, 0, numsSize*sizeof(NODE));
    input[0].val = nums[0];
    input[0].times = 1;

    for(i=1;i<numsSize;i++){
        if(nums[i] != nums[i-1]){
            j++;
            input[j].val = nums[i];
            input[j].times = 1;
        } else {
            input[j].times++;;
        }
    }

    //对统计的次数按从大到小排序
    qsort(input, j+1, sizeof(NODE), CmpNode);

    rslt = (int*)malloc(k*sizeof(int));

    for(i=0;i<k;i++){
        rslt[i] = input[i].val;
    }

    free(input);

    return rslt;