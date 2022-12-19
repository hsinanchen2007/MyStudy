### 解题思路
此处撰写解题思路
1.当arr成员之和小于等于target时，返回数组最大数即可；
2.当arr成员之和大于target时
2.1）所有成员均大于平均值，则返回平均值（四舍五入）
2.2）否则，从平均值开始尝试，依次加1，直到绝对值最小
### 代码

```c
int findMaxNum(int* arr, int arrSize)
{
    int i = 0;
    int maxNum = 0;
    
    for(i = 0; i < arrSize; i++)
    {
        if(arr[i] > maxNum)
        {
            maxNum = arr[i];
        }
    }
    
    return maxNum;
}

int findMinNum(int* arr, int arrSize)
{
    int i = 0;
    int minNum = arr[0];
    
    for(i = 1; i < arrSize; i++)
    {
        if(arr[i] < minNum)
        {
            minNum = arr[i];
        }
    }
    
    return minNum;
}

int findDiffValue(int* arr, int arrSize, int bestValue, int target)
{
    int sum = 0;
    int i = 0;
    
    for(i = 0; i < arrSize; i++)
    {
        if(arr[i] <= bestValue)
        {
            sum += arr[i];
        }
        else
        {
            sum += bestValue;          
        }
    }
    
    return (sum > target)?(sum - target):(target - sum);
}

int findBestValue(int* arr, int arrSize, int target)
{
    int i = 0;
    int sum = 0;
    int avgNum = 0;
    int bestValue = 0;
    int diffValue = 0;
    int diffValue2 = 0;
    float tempTarget = target;
    
    for(i = 0; i < arrSize; i++)
    {
        sum += arr[i];
    }
    
    if(sum <= target)
    {
        return findMaxNum(arr, arrSize);
    }
    else
    {
        avgNum = tempTarget/arrSize + 0.5;
        if(avgNum <= findMinNum(arr, arrSize))
        {
            return avgNum;            
        }
        else
        {
            bestValue = avgNum;
            do
            {
                diffValue = findDiffValue(arr, arrSize, bestValue, target);
                bestValue++;
                diffValue2 = findDiffValue(arr, arrSize, bestValue, target);  
            }while(diffValue2 < diffValue);
            
            return (bestValue-1);
        }
    }
}

```