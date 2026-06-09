### 解题思路
首先再遍历已知数组的过程中记录0的个数，因题目中没有明确提示顺序故通过集合的sort函数对其排序
通过set的定义来判断除0外是否有重复元素，有则直接返回false；
然后判断余下元素最大与最小之差是否超过4（4个0时即差为0），超过则不为顺子

### 代码

```java
class Solution {
    public boolean isStraight(int[] nums) {
        ArrayList<Integer> arrayList =new ArrayList<Integer>();
        int nums_0=0;
        for(int i=0;i<5;i++)
        {
            if(nums[i]==0) {
                nums_0++;
            }
            arrayList.add(nums[i]);
        }
        Collections.sort(arrayList);
        Set<Integer> set = new HashSet<Integer>();
        for(int i=nums_0;i<5;i++)
        {
            if(set.add(arrayList.get(i))){
            }
            else{
                return false;
            }
        }
        if((arrayList.get(4)-arrayList.get(nums_0))<=4){
            return true;
        }
        return false;
    }
}
```