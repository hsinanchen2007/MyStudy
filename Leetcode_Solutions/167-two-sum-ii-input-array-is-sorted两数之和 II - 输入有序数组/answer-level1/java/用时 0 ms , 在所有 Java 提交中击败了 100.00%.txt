### 解题思路
定义两个指针，如果两个指针指向的数之和大于目标数，那么小指针减一，大指针不变。如果小于就同时加一
### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] res = new int[2];
        for(int i = 1, j = 0;i < numbers.length;i++) {
            if(numbers[i] + numbers[j] == target) {
                res[0] = j + 1; res[1] = i + 1;
                break;
            }else if(numbers[i] + numbers[j] < target) j++;
            else {
                i--;j--;
            }
        }
        return res;
    }
}
```