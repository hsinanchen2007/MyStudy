### 解题思路
此处撰写解题思路

### 代码

```c
int minArray(int* numbers, int numbersSize){
    if(numbers == NULL || numbersSize <= 0){
        return 0;
    }
    int left = 0 , right = numbersSize - 1 ;
    while(left < right){
        int mid = (left + right)  / 2 ;
        if(numbers[mid] < numbers[right]){
            right = mid;
        }else if(numbers[mid] > numbers[right]){
            left = mid + 1;
        }else{ // ==
            right--;
        }
    }
    return numbers[left];
}


```