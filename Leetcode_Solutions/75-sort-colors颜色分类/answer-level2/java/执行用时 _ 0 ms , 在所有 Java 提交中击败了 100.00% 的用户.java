### 解题思路
基本思路：
一次遍历，将0与前面的元素交换，将2于后面的元素交换。

具体实现：
1：创建两个下标，int indexOfZero = 0, indexOfTwo = len-1;一个表示排序后最右边0的位置，一个表示排序后最左边2的位置。遍历的元素为0或者2时就交换，每次交换后对应坐标就往中间移动；
2：遍历数组，遍历到排序后最左边2的位置即可。因为后面的元素都是2，而表示2的坐标已经前移，遍历后面的元素会将已经归位的2又交换到前面；
3：每次交换2时，遍历需要往回退一步。因为交换的是后面的没有被遍历的元素，需要退一步检查该元素。也正是因为如此，虽然遍历到排序后最左边2的位置停止，但实际上遍历了所有元素。
### 代码

```java
class Solution {
    public void sortColors (int[] nums) {
        int len = nums.length;
        int indexOfZero = 0, indexOfTwo = len-1;//创建两个下标表示0和2的位置
        for (int scan = 0; scan <= indexOfTwo;scan++) {  //遍历到2的位置停止，后面元素都是2，但表示2的下标已经前移了。
            if (nums[scan] == 0) {
                swap(nums,scan,indexOfZero);//遇到0就交换
                indexOfZero++;//表示0的下标往中间移动
            }

            if (nums[scan] == 2) {
                swap(nums,scan,indexOfTwo);//遇到2就交换
                indexOfTwo--;//表示2的下标往中间移动
                scan--;//遍历退一步，因为该元素是从数组后半部分交换来的，尚未遍历，需要继续扫描该元素。
            }
        }
    }

    public static void swap (int[] array,int i,int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}











```