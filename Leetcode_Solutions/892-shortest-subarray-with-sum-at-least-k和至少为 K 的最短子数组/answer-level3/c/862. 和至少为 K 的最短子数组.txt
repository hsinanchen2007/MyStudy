### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/8b7902dac9c8a7440bfc1ed3c197b560784d1c0719689b545584958f475c25af-image.png)

如果所有点都是正数，该问题难度不大：
[+,+,+,+ ...]
1.先花费O(N)的时间计算所有起点到i的和，存为sum[i+1];
2.然后从左向右遍历sum数组，用right和left表示首尾，当sum[right] - sum[left] >= K时计算数组长度；
3.为了计算最短数据，需要尝试性的向右移动right，当移动后任然满足sum[right] - sum[left]就移动left，否则维持不动；
4.由于后面计算的length一定比前面的短才会更新length，所以移动left维持right - left 为length长度，需要考虑是否 +1（和开闭区间有关）。

但是数组存在负数的情况，当出现负数时，sum数组将不再单调递增；
存在三种情况
（1）连续的负数，导致sum数组出现负值；
[-,-,-,-,-,+,+ ...]
 (2) 单个的负数，但是导致left无法跨越，计算出来的长度偏大
[+,-,+,+,+,+ ...] 例如：[80,-37,30,10,40,160] 240
 (3） 正负数交替，但是负数段的和一直为负数；
[+,-,+,-,+,-,+,+,+ ...] 例如：[80,-30,1,-1,1,-1,50,60,100] 210

针对以上情况做两个处理：
1.当计算sum时出现负值，直接将sum置为0，排除sum < 0对计算sum[right] - sum[right]的影响，而且当尝试left右移时可以直接跳过。
例如 if(sum[i+1] < 0) sum[i + 1] = 0;

2.单个负数和正负交替的情况归为一类，统一都加入先入先出队列，记录负数队列的左右边界。
该代码里建立了一个超大数组来存放队列，当然也可以使用双向链表实现队列。
队列neg[]，用Head, Tail, Qsize分别表示队首、队尾和队列大小。从Head侧入队，从Tail侧出队。
入队的逻辑：
（1）当A[i] < 0 时开始组建节点，但是不完全入队；另节点的左右边界均为i，left = right = i;
 (2) 随着i的增加，如果sum[i + 1] - sum[left] < 0, 就更新right = i;
 (3) 知道上述条件不满足时停止，但是停止时需要考虑，sum[i + 1] - sum[left]由负转正，
肯定最后出现很多正值，这些正值都不能进入队列节点。 所以对这些正值进行回退。一直到right指向的是
第一非负数为止。
 (4) 至此，一个起于“负”，终于“负”， 而且和小于0的子数据节点生产，而且确定了两头的边界left和right，此时可以完全入队。

该代码处理入队时使用了状态机。

出队逻辑：
1.对队列进行维护，如果neg[Tail].right < left, 也就是队尾的元素在遍历指针left左侧，也就没有什么意义了，对其进行出队；
2.当队尾元素处于遍历指针left和right之间时，而且 neg[Tail].right + 1到right的和已经满足 >= K的要求，
就直接更新遍历指针left到该点，left = neg[Tail].right + 1，同时该节点出队。

以上就是该代码的大体思路，这个题目对时间复杂度要求很高，如果不能实现O(N)的算法，很难通过，因为有一个超大用例。
该解法能够满足要求，而且超过半数以上。
其实还有点可以优化，当遍历指针落入某个队列节点时，可以直接跳过，这样进一步减少计算量，提高速度。
### 代码

```c
typedef struct _node_t {
    int left;
    int right;
}node_t;

int shortestSubarray(int* A, int ASize, int K){
    if(A == NULL || ASize<1 || K<1) return -1;

    int left = 0, right = 0, index = 0;;
    int length = ASize + 2;

    node_t *neg =(node_t *)malloc(sizeof(node_t) * (ASize + 2));
    for(int i=0; i<ASize+2; i++){
        neg[i].left = 0;
        neg[i].right = 0;
    }
    int Head =-1, Tail = 0;
    int Qsize = 0;

    enum{
        IDEL = 0,   // not negtive
        ADD         // add item
    };
    int status = IDEL;

    int *sum = (int *)malloc(sizeof(int) * (ASize + 2));
    sum[0] = 0;
    for(int i=0; i< ASize; i++){
        sum[i+1] = sum[i] + A[i];
        if(sum[i+1] < 0) sum[i+1] = 0;

        // add item to Q
        switch(status){
            case IDEL:{
                if(A[i]<0){
                    Head++;
                    Qsize++;
                    neg[Head].left = i;
                    neg[Head].right = i;
                    status = ADD;
                }
                break;
            }
            case ADD:{
                if(sum[i+1] - sum[neg[Head].left] < 0){
                    neg[Head].right = i;
                }
                else{
                    while(A[neg[Head].right] > 0 ){
                        neg[Head].right -- ;
                    }
                    status = IDEL;
                }
                break;
            }
            default:{
                printf("<%d> error",__LINE__);
                break;
            }
        }
    }

    while(right<ASize){
        do{
            while(Qsize > 0 && neg[Tail].right <= left){
                Tail++;
                Qsize--;
            }
            if(neg[Tail].right <= right && Qsize > 0 && sum[right+1] - sum[neg[Tail].right + 1] >= K){
                left = neg[Tail].right + 1;
            }
            while(left <= right && sum[right+1] >= 0 && sum[right+1]-sum[left+1] >= K){
                left++;
            }
        }
        while((left <= right && sum[right+1]-sum[left+1] >= K)
        || (Qsize > 0 && neg[Tail].right <= left));

        if(sum[right+1] - sum[left] >= K){
            int tmp = right - left + 1;
            length = tmp < length ? tmp : length;
        }

        right++;
        if(right - left + 1 > length && length <= ASize){
            left = right - length + 1;
        }
    }

    free(sum);
    if(length <=ASize)
        return length;
    else
        return -1;
}
```