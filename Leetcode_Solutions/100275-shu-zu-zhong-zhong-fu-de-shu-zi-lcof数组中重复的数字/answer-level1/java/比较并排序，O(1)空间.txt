### 解题思路
由0到n-1构成了一个特殊的数组：
其中必然有一些index上的值nums[i] = i，
若没有,我们通过交换nums[i]和nums[nums[i]]重新排序数组（一种特殊的排序方法），
通过循环这一过程，每个经过的i都完成了一次这样的链式交换，
在这一过程中，查找重复的值。

for循环的最后，必然得到已经排序好的数组,最后一个i有两种情况:
1.为重复的值，在前面排序好的数组中必然找到和它相等的数；
2.为nums[i] == i,那么它是一个内层循环遍历不到的值，或者之前有重复的值，但已经找到并退出了。

算法复杂度：
虽然有两层循环，但是真正的排序过程（链式交换）只需要O(n)的时间复杂度，其他操作常数时间。
额外空间O(1)，只用到了几个中间变量。
### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        if(nums == null || nums.length == 0) return 0;
        for(int i = 0; i <nums.length; i++){
            while(nums[i] != i){
                if(nums[i] == nums[nums[i]]){
                    return nums[i];
                }else{
                    int temp = nums[i];
                    nums[i] = nums[temp];
                    nums[temp] = temp;
                }
            }
        }
        return 0;
    }
}
```