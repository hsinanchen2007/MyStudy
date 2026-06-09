### 解题思路
评论中的三路快排思想很经典，代码也很优雅。
这里谈谈自己的思路。
1. 设立首尾变量i（初始值为0），j（初始值为nums.length-1）用来标识遍历的位置
2. nums[i]为0时，i++；nums[j]为2时，j--;
3. nums[i]为1或2，nums[j]为0或1
4. 分四种情况进行讨论，其中特别要注意的是当nums[i]为1且nums[j]为1时，可以先用List存储i的位置，然后i++，继续遍历，当遍历到0（可能是从i->或者<-j这两方向）时，List出栈，进行交换。

### 代码

```java
class Solution {
    public void sortColors(int[] nums) {
        int i = 0;
        int j = nums.length - 1;
        List<Integer> list = new ArrayList<>();
        while (i <= j){
            //找到不为0的第一个数
            while (i <= j && nums[i] == 0){
                if (list.size() != 0){
                    Integer remove = list.remove(0);
                    swap(nums,remove,i);
                }
                else
                    i++;
            }
            //找到不为2的第一个数
            while (i <= j && nums[j] == 2){
                j--;
            }
            if (i <= j && nums[i] == 1 && nums[j] == 0){
                if (list.size() != 0){
                    Integer remove = list.remove(0);
                    swap(nums,remove,j);
                }
                else{
                    swap(nums,i,j);
                    i++;
                }
            }
            else if (i <= j && nums[i] == 2 && nums[j] == 0){
                if (list.size() != 0){
                    Integer remove = list.remove(0);
                    swap(nums,remove,j);
                }
                else {
                    swap(nums,i,j);
                    i++;
                    j--;
                }
            }
            else if (i <= j && nums[i] == 2 && nums[j] == 1){
                swap(nums,i,j);
                j--;
            }
            //两边扫描到的都是1
            else if (i <= j && nums[i] == 1 && nums[j] == 1){
                list.add(i);
                i++;
            }
        }
    }
    
    private void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
```