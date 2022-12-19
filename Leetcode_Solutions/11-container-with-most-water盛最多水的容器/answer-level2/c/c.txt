### 解题思路
此处撰写解题思路参考题解

### 代码

```c
int maxArea(int* height, int heightSize)
{
    int left,right,size,max=0;
    int head=0,tail=heightSize-1,m;
    while(head<tail)
    {

        left=height[head];
        right=height[tail];
        m=tail-head;
        if(left<right) 
        {
            size=left*m;
            head++;
        }
        else 
        {
            size=right*m;
            tail--;
        } 
        if(size>max) max=size;
    }
        
    return max;
}

双指针法
int maxArea(int* height, int heightSize)
{
    int left,right,size,max=0;
    int head=0,tail=heightSize-1,m;
    while(head<tail)
    {

        left=height[head];
        right=height[tail];
        m=tail-head;
        if(left<right) 
        {
            size=left*m;
            head++;
        }
        else 
        {
            size=right*m;
            tail--;
        } 
        if(size>max) max=size;
    }
        
    return max;
}