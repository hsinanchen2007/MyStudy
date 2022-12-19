### 解题思路
惊了，没想到就这么快速地通过了。
这个题是真的让我发现了malloc()和memset的好处，不用再去纠结题目中numSize的范围。

重点是区分[寻找重复数](https://leetcode-cn.com/problems/find-the-duplicate-number/solution/287xun-zhao-zhong-fu-shu-by-kirsche/)区别十分细微，但也是这道题为什么不能用快慢指针的原因！
在“寻找重复数”中，
![1.png](https://pic.leetcode-cn.com/a5ddf8623a97981741f4c1ff42ea6d0abf2a4ccf75abb880be8833578b865ece-1.png)
“其数字都在 1 到 n 之间（包括 1 和 n）”便是关键，即**数组下标的范围也是数组值的范围，正因为这样，才能构成一个单链表！**
而本题不满足这样的条件。

看了大神们题解，发现我这种做法本质上就是利用了哈希表的性质，即将没在哈希表中存在过的数字存入哈希表中，当发现a[i]在哈希表中存在过，则直接输出。

### 代码

```c
int findRepeatNumber(int* nums, int numsSize){
    short *arr=(short*)malloc(sizeof(short)*numsSize);
    memset(arr,0,sizeof(short)*numsSize);
    int i;
    for(i=0;i<numsSize;i++){
        arr[nums[i]]++;
        if(arr[nums[i]]>1) break;
    }
    return nums[i];
}
```