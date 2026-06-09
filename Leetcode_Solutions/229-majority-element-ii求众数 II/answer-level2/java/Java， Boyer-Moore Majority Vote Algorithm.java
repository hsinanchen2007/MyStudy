首先可以明确的一点是，这样的元素可能有0个、1个、或者2个，再没有别的情况了。
然后，用Boyer-Moore算法思路，但与leetcode169有些区别，需要些改动：
1)满足条件的元素最多有两个，那么需要两组变量。原本的的cnt, major变成了cnt1, major1; cnt2, major2。
2)选出的两个元素，需要验证它们的出现次数是否真的满足条件。


```
class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int major1, cnt1, major2, cnt2;
        major1=cnt1=major2=cnt2=0;
        int len = nums.length;
        for(int i=0;i<len;i++){
            if(cnt1 == 0 && major2 != nums[i]){
                major1 = nums[i];
                cnt1 = 1;
            } else if(cnt2 == 0 && major1!=nums[i]){
                major2 = nums[i];
                cnt2 = 1;
            } else if(major1 == nums[i]){
                cnt1++;
            } else if(major2 == nums[i]) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1=cnt2=0;
        for(int n : nums){
            if(n==major1)
                cnt1++;
            else if(n==major2)
                cnt2++;
        }
        List<Integer> list = new ArrayList<>();

        if (cnt1>len/3)
            list.add(major1);
        if (cnt2>len/3)
            list.add(major2);
        return list;
    }
}
```