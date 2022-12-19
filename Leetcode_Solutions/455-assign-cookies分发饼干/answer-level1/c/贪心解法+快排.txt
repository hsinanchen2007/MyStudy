这里我们的想法是用最大的饼干去满足最大胃口的小朋友（跟最小饼干去满足胃口最小的其实是一样的），我们只需要将2个数组都排好序，从后往前扫描，如果有最大的饼干满足某一个小朋友就将其分配给那个小朋友（这里要设置一个计数器计一下满足了多少个小朋友），然后这里最关键的是排序。整题的时间复杂度高的地方也就是在排序的位置。后面匹配小朋友顶多就是线性时间。我刚开始嫌麻烦就写了个冒泡排序尝试了一下，结果超时然后我就换了个快排，轻松通过。
```
void quicksort(int *arr, int low, int high)
{
    int i,j,temp;
    i = low;
    j = high;
    if(low < high)
    {
        temp  = arr[low];
        while(i<j)
        {
            //从后向前找比第一个小的，把小的拿前面来
            while(i < j && arr[j] > temp)
            {
                j--;
            }
            if(i < j)
            {
                arr[i] = arr[j];
                i++;
            }

            //从前向后找比第一个大的，把大的扔后面去
            while( i < j && arr[i] < temp)
            {
                i++;
            }
            if(i < j)
            {
                arr[j] = arr[i];
                j--;
            }
        }
        arr[i] = temp;
        quicksort(arr, low, i-1);
        quicksort(arr,i+1,high);
    }

}
int findContentChildren(int* g, int gSize, int* s, int sSize){

int i,j,count,temp;

//给小孩胃口和饼干尺寸排序
quicksort(g,0,gSize-1);
quicksort(s,0,sSize-1);

//从而向前扫描
i = gSize-1; 
j = sSize-1; 
count = 0;
while(i>= 0 && j >= 0)
{
    if(s[j] >= g[i]) 
    {
        j--;
        i--;
        count++; //碰到满足的计数器要加1
    }else if(s[j] < g[i]) //如果碰到最大的饼干尺寸不能满足该小朋友就直接跳过它去找下一个大胃口的小朋友
    {
        i--;
    }

}
return count;
}
```
