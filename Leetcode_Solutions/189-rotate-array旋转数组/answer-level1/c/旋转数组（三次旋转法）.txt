### 解题思路
三次旋转

### 代码

```c
void reverse(int a[],int i,int j)
{
    int t;
    t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void rotate(int* nums, int numsSize, int k){

    int i = 0;
    k = k % numsSize;
    if((numsSize <= 1)||(k == 0))
        return;
    for(i = 0;i< numsSize/2;i++)
    {
        reverse(nums,i,numsSize-1-i);
    }
    for(i = 0;i< k/2;i++)
    {
        reverse(nums,i,k-1-i);
    }
    for(i = k;i< (k+numsSize)/2;i++)
    {
        reverse(nums,i,numsSize-1-(i-k));
    }

}
```