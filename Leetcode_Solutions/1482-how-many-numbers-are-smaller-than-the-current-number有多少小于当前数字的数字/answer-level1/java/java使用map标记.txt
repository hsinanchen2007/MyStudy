![image.png](https://pic.leetcode-cn.com/ac8cbf49230cf5d191fcf03f129634a2d966440898182532c7f3cb23a26379bc-image.png)

首先需要定义一个数组fre来记录nums数组中各个数出现的次数。
在进行初始化fre数组时我们需要进行初始化，由于nums中可能会有0，所以将fre中的元素初始化为-1。
标记完毕之后，如果fre[i] == -1，就代表i这个数在nums中没有出现，除此之外的i出现的次数为fre[i]+1
其次需要解决map标记的方法，由于题中需要输出的是小于nums[i]的数的个数
所以我们从后往前遍历fre数组。
定义一个num = nums.length来记录次数，由于从后往前遍历，代表我们先遍历到的数就是nums中最大的数，这时我们将num -= (fre[i] + 1)
因为我们之前对fre初始化为-1，所以需要+1得到对应数字真实出现的次数，之后将其加入到map中。
最后我们建立一个输出数组a,随后扫描nums,a[i] =  map.get(nums[i])。
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int []fre = new int[101];
        Arrays.fill(fre,-1);
        for(int x:nums){
            fre[x]++;
        }
        Map<Integer,Integer> map = new HashMap();
        int num = nums.length;
        for(int i = 100;i>=0;i--){
            if(fre[i]!=-1){
                num -= (fre[i]+1);
                map.put(i,num);
            }
        }
        int []a = new int[nums.length];
        for(int i = 0;i<a.length;i++){
            a[i] = map.get(nums[i]);
        }
        return a;
    }
}