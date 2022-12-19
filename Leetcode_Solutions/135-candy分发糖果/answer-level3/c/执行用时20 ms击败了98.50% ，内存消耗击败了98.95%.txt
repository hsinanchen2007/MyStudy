### 解题思路
将所给数列看作升序（依次分1，2，3，4，…，n个糖果）和降序（依次分n,n-1,n-2,n-1，…，1个糖果）数列的组合；寻找最低点：小于左右数字的数，从1开始向左按升序发糖果，从1开始向右按升序发糖果。给最右的数发糖果后，从下一个数字开始寻找最低点。
改进：最低点min可以是x=min<y和x<min=y;相邻两=几个数相等的情况下，分为它们处于一段序列中/两端等多种情况；对于常数列，每人发1个糖果。

### 代码

```c
int candy(int* ratings, int ratingsSize){
    if(ratingsSize==1)
        return 1;
    if(ratingsSize==0)
        return 0;
    int arr[20000]={0},nums;
    //size>=2;
    for(int i=0;i<ratingsSize;i++)
    {
        if(i==0&&ratings[0]<ratings[1]||i==ratingsSize-1&&ratings[i]<ratings[i-1]||i>0&&i<ratingsSize-1&&(ratings[i]<ratings[i-1]&&ratings[i]<=ratings[i+1]||ratings[i]==ratings[i-1]&&ratings[i]<ratings[i+1]))
        {   
            nums=1;
            arr[i]=nums++;
            int j=1;
            while(i-j-1>=0&&ratings[i-j-1]>=ratings[i-j])
            {   if(ratings[i-j]==ratings[i-j+1])
                {   nums=1;
                    arr[i-j]=nums++;}
                else
                    arr[i-j]=nums++;
                j++;}
            //if(i-j==-1)
              //  return i;
            if(i!=0&&ratings[i-j]==ratings[i-j+1]&&arr[i-j]==0)
                arr[i-j]=1;
            else if(i!=0&&ratings[i-j]!=ratings[i-j+1])
                arr[i-j]=(nums>arr[i-j])? nums:arr[i-j];        

                  
            nums=2;j=1;
            while(i+j+1<ratingsSize&&ratings[i+j+1]>=ratings[i+j])
            {   if(ratings[i+j]==ratings[i+j-1])
                {   nums=1;
                    arr[i+j]=nums++;}
                else
                    arr[i+j]=nums++;
                j++;}
            if(i!=ratingsSize-1&&ratings[i+j]==ratings[i+j-1]&&arr[i+j]==0)
                arr[i+j]=1;
            else if(i!=ratingsSize-1&&ratings[i+j]!=ratings[i+j-1])
                arr[i+j]=(nums>arr[i+j])? nums:arr[i+j];
            i=i+j;
        }
    }
    
    int ans=0;
    for(int i=0;i<ratingsSize;i++)
        ans+=arr[i];
    if(ans==0)
        return ratingsSize;
    return ans;
}
```