### 解题思路
求出平均值，只有平均值为3的倍数或者0才有可能3等分，然后就是使用index对A进行遍历，每累加到一个avg值的时候，就将sum归0，继续遍历，当其中一次遍历完全部数字仍然还没有得到sum=avg的结果，则说明无法找到结果，直接返回false

### 代码

```c
bool canThreePartsEqualSum(int* A, int ASize){
    //先找出平均值
    int avg = 0;
    for(int i = 0; i < ASize; i++)
    {
        avg += A[i];
    }
    if(avg % 3 != 0)
        return false;
    avg = avg/3;
    int index = 0;
    int sum = 0;
    for(int i = 0; i <= 2; i++)
    {
        int flag = 0;
        for(; index < ASize; index++)
        {
            sum += A[index];
            if(sum == avg)
            {
                flag = 1;
                index += 1;
                sum = 0;
                break;
            }  
        }
        if(flag == 0)
            return false;
    }
    return true;
}
```