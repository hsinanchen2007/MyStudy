![5FC4E939-D53D-4998-9EA8-E343AB1BEAE5.jpeg](https://pic.leetcode-cn.com/a68245938cda71e134e5e2e6d52978c19d0028e571ad31d812ae77da95e81dba-5FC4E939-D53D-4998-9EA8-E343AB1BEAE5.jpeg)

```
int FindMaxValPos(int* nums, int numsSize)
{
    int pos = numsSize - 1;
    int i = 0;
    int maxVal = nums[numsSize - 1];
    for (i = 0; i < numsSize; i++) {
        if (maxVal <= nums[i]) {
            maxVal = nums[i];
            pos = i;
        } else {
            break;
        }
    }
    return pos;
}

bool Find2Divided(int *nums, int left, int right, int target, int *data)
{
    int middle;
    while (left < right) {
        middle = left + (right - left) / 2;
        if (nums[middle] == target) {
            *data = middle;
            return true;
        } else if (nums[middle] < target) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    return false;
}

int search(int* nums, int numsSize, int target)
{
    if ((nums == NULL) || (numsSize == 0)) {
        return -1;
    }
    int pos;
    int left;
    int right;
    int middle;
    bool isTrue;
    int data;
    pos = FindMaxValPos(nums, numsSize);
    //printf("pos: %d\n", pos);
    //未变更
    if (pos == numsSize - 1) {
        if (nums[0] == target) {
            return 0;
        } else if (nums[numsSize - 1] == target) {
            return numsSize - 1;
        }
        isTrue = Find2Divided(nums, 0, numsSize - 1, target, &data);
        if(isTrue == true) {
            return data;
        } else {
            return -1;
        }
    }
    //已变更
    if (nums[numsSize - 1] == target) {
        return numsSize - 1;
    } else if (nums[numsSize - 1] > target) {
        if (nums[pos + 1] == target) {
            return pos + 1;
        }
        isTrue = Find2Divided(nums, pos + 1, numsSize - 1, target, &data);
        if(isTrue == true) {
            return data;
        }
    } else {
        if (nums[pos] == target) {
            return pos;
        } else if (nums[pos] < target) {
            return -1;
        } else {
            if (nums[0] == target) {
                return 0;
            }
            isTrue = Find2Divided(nums, 0, pos, target, &data);
            if(isTrue == true) {
                return data;
            }
        }
    }

    return -1;
}
```
