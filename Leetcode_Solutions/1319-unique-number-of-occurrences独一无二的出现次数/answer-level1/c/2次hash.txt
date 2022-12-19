执行用时 :0 ms, 在所有 c 提交中击败了100.00%的用户
内存消耗 :7.1 MB, 在所有 c 提交中击败了100.00%的用户

第一次用传入的参数，作为key，init hash map；
第二次一第一次制作的hash map为key，init hash map2；

```
bool uniqueOccurrences(int* arr, int arrSize){
    
    int hash_table[2000];
    int hash_res_table[2000];
    memset(hash_table, 0, sizeof(int)*2000);
    memset(hash_res_table, 0, sizeof(int)*2000);
    int i = 0;
    
    while(i < arrSize){
        if(arr[i] < 0)
            hash_table[(arr[i] * -1)]++;
        else
            hash_table[(arr[i] + 1000)]++;
        i++;
    }
    
    i = 0;
    while(i < 2000){
        if(hash_table[i] > 0)
            hash_res_table[hash_table[i]]++;
        if(hash_res_table[hash_table[i]] > 1)
            return false;
        i++;
    } 
    return true;
}
```


