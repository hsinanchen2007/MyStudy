**思路1：** 如果数组是无序的我们可以使用暴力枚举，或者hash表存储访问过的元素，但是题目又多了一个条件就是**数组是有序的**。既然数组是有序的，我们就要充分利用有序的条件，使用双指针的方式：左指针初始指向最小值，右指针初始指向最大值，不断将左右指针的和与target对比并调整左右区间，直到找到结果。
```
public int[] TwoSum(int[] numbers, int target)
        {
            int[] result = new int[2];
            int left = 0;
            int right = numbers.Length - 1;

            while (left < right)
            {
                if (numbers[left] + numbers[right] == target)
                {
                    result[0] = left + 1;
                    result[1] = right + 1;
                    return result;
                }
                else if (numbers[left] + numbers[right] > target)
                {
                    right--;
                }
                else
                {
                    left++;
                }

            }

            return result;
        }
```
