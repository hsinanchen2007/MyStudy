### 解题思路
此处撰写解题思路

想法很简单，当一个数组创建出来之后所有位置均为0，当一个目标值不为0时则将其目标位置后面的所有元素都向后移动一个位置，然后将目标值插入指定位置就行了。如果为0直接插入元素就好。开始没有看到提示上说所有元素 >0 所以考虑了负数的情况


### 代码

```java
class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        int[] target = new int[nums.length];
        for ( int i = 0; i < nums.length;i++){
            if (target[index[i]] != 0) {
                target = this.move(target,index[i],nums[i]);
            } else {
                target[index[i]] = nums[i];
            }
        }
        return target;
    }

    // 移动后面的元素将目标元素插入指定位置
    private int[] move(int[] array,int index,int value) {
        int num = index;
        while(array[++index] > 0);
        while(index > num) {
            array[index--] = array[index];
        }
        array[num] = value;
        return array;
    }
}
```