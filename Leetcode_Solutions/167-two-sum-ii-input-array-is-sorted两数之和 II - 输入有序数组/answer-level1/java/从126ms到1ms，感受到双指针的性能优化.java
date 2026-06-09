### 解题思路
1，双重for循环遍历，
2，双指针

### 代码

解法二：
```java
class Solution {
   public int[] twoSum(int[] numbers, int target) {
        int[] result = {0,0};
        int left = 0;
        int right = numbers.length-1;
        while (left<right) {
            int sum = numbers[left] + numbers[right];
            if (sum > target){
                right--;
            }
            if (sum < target) {
                left++;
            }
            if (sum == target) {
                result[0] = left+1;
                result[1] = right+1;
                break;
            }
        }
        return result;
    }
}

解法一：
public int[] twoSum(int[] numbers, int target) {
        int[] result = {0,0};
        for (int i = 0; i < numbers.length; ++i) {
            for (int j = i+1; j < numbers.length; ++j) {
                if ((numbers[i] + numbers[j]) == target) {
                    result[0] = i+1;
                    result[1] = j+1;
                }
            }
        }
        return result;
    }
```