### 解题思路
参考题解；
补充一点，这里用count作终止条件很巧妙。如果把从start到回到start的路径看作一个环，那么可能一个环包含了N%k个元素（若n%k==0）若n%k==1，那么这个环将会包含所有元素，成为一个大环。

### 代码

```c
void rotate(int* nums, int numsSize, int k){
    //numsSize=numsSize-1;
    int temp,count=0;
    int  current;
    int pre;
    k=k%numsSize;
    for(int start=0;count<numsSize;start++)
    {
        current=start;
        pre=nums[current];
       int next;
        do
        {
            next=(current+k)%numsSize;
            temp=nums[next];
            nums[next]=pre;
            pre=temp;
            current=next;
            count++;
        }
        while(current!=start);
    }

}
```