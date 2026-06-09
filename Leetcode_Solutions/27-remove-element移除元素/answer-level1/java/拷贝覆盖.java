### 解题思路
主要思路是遍历数组nums，每次取出的数字变量为num，同时设置一个下标ans
在遍历过程中如果出现数字与需要移除的值不相同时，则进行拷贝覆盖nums[ans] = num，ans自增1
如果相同的时候，则跳过该数字不进行拷贝覆盖，最后ans即为新的数组长度
这种思路在移除元素较多时更适合使用，最极端的情况是全部元素都需要移除，遍历一遍结束即可
时间复杂度：O(n)，空间复杂度：O(1)


### 代码

```java
class Solution {
       public static int removeElement(int[] nums, int val) {
        int ans=0;
        for (int i:nums) {
            if (i!=val){
                nums[ans]=i;
                ans++;
            }
        }
        return ans;
    }
}
```