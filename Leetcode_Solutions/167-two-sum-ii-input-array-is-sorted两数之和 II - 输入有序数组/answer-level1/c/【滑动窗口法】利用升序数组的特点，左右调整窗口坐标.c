### 解题思路
想法：由于数组是有序且是升序数组，因此，肯定暴力法肯定会超时。暴力法的时间复杂度为O(n^2)
原来想用二分法，发现还是超时。
后来，觉得可以通过不断的比较两数之和的大小，来确定窗口左坐标还是窗口右坐标的移动，可以一次遍历完，从而时间复杂度为O（n）。
![image.png](https://pic.leetcode-cn.com/81a02579d2401a0975c1dbfbac81b81626ea775fd8eb282272a57a332745bddc-image.png)


### 代码

```c
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int left = 0;
	int right = numbersSize - 1;
    int *ret = NULL;
    ret = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;
    ret[0] = ret[1] = 0;

    while (left < right) {
            if(numbers[left] + numbers[right] == target) {
                ret[0] = left + 1;
                ret[1] = right + 1;
                break;
            }
			else if(numbers[left] + numbers[right] > target) {
                right--;
            }
			else if(numbers[left] + numbers[right] < target) {
                left++;
            }

    }
    
    return ret;
}

```