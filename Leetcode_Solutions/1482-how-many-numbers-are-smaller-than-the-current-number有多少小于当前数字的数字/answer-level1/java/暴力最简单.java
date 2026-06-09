### 解题思路
两层循环，从第一个开始，和后面的每一个进行比较
如果满足条件，总数加1
执行完一个i，表示比完了一个初始数，把此时的count放入新数组，如此往复，得到新数组

### 代码

```java
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] newNum = new int[nums.length];
        for (int i = 0;i < nums.length;i++){
            int count = 0;
            for (int j = 0;j < nums.length;j++){
                if (nums[i] > nums[j]){
                    count++;
                }
            }
            newNum[i] = count;
        }
        return newNum;

    }
}
```