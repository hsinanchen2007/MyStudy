### 解题思路
此处撰写解题思路
对数组进行二分查找，没什么可说的，主要注意两点：
1.当numbers[mid] < numbers[high]时，要将mid留下，因为此时最小值可能就是numbers[mid]。
2.当numbers[mid] == numbers[high]时，无法直接判定最小值在哪一边，我们将high扔掉即可，这样总会遇到不等于的情况，就能分清楚最小值在哪一边了。
### 代码

```c
int minArray(int* numbers, int numbersSize){
    if(numbers[0] < numbers[numbersSize-1])
        return numbers[0];
    int i,low = 0,high = numbersSize-1,mid;
    while(low < high){
        mid = (low+high)/2;
        if(numbers[mid] < numbers[high]){
            high = mid;
        }
        else if(numbers[mid] > numbers[high]){
            low = mid+1;
        }
        else{
            high--;
        }
    }
    return numbers[low];
}
```