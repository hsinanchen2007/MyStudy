### 解题思路
此处撰写解题思路

### 代码

```c

void maxHeapify(int num[], int start, int end) {
    //建立父节点指标和子节点指标
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { //若子节点指标在范围内才做比较
        if (son + 1 <= end && num[son] < num[son + 1]) //先比较两个子节点大小，选择最大的
            son++;
        if (num[dad] > num[son]) //如果父节点大於子节点代表调整完毕，直接跳出函数
            return;
        else { //否则交换父子内容再继续子节点和孙节点比较
            //EXCHANGE(num[dad], num[son])
            int tmp = num[dad];
            num[dad] = num[son];
            num[son] = tmp;
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void heapSort(int* num, int count) {
    int i;
    //初始化，i从最後一个父节点开始调整
    for (i = count / 2 - 1; i >= 0; i--)
        maxHeapify(num, i, count - 1);
    //先将第一个元素和已排好元素前一位做交换，再重新调整，直到排序完毕
    for (i = count - 1; i > 0; i--) {
        //EXCHANGE(num[0], num[i])
        int tmp = num[0];
        num[0] = num[i];
        num[i] = tmp;
        maxHeapify(num, 0, i - 1);
    }
}

int majorityElement(int* nums, int numsSize)
{
    heapSort(nums , numsSize);
    return nums[numsSize/2];

}
```