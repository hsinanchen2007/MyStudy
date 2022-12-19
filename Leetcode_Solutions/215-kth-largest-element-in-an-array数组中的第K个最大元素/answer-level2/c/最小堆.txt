### 解题思路
最小堆方法，借鉴大神@yankuangshigo的解题思路

最小堆：父节点的数值小于所有孩子节点。
先对前K个数组元素进行"原地"建小顶堆；
建完小顶堆后，堆顶的元素是k个元素中最小的值，即是这K个元素的第K大元素。
然后遍历剩下的元素 nums[k] ~ nums[len-1]
1、如果比堆顶元素小，跳过
2、如果比堆顶元素大，和堆顶元素交换后重新堆化

### 代码

```c

void buildHeap(int *nums, int k);
void heapify(int *nums, int k, int i);
void swap(int *nums, int m, int n);

int findKthLargest(int* nums, int numsSize, int k){
    //先堆化前k个元素,堆顶元素为此时第k个大的元素
    buildHeap(nums,k);

    //比较后面numsSize-k个元素与堆顶元素大小；
    //比堆顶小，则继续比较；
    //比堆顶大，则重新堆化，重新获得堆顶元素。
    for(int i=k; i<numsSize; i++){
        if(nums[0] > nums[i]){
            continue;
        }
        swap(nums,0,i);
        heapify(nums,k,0);
    }

    return nums[0];
}

//建堆
void buildHeap(int *nums, int k){
    for(int i = k/2-1; i >= 0;i--){
        heapify(nums,k,i);
    }
}

//堆化
void heapify(int *nums, int k, int i){
    int minPos = i;
    while(true){
        //父节点与左孩子节点比较
        if(2*i+1 < k && nums[2*i+1] < nums[i]){
            minPos = 2*i+1;
        }
        //右孩子节点与最小值节点比较，得出三方最小值节点
        if(2*i+2 < k && nums[2*i+2] < nums[minPos]){
            minPos = 2*i+2;
        }
        //若父节点已经是最小的
        if(minPos == i){
            break;
        }
        //父节点与三方最小值节点交换数值
        swap(nums, i, minPos);
        i = minPos;
    }
}

//交换数值
void swap(int *nums, int m, int n){
    nums[m] += nums[n];
    nums[n] = nums[m] - nums[n];
    nums[m] = nums[m] - nums[n];
}

```