### 解题思路
三个相等部分==总和可以被三整除==每个部分都是总和1/3

### 代码

```c
bool canThreePartsEqualSum(int* A, int ASize){
    //看一下总和是否能被三整除
    int sum=0;
    for(int iter=0;iter<ASize;++iter)
        sum+=A[iter];
    if(sum%3==0)
    {   //从头到位依次加
        int target=sum/3,flag=0;
        sum=0;
        for(int iter=0;iter<ASize;++iter)
            //已经找到两个段的和是总和的2/3就返回正确
            if(flag==2) 
                return 1;
            //累加到总和的1/3时 加一标志 再从0开始加

            else
            {
                sum+=A[iter];
                if(sum==target)
                {
                    ++flag;
                    sum=0;
                }
            }
    }
return 0;
}
```