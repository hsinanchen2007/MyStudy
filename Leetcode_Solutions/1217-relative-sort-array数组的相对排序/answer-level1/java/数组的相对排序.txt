### 解题思路
   由于arr1,arr2中的数字大小都是从0-1000，因此设定一个新数组nums（桶），它的大小为1000。将arr1中每个元素按它的值存储到相应的桶中（值为2，存到nums[2]）。之后遍历arr2，
每遍历一个元素arr[i]，就到nums[arr[i]]中找它，把桶里的数倒入最后返回数组res中。遍历
完arr2，再将nums中剩下的元素按序号放入res中。

### 代码

```java
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        //该题是一个桶排序的经典例子
        int [] nums=new int [1001];  //一个arr1重新排序的数组
        int [] res=new int [arr1.length];
        //遍历arr1，统计每个元素的数量
        for(int i:arr1)
        {
            nums[i]++;
        }
        //遍历arr2，处理arr2中出现过的元素
        int index=0;     //res数组中的序号
        for(int i:arr2)
        {
            while(nums[i]>0)
            {
                res[index++]=i;
                nums[i]--;
            }
        }
        //遍历完arr2,处理剩下arr2中未出现的元素
        for(int i=0;i<nums.length;i++)
        {
            while(nums[i]>0)
            {
                res[index++]=i;
                nums[i]--;
            }
        }
        return res;     
    }
}
```