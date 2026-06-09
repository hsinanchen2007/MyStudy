### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/dd5bbaf308f68a7fb873e18fb2e15a0d62debde554134f22bd26e63114ac8627-image.png)

### 代码

```c
int majorityElement(int* nums, int numsSize){
    int first = nums[0];
    int cnt = 1;
    int second;
    for (int i = 1; i < numsSize; i++) {
        if (cnt == 0) {
            first = nums[i];
            cnt++;
            continue;
        }
        second = nums[i];
        if (second == first) {
            cnt++;
        }
        else {
            cnt--;
        }
    }

    return first;
}
```