### 解题思路
这里有一个非负整数数组 arr，你最开始位于该数组的起始下标 start 处。当你位于下标 i 处时，你可以跳到 i + arr[i] 或者 i - arr[i]。

请你判断自己是否能够跳到对应元素值为 0 的 任意 下标处。

注意，不管是什么情况下，你都无法跳到数组之外。

 

示例 1：

输入：arr = [4,2,3,0,3,1,2], start = 5
输出：true
解释：
到达值为 0 的下标 3 有以下可能方案： 
下标 5 -> 下标 4 -> 下标 1 -> 下标 3 
下标 5 -> 下标 6 -> 下标 4 -> 下标 1 -> 下标 3 





用全局flag标记的话，  
因为是全局变量，每次测试前要清零，

### 代码

```c
int flag[50000] = {0};

bool digui(int* arr, int arrSize, int start){
        bool res = false;
        int k = 0;

        if(arr[start] == -1){
            printf("flag[%d] has entried\n",start);
            return false;
        }

        k = arr[start];
        arr[start] = -1;
        
        if(k == 0)
            return true;
        
        if(start - k >= 0)
            res = res || digui(arr,arrSize,start - k);
        if(start + k < arrSize)
            res = res || digui(arr,arrSize,start + k);
        
        return res;
}


bool digui2(int* arr, int arrSize, int start){
        bool res = false;
        int k = 0;

        if(flag[start] == -1){
            printf("flag[%d] has entried\n",start);
            return false;
        }

        k = arr[start];
        flag[start] = -1;
        
        if(k == 0){
            memset(flag,0,50000);
            return true;
        }

        if(start - k >= 0)
            res = res || digui(arr,arrSize,start - k);
        if(start + k < arrSize)
            res = res || digui(arr,arrSize,start + k);
        
        return res;
}


bool canReach(int* arr, int arrSize, int start){
#if 1
    if(start >= arrSize || start < 0 || arr[start]==-1)
        return false;
  
    if(arr[start] == 0)
        return true;
    
    int t = arr[start];
    arr[start] = -1;
    return (canReach(arr,arrSize,start + t) || canReach(arr,arrSize,start - t));

#else
    //return digui2(arr,arrSize,start);
#endif
}
```