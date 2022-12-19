1、每次把数组分成两半，递归找到这两半的目标值起始点和目标值终止点
2、递归的终止条件是:
    1)目标值比整个子数组都小，或比整个子数组都大
    2)目标值只有1个元素时
3、如果左半部分的起始点能找到，则整体的起始点就是左部分的起始点，否则为右部分的起始点
4、如果有半部分的终止点能找到，则整体的终止点就是右部分的终止点，否则为左部分的终止点

typedef struct {
    int start;
    int end;
} Range;

Range Search(int* nums, int left, int right, int target)
{
    Range result;
    result.start = -1;
    result.end = -1;
    //超出了查找范围，直接返回-1
    if (nums[left] > target || nums[right] < target) {
        return result;
    }
    if (left == right) {
        //只有1个元素时，如果找到了则起始点和终止点都是该元素，否则返回-1
        if (nums[left] == target) {
            result.start = left;
            result.end = left;
        }
        return result;
    }
    int mid = left + (right - left) / 2;
    Range leftResult, rightResult;
    //递归查找左半部分的起始点、终止点；以及右半部分的起始点，终止点
    leftResult = Search(nums, left, mid, target);
    rightResult = Search(nums, mid + 1, right, target);
    //优先取左半部分的起始点作为最终的起始点
    if (leftResult.start != -1) {
        result.start = leftResult.start;
    } else {
        result.start = rightResult.start;
    }
    //优先取右半部分的终止点作为最终的终止点
    if (rightResult.start != -1) {
        result.end = rightResult.end;
    } else {
        result.end = leftResult.end;
    }
    return result;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int* ret = malloc(sizeof(int) * 2);
    *returnSize = 2;
    if (numsSize <= 0) {
        ret[0] = -1;
        ret[1] = -1;
        return ret;
    }
    Range result = Search(nums, 0, numsSize - 1, target);
    ret[0] = result.start;
    ret[1] = result.end;
    return ret;
}