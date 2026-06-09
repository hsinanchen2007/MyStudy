### 解题思路
> 由于是循环列表, 所以入栈后没有处理成功的需要处理第二遍; 结束条件是第二遍遇到最大值时;
- **重要** 注意边界条件的处理, 提交了好几次,郁闷 :)

### 代码

```python3 [groups1-python3]
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        if not nums:
            return []
        ans = [-1] * len(nums)
        q = collections.deque()
        biggest = nums[0]
        for i, n in enumerate(nums):
            while q and nums[q[-1]] < n:
                top = q.pop()
                ans[top] = n
                if n > biggest:
                    biggest = n
            q.append(i)
        # 由于是循环列表, 一趟找不到, 再查找一遍,直到列表为空;
        for i, n in enumerate(nums):
            while q and nums[q[-1]] < n:
                top = q.pop()
                ans[top] = n
            if biggest == n:
                # 最大元素都没有处理完q中的数据,说明剩下的全是最大值,保持默认的-1输出即可
                break
        return ans
```

```C [groups1-C]
#define MAX_NUM_COUNT 10001

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *nextGreaterElements(int *nums, int numsSize, int *returnSize)
{
    if (nums == NULL || returnSize == NULL) {
        return NULL;
    }
    int stack[MAX_NUM_COUNT];
    int count = 0;
    int biggest = INT_MIN;
    int *result = (int *)malloc(sizeof(int) * numsSize);
    if (result == NULL) {
        return NULL;
    }
    memset(result, 0xff, sizeof(int) * numsSize);
    int i, top;
    for (i = 0; i < numsSize; i++) {
        top = count - 1;
        while (count > 0 && nums[stack[top]] < nums[i]) {
            result[stack[top]] = nums[i];
            top--;
            count--;
        }
        stack[count++] = i;
        if (nums[i] > biggest) {
            biggest = nums[i];
        }
    }

    // 处理第一遍无法找到的场景
    for (i = 0; i < numsSize; i++) {
        top = count - 1;
        while (count > 0 && nums[stack[top]] < nums[i]) {
            result[stack[top]] = nums[i];
            top--;
            count--;
        }
        if (nums[i] == biggest) {
            break;
        }
    }
    *returnSize = numsSize;
    return result;
}
```

# 运行情况
```
执行用时 :228 ms, 在所有 Python3 提交中击败了89.00%的用户
内存消耗 :15 MB, 在所有 Python3 提交中击败了5.10%的用户

执行用时 :112 ms, 在所有 C 提交中击败了80.52%的用户
内存消耗 :15.9 MB, 在所有 C 提交中击败了100.00%的用户
```