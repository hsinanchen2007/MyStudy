### 解题思路
此处撰写解题思路

### 代码

```c
int majorityElement(int* nums, int numsSize){
    int cur;
    int counter = 0;
    for (int i = 0; i < numsSize; i++) {
        if (counter == 0) {
            counter = 1;
            cur = nums[i];
        } else if (cur != nums[i]) {
            counter--;
        } else {
            counter++;
        }       
    }
    if(counter > 0)
        return cur;
    else
        return -1; 
}
```