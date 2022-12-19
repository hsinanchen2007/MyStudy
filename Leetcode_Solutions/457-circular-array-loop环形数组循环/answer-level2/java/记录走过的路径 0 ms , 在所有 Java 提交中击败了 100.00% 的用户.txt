### 解题思路
题目条件：
1. -1000 ≤ nums[i] ≤ 1000
2. nums[i] ≠ 0
3. 1 ≤ nums.length ≤ 5000

从头开始遍历数组，每一次循环都改变遍历过的数组元素，正数赋值为一个新的不在题目给出范围内的正数，负数同理（正负表示路径的方向。赋值的数字每一次循环都会更新，保证每条路径的唯一）。
赋值过的数组元素则不再遍历，因为肯定不是一个环。
每一次while循环，创建一个变量start来确认是否移动了，如果只是一个长度为1的环则无视掉。
发现环的条件是：在当前路径当中，如果遍历到赋值过的元素并且长度不为1，则这是一个有效的环。
### 代码

```java
class Solution {
    public boolean circularArrayLoop(int[] nums) {
        int curr1 = 1001;
        int curr2 = -1001;
        for (int i = 0; i < nums.length; i++){
            if (nums[i] < 1001 && nums[i] > -1001){
                int r = i;
                int direction = nums[i];
                while (true){
                    int start = r;
                    int tmp = nums[r] % nums.length;
                    if (tmp * direction < 0){
                        break;
                    }
                    nums[r] = nums[r] >= 0 ? curr1 : curr2;

                    if (r + tmp > nums.length - 1){
                        r = tmp - (nums.length - r);
                    }
                    else if (r + tmp < 0){
                        r = nums.length + (r + tmp);
                    }
                    else{
                        r += tmp;
                    }

                    if (r == start){
                        nums[r] = nums[r] >= 0 ? curr1 : curr2;
                        break;
                    }
                    if (nums[r] == curr1 || nums[r] == curr2){
                        return true;
                    }

                    if (nums[r] >= 1001 || nums[r] <= -1001){
                        break;
                    }
                }
            }
            curr1++;
            curr2--;
        }
        return false;
    }
}
```