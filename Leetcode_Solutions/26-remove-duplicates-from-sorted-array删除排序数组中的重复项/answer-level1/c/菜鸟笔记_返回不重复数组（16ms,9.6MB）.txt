### 解题思路
1. 两个指针，刚开始前后相邻。如果head与rear标记的元素相等了，那么此时head的下一个元素（即++head，占着茅坑不顶用，实际上head与rear之间可能全部相同，此时我们选择++head作为被替换者）是重复的且可以被替换的元素，此时用rear指针向后扫描，碰到第一个不重复的元素，就把他放到++head的位置。直到rear扫描到数组最后。
2. 做数组越界判断的时候，要考虑别人发过来的是0个元素的数组和一个元素的数组这两种情况，争取一次t成功，奥里给！
3. 假如你看到我的题解，能不能告诉我，为啥我只定义了两个变量，内存空间却才击败了37.48%的人呢？内存空间除了和定义的变量有关，还和啥有关系？来自一个菜鸟的提问。
### 代码

```c
/*date：2020.3.4 10：39*/
int removeDuplicates(int* nums, int numsSize){
    if (numsSize == 1){//如果只有一个则直接返回，否则下面会越界
        return 1;
    }
    if (numsSize == 0){
        return 0;
    }
    int head = 0;
    int rear = 1;
    while (rear < numsSize){
        if (nums[head] == nums[rear]){//rear向后扫描，如果和head一样则head不动，rear向后扫描。
        //如果不一样，则前进一格赋值
            rear++;
        }
        else{
            nums[++head] = nums[rear++];
        }
    }
    return head+1;

}
```