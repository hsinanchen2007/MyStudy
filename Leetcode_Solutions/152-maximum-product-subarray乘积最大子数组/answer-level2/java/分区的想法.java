提交结果：
执行用时 :2 ms, 在所有 Java 提交中击败了99.03% 的用户
内存消耗 :38.6 MB, 在所有 Java 提交中击败了8.14%的用户

思路：所谓一遇zero误终身，0是铁定不能参与乘积的，即子序列不能包括0，所以我考虑通过0来将原数组分成若干段，比如数组中存在三个0，那么应该是分成四段了，我感觉不好用代码实现，所以假装-1和length位置也存在0，这样的话就可以用两个相邻的0来围成一个区间了。把我们的目光聚焦在一个区间内，在一个特定的区间里面，肯定是没有0了，但是存在负数这个东西，负数能使我们从天堂到地狱，也可以让我们从地狱重回天堂，最终的结果取决于负数的个数，如果是偶数个负数，最终负负得正了，于我们的结果没有影响，那么这个区间最大乘积就是所有元素之积，如果有奇数个，我们必须摒弃第一个或者最后一个负数，当然同时被抛弃的还有第一个负数之前的所有正数或者最后一个负数后面所有的正数。

代码：
```
public int maxProduct(int[] nums) {
        if (nums.length==1)return nums[0];//除非只有一个元素，否则最大乘积一定大于等于0
        int max=0;
        List<Integer> siteOfZero=new ArrayList<>();//乘积肯定不能有0参与，
        // 所以用0把原数组划分若干个区间，假装在-1和length出也有0 ，用于形成区间
        siteOfZero.add(-1);
        for (int i = 0; i < nums.length; i++) {
            if (nums[i]==0)siteOfZero.add(i);
        }
        siteOfZero.add(nums.length);
        for (int i = 0; i < siteOfZero.size() - 1; i++) {
            int res=help1(nums,siteOfZero.get(i)+1,siteOfZero.get(i+1)-1);
            if (res>max)max=res;
        }
        return max;
    }
    //计算每个区间最大的乘积
    private int help1(int[] nums, int begin, int end) {
        if (end<begin)return -1;
        else if (end==begin)return nums[begin];
        int first=-1;int last=-1;int count=0;//记录第一个负数，最后一个负数出现位置和负数个数
        for (int i = begin; i <=end ; i++) {
            if (nums[i]<0){
                if (first==-1)first=i;
                last=i;
                count++;
            }
        }
        if (count%2==0)
            return help2(nums,begin,end);
        else return Math.max(help2(nums,begin,last-1),help2(nums,first+1,end));
    }
    //计算子序列乘积的函数
    private int help2(int[] nums, int begin, int end) {
        int result=1;
        for (int i = begin; i <=end; i++) {
            result*=nums[i];
        }
        return result;
    }
```
