#### 比较慢的初始版本

初始考虑，使用两个指针。
由于要保证顺序，所以两个指针从同一方向往另一方向移动


第一个指针从数组头部开始出发，找到第一个零元素位置后停止。
第二个指针从第一个指针后一位置开始，找到第一个非零元素位置停止；
然后两个位置的元素交换
具体的代码是:

```java
class Solution {
    public void moveZeroes(int[] nums) {
        for(int i =0;i<nums.length;i++){
            if(nums[i] != 0){
                continue;
            }
            for(int j=i+1;j<nums.length;j++){
                if(nums[j] != 0){
                    nums[i] = nums[j];
                    nums[j] = 0;
                    break;
                }
            }
        }
    }
}
```
执行花了整整9ms
时间复杂度 O(n^2)
空间复杂度 O(n)


#### 结合其他题解的优化版本

这里的核心思想是一样的

也是用两个指针，
第一个指针直接指向当前非零的元素，第二个指针向后查找

不同的是，针对数组头部的非零元素，直接用
```java
                nums[i] = nums[j];
                if( i!= j){
                    nums[j] =0;
                }
```
这一小段代码中有两个关键因素
+ 在非零元素存在时，第一个指针一定要向右移动
+ 保证只有在第二个指针所指位置不一样，即需要发生元素交换时，才进行交换

这里好像有点废话

整体的代码就是这样:
```java
class Solution {
    public void moveZeroes(int[] nums) {
        int i =0;
        for(int j=0;j<nums.length;j++){
            if(nums[j] != 0){
                nums[i] = nums[j];
                if( i!= j){
                    nums[j] =0;
                }
                i++;
            }
        }
    }
}
```