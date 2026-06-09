### 解题思路
老哈希了

### 代码

```c
bool uniqueOccurrences(int* arr, int arrSize){
    int a[2000]={0},b[1000]={0};
    int i=0;
    while(i<arrSize){
        a[arr[i]+1000]++;
        i++;
    }
    i=0;
    while(i<2000){
        if(a[i]!=0){
            if(b[a[i]]==0){
                b[a[i]]++;   
            }else{
                return false;
            }
        }
        i++;
    }
    return true;
}
```