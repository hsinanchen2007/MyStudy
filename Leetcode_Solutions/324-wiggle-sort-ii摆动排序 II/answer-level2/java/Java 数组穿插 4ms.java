### 解题思路
比较简单的解法就是：
1. 先将数组排序；
2. 从中间位置切分，分为前半部分A和后半部分B；
3. 将B穿插到A中，生成一个新数组。
需要注意的点有：
- 如果数组长度是奇数，则中间元素是属于前半部分；
- 由于数组元素可能重复，所以穿插后重复元素可能会相邻，此时不满足题意；因此需将前后部分分别倒序；
### 代码

```java
class Solution {
    public void wiggleSort(int[] nums) {
        Arrays.sort(nums);
        int arr[]=new int[nums.length];
        int mid=nums.length/2;
        mid=nums.length%2==0?mid-1:mid;
        //将前半部分倒序
        for(int i=mid;i>=0;i--)
            arr[mid-i]=nums[i];
        //将后半部分倒序
        for(int i=nums.length-1;i>mid;i--)
            arr[nums.length-i+mid]=nums[i];
        //将前半部分插空排好
        for(int i=0;i<=mid;i++){
            nums[2*i]=arr[i];
        }
        //将后半部分插入
        int j=1;
        for(int i=1;i<nums.length;i+=2)
            nums[i]=arr[mid+(j++)];
    }
}
```