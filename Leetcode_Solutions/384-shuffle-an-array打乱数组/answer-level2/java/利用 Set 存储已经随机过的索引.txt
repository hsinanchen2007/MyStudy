### 解题思路
没明白官方题解为啥要各种 shadow copy，题目又没做要求，`shuffle()` 更像一个静态工厂方法，用一次就完事了，于是有了自己的写法（见注释）：

### 代码

```java
class Solution {

    int[] nums;
    Random random;

    public Solution(int[] nums) {
        this.nums = nums;
        this.random = new Random(31);
    }
    
    public int[] reset() {
        return nums;
    }
    
    // 解法一（自己写的，又不是不能用）
    // public int[] shuffle() {
    //     Set<Integer> set = new HashSet<>(); 
    //     int len = nums.length;
    //     int[] curNums = new int[len];
    //     for (int i = 0; i < len;) {
    //         int index = random.nextInt(len);
    //         if (set.contains(index)) {
    //             continue;
    //         }
    //         curNums[index] = nums[i];
    //         set.add(index);
    //         i++;
    //     }
    //     return curNums;
    // }

    // 解法二（官方题解）
    public int[] shuffle() {
        int[] array = nums.clone();
        for (int i = 0; i < array.length; i++) {
            swapAt(array, i, randRange(i, array.length));
        }
        return array;
    }

    private int randRange(int min, int max) {
        return random.nextInt(max - min) + min;
    }

    private void swapAt(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
```