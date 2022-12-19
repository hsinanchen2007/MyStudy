### 解题思路
1. 前后两个指针，刚开始一个在最前head，一个在最后rear。head开始向前扫描，停留在发现的第一个val上面，此时将rear的值赋给head，然后rear向前。此时不考虑rear的值本身是否是val，因为被赋值的head在下一轮还要再检查是否是val。这样做的目的是，rear如果考虑只拿不是val的值往前放，这样会给后面产生“空洞”。
2. 考虑几种特殊情况：如果只有一个数字且不等于val/等于val；最后那个head元素是否等于val，因为如果倒数第二个元素不是val，那么head自动进一，head==rear，此时已经跳出循环，故不能判断最后一位是什么值，所以要再次加以判断。

### 代码

```c
/*date:2020.3.4 11：21*/
int removeElement(int* nums, int numsSize, int val){

    if (numsSize == 0){
        return 0;
    }

    int head = 0;
    int rear = numsSize -1;
    while (head != rear){
        if (nums[head] == val){//如果相等
            nums[head] = nums[rear--];
        }
        else{
            head++;
        }
    }
    if (nums[head] != val){
        return head+1;
    }
    else{
        return head;
    }

}
```