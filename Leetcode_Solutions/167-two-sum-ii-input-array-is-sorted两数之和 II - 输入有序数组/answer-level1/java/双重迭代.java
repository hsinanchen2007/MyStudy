### 解题思路
首先，使用第一次迭代缩小遍历范围，在双重迭代时就使用确定好的范围，依次相加，比较两数之和是否等于`target`，找到后返回即可。时间复杂度为`O($n^2$)`

### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {

        int index1 = 0;
        int index2 = 0;
        int limit = numbers.length;
        int[] indexs = new int[2];
        for (int i = 0; i < numbers.length; ++i) {
            if (numbers[i] > target) {
                limit = i + 1;
                break;
            }
        }
        for (int i = 0; i < limit; ++i) {
            int num1 = numbers[i];
            for (int j = i + 1; j < limit; ++j) {
                int num2 = numbers[j];
                if (num1 + num2 == target) {
                    indexs[0] = i + 1;
                    indexs[1] = j + 1;
                    return indexs;
                }
            }
        }

        return indexs;
    }
}
```