```
/* 
 * n的最大值已经为10000，所以十进制上各位数字之和最大为36（当n=9999），
 * 所以使用hash统计和为0~36的数字的个数。
 * 最后使用qsort()对hash数组从大到小的排序。
 */
int Compare(const void * elem1,const void * elem2){
    int e1 = *(int*)elem1;
    int e2 = *(int*)elem2;
    if(e1 < e2) {
        return 1;
    }

    return -1;
}

int countLargestGroup(int n){
    int arr[37] = {0};
    for(int i = 1; i <= n; i++) {
        int temp = i;
        int sum = 0;
        do {
            sum += temp%10;
        } while(temp = temp/10);
        arr[sum]++;
    }
    
    qsort(arr, 37, sizeof(int), Compare);
    
    int ans = 1;
    for(; arr[ans-1] == arr[ans]; ans++);
    
    return ans;
}
```
