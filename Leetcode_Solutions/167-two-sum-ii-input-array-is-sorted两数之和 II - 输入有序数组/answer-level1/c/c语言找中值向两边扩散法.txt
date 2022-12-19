# 思路

耗时4ms，内存6.2m。

思路很简单，就是先找数组中target/2的前后两个值，然后慢慢向两边扩散。

# 示例

[0,2,4,5,8] target为7

1. 先找7/2=3.5前后的，也就是2和4这两个，获取其指针，front指向2，back指向4
2. 2+4<7，所以back++，也就是指向5
3. 2+5==7，所以成功返回

```c
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    *returnSize=2;
    int *result = (int*)malloc(sizeof(int)*2);
    double mid = (double)target / 2.0;
    int sum = 0;
    int i = 0;
    int* front =NULL;
    int* back = NULL;

    //寻找target中值位置
    for(i = 0; i < numbersSize; ++i){
        if((double)numbers[i]> mid) break;
        else if ((double)numbers[i]==mid) {
            ++i;
            break;
        }
    }
        
    //两个指针，分别两边扩散
    front = numbers + i - 1;   
    back = numbers + i;
    while(true){
        sum = *front+*back;
        if(sum == target) break;
        else if (sum>target) front--;
        else back++;
    }
    result[0] = front - numbers + 1;
    result[1] = back - numbers + 1;

    return result;
}
```
