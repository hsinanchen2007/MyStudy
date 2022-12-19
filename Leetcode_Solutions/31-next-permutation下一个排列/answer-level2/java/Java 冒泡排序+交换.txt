### 解题思路
此处撰写解题思路
从末尾遍历，找到一个数的下标，这个数满足：1、后面仅存在一个比其大的数；2、这个数的下标是所有满足1条件中的最大的。
如果存在，和后面比其大的数进行交换，同时该数后面的数列 按升序排列
如果不存在，对数组进行升序排列
### 代码

```java
class Solution {
    public void nextPermutation(int[] nums) {
         //从末尾遍历，找到一个数的下标，这个数满足：1、后面仅存在一个比其大的数；2、这个数的下标是所有满足1条件中的最大的。
        int index = -1;
        int index2 = -1;
        boolean finded = false;
        for (int i = nums.length - 1; i > -1; i--) {
            for (int j = i - 1; j > -1; j--) {
                if (nums[j] < nums[i]) {
                    finded = true;
                    if (index < j) {
                        index = j;
                        index2 = i;
                    }
                }
            }

        }

        //如果存在，和最后一个数互换
        if (finded) {
            // 该数后面的数列 按升序排列
            exchangeNums(nums, index, index2);
            for (int i = index + 1; i < nums.length; i++) {
                for (int j = i; j < nums.length; j++) {
                    if (nums[i] > nums[j]) {
                        exchangeNums(nums, i, j);
                    }
                }
            }
        } else {
            for (int i = 0; i < nums.length; i++) {
                for (int j = i; j < nums.length; j++) {
                    if (nums[i] > nums[j]) {
                        exchangeNums(nums, i, j);
                    }
                }
            }
        }
        
    }

    public void exchangeNums(int[] nums, int n1, int n2) {
        nums[n1] = nums[n1] + nums[n2];
        nums[n2] = nums[n1] - nums[n2];
        nums[n1] = nums[n1] - nums[n2];
    }
    
}
```