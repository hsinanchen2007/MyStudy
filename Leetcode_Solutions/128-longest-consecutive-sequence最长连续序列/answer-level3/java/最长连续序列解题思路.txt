### 解题思路
1. 对每个数据进行标记，默认都是可以使用的。
2. 遍历数组，如果应使用过的不再使用，未使用过的标记未不可再使用。
3. 对每个数字分别向左+1和向右-1，如果结果能在数组中找到，就长度加1，并将找到的数字标记为不可再使用。
4. 最后比较选择最长的长度。

### 代码

```java
class Solution {
    public int longestConsecutive(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }

        Map<Integer, Boolean> numsMap = new HashMap<>();
        for(int num : nums) { 
            numsMap.put(num, true);
        }

        int length = 1;
        for(int num : nums) {
            if (!numsMap.get(num)) {
                continue;
            }

            int curNum1 = num, curNum2 = num;
            int curLength = 1;

            while(true){
                curNum1 = curNum1 + 1;
                if (numsMap.get(curNum1) == null) {
                    break;
                }
                numsMap.put(curNum1, false);
                curLength++;
            }

            while(true) {
                curNum2 = curNum2 - 1;
                if (numsMap.get(curNum2) == null) {
                    break;
                }
                numsMap.put(curNum2, false);
                curLength++;
            }

            if(curLength > length) {
                length = curLength;
            }
        }

        // Set<Integer> numSet = new HashSet<>();
        // for(int num : nums) {
        //     numSet.add(num);
        // }

        // int length = 1;
        // for(int num : nums) {
        //     int curNum1 = num, curNum2 = num;
        //     int curLength = 1;
        //     while(true){
        //         curNum1 = curNum1 + 1;
        //         if (!numSet.contains(curNum1)) {
        //             break;
        //         }
        //         curLength++;
        //     }

        //     while(true) {
        //         curNum2 = curNum2 - 1;
        //         if (!numSet.contains(curNum2)) {
        //             break;
        //         }
        //         curLength++;
        //     }

        //     if(curLength > length) {
        //         length = curLength;
        //     }
        // }
        return length;
    }
}
```