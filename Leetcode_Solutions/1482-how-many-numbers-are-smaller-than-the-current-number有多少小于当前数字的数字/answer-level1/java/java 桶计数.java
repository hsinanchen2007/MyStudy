### 解题思路
首先定义一个足够大的桶，使所有元素都能在桶中找到对应位置
temp[i]:i元素出现了几次
遍历原数组，完成对temp的初始化，然后通过累加的方式计算比当前桶中数据大于或等于的个数
最后用总的个数减去大于等于的个数就是小于的个数
### 代码

```java
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        //因为本题的数据取值范围[0,100]
        int[] temp = new int[101];
        int len = nums.length;
        //将原数组中的元素装到对应的桶中，完成桶的初始化
        for(int i=0;i<nums.length;i++){
            temp[nums[i]]++;
        }
        //通过累加的方式计算比当前桶中数据大于或等于的个数
        for(int i=temp.length-2;i>=0;i--){
            temp[i]+=temp[i+1];
        }
        //总的个数减去大于等于的个数就是小于的个数
        for(int i=0;i<nums.length;i++){
            nums[i]=len-temp[nums[i]];
        }
        return nums;
    }
}
```

```
