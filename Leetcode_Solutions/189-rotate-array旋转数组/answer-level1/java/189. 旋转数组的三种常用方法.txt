# 方法1：一次移动一位
循环k次，一次移动一个
最后一位要特殊处理到第一位
0位置记录下一次要变化的数，用0位置和下一位换

```java
public class Solution {
   public void rotate(int[] nums, int k) {
       for (int i=0;i<k;i++){
           for (int j=0;j<nums.length-1;j++){
               int tmp=nums[j+1];
               nums[j+1]=nums[0];
               nums[0]=tmp;
            }
        }
   }
}
```
**复杂度分析：**
    时间复杂度O（n^2）
    空间复杂度O（1）没有额外使用空间

# 方法2：新建数组
遍历数组给每个位置的值直接将进行换位到一个新数组中
计算得知公式k+i>len的最后位置：k%len-(len-i)就是最后换到的位置
最后把新数组的值赋值给原数组

```java
public class Solution {
    public  void rotate(int[] nums, int k) {
       int newarr[]=new int[nums.length];
       for (int i=0;i<nums.length;i++){
           k=k%nums.length;
           int end=i+k;
           if (end>=nums.length){
               end=k-(nums.length-i);
           }
           newarr[end]=nums[i];
       }
       for (int i=0;i<newarr.length;i++){
           nums[i]=newarr[i];
       }
    }
}
```
**复杂度分析：**
    时间复杂度O（n）
    空间复杂度O（n）

# 方法3：3次旋转
当我们旋转数组 k 次， k%n 个尾部元素会被移动到头部，剩下的元素会被向后移动
先反转整个数组
在反转前k个元素
最后反转n-k个元素
这样就得到我们最后需要的数组
```
原始数组                  : 1 2 3 4 5 6 7
反转所有数字后             : 7 6 5 4 3 2 1
反转前 k 个数字后          : 5 6 7 4 3 2 1
反转后 n-k 个数字后        : 5 6 7 1 2 3 4 --> 结果
```


```java
public class Solution {
    public void rotate(int[] nums, int k) {
        k=k%nums.length;
        reverse(nums,0,nums.length-1);
        reverse(nums,0,k-1);
        reverse(nums,k,nums.length-1);
    }

    public void reverse(int[] nums, int slow, int faste) {
        while (faste>slow){
            int tmp=nums[slow];
            nums[slow]=nums[faste];
            nums[faste]=tmp;
            slow++;
            faste--;
        }
    }
}
```
**复杂度分析：**
