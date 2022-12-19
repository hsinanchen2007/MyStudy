**1.先翻转前n-k个，再翻转后k个，最后翻转整个数组即可。但要注意k可能大于数组长度，取余即可。**
```c
void reverse(int *a, int l, int h)
{
    for(int i = 0; i < (h - l + 1) / 2; i++){
        int t = a[l + i];
        a[l + i] = a[h - i];
        a[h - i] = t;
    }
}
void rotate(int* nums, int numsSize, int k){
    if(!nums || numsSize == 0)
        return;
    k = k % numsSize;
    reverse(nums, 0, numsSize - 1 - k);
    reverse(nums, numsSize - k, numsSize - 1);
    reverse(nums, 0, numsSize - 1);
}
```
**2.环形旋转**
**把数组当成环形的，把每个元素放到其后K个位置。**
```
void rotate(int* nums, int numsSize, int k){
    if(!nums || numsSize == 0)
        return;
    k = k % numsSize;
    int cnt = 0, start = 0, cur;
    int prev, next, tmp;
    while(cnt < numsSize){
        cur = start;
        prev = nums[start];
        do{
            next = (cur + k) % numsSize;
            tmp = nums[next];
            nums[next] = prev;
            prev = tmp;
            cur = next;
            cnt++;
        }while(start != cur);
        start++;
    }
}
```