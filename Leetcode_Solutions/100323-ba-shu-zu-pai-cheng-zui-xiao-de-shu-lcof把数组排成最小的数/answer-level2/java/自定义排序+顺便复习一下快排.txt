### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String minNumber(int[] nums) {
        quickSort(nums, 0, nums.length - 1);
        String res = "";
        for(int t : nums)
            res += t;
        return res;
    }

    public void quickSort(int[] nums, int l, int r){
        int i = l;
        int j = r;
        int pivot = nums[(l+r)/2];
        while(i <= j){
            while(compare(nums[i], pivot))
                i++;
            while(compare(pivot, nums[j]))
                j--;
            //i==j的位置是pivot应该放置的位置
            if(i<=j){
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j]  = tmp;
                i++;
                j--;
            }
        }
        if(l<j)
            quickSort(nums, l, j);
        if(i<r)
            quickSort(nums, i, r);
    }

    public boolean compare(int a, int b){
        String ab = a+""+b;
        String ba = b+""+a;
        return ab.compareTo(ba)<0 ? true:false;
    }
}
```