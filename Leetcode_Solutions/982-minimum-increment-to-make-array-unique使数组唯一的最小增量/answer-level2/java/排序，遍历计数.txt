### 解题思路
```text
1. 排序
2. 定义list dupElements记录重复元素，排序后，如果后一个元素和前一个元素相等，即为重复元素
3. 如果A[i + 1]和A[i]中间有空位，则用dupElements中的元素进行填充，直到dupElements为空，或没有空位为止，填充的过程中增加计数
4. 遍历结束后，如果dupElements尚不为空，则以当前数组中最大的元素为起点进行递增，递增的过程中，增加计数
```

### 代码

```java
class Solution {
    // 计数
    int count = 0;

    public int minIncrementForUnique(int[] A) {
        // 空数组情况
        if (A.length == 0) {
            return 0;
        }
        // 先排序
        Arrays.sort(A);
        List<Integer> dupElements = new ArrayList<>();
        // 数组中最大的元素
        int curMax = A[A.length - 1];
        // 遍历一遍找出重复元素
        for (int i = 0; i < A.length - 1; i++) {
            // 如果后一个元素和前一个元素相等，则为重复元素
            if (A[i + 1] == A[i]) {
                dupElements.add(A[i + 1]);
            }
            // 如果i+1和i不相等，且大于1，则对已经的dupElements的元素进行计算自增
            // 判断条件：有重复元素；且A[i], A[i + 1]中间有空闲位置
            if (dupElements.size() > 0 && A[i + 1] - A[i] > 1) {
                calcSteps(dupElements, A[i], A[i + 1]);
            }
        }
        // 遍历完成，还有剩余的重复元素，则从数组中最大的元素开始算
        for (int element : dupElements) {
            curMax++;
            count += (curMax - element);
        }
        return count;
    }

    private void calcSteps(List<Integer> dupElements, int start, int end) {
        // 游标，记录当前的位置
        int cursor = start + 1;
        // 记录移除元素的数量
        int num = 0;
        for (int element : dupElements) {
            if (cursor < end) {
                count += (cursor - element);
                // 记录移除元素的数量
                num++;
                cursor++;
            } else {
                // 如果已经到end了，则停止遍历，该区间不能满足要求
                break;
            }
        }
        // 删除前面已经自增的元素，并返回
        for (int i = 0; i < num; i++) {
            dupElements.remove(0);
        }
    }
}
```

### 测试用例
```java
public class SolutionTest {
    Solution solution = new Solution();

    @Test
    public void minIncrementForUnique() {
        int[] input1 = {1,2,2};
        int expect1 = 1;
        int output1 = solution.minIncrementForUnique(input1);
        assertEquals(expect1, output1);

        // 初始化计数
        solution.count = 0;
        int[] input2 = {3,2,1,2,1,7};
        int expect2 = 6;
        int output2 = solution.minIncrementForUnique(input2);
        assertEquals(expect2, output2);
    }
}
```