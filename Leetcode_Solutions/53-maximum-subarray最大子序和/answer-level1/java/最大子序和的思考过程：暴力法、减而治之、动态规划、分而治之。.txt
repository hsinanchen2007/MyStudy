### 1 暴力法

每个子序列都有一个start和end，（start <= end），共有 (n^2)/2个子序列，如果能在O(1)的情形下计算一个子序列的和，可以在O(n^2)完成暴力破解。其实，已知nums[a,b]的和,求nums[a,b+1]的和，只需要加上nums[b+1]即可。

按如下方式填表即可。

![image-20200111221913168.png](https://pic.leetcode-cn.com/eddfb9aababdebeaeb93782c3ff5f4d8d46d40ba02038ffba9a8450c0c9e8d26-image-20200111221913168.png)

``` Java
class Solution {
    public int maxSubArray(int[] nums) {
        int start = 0,end = 0;
        int max = Integer.MIN_VALUE;
        int temp;
        int length = nums.length;
        for(start = 0; start < length; start++){
            temp = 0;
            for(end = start; end < length; end++){
                temp += nums[end];
                if(temp >= max){
                    max = temp;
                }
            }
        }
        return max;
    }
}
```

* 时间复杂度 `O(n^2)`
* 空间复杂度`O(1)` 只需要temp变量（保存上一个值）和max变量（保存最大值）即可
* 执行用时`68ms 6.99%`

### 2 递归-减而治之（按照自顶而下，递归的方式去思考）

**思考**：知道nums[0,n-1]的最大子序和为max1，如何求nums[0,n]的最大子序和max2呢？如果能以O(1)解决这个问题，那么原问题的规模就可以缩减一个元素。

![image-20200111223444635.png](https://pic.leetcode-cn.com/8fc1be8bbb2bfbc1e04a06cc5553c487bec3b629ea7edbeca40ae08915a7ea6b-image-20200111223444635.png)

max2可能就是max1；也可能由于nums[n] （图中的4）的加入，导致以nums[n]结束的某个子序列的值大于了max1。

即，我们需要比较max1和以nums[n]结束的最大子序列和。

**思考**：以nums[n]结束的最大子序列和怎么求呢？

以nums[n]结束的最大子序列和 = nums[n] +  nums[0,n-1]能对nums[n]提供的**最大贡献值**。

**思考**：“最大贡献值”容不容易求呢？

“nums[0,n-1]能对nums[n]提供的**最大贡献值**”能不能轻松求出来，我们从一个**递归基**nums[0,0]看起。

* 对于{-2}来说，显然它能对下一个序列的贡献为-2，既然是负值，干脆不要，即最大贡献值为0；

* 对于{-2,1}来说，{-2}的最大贡献值为0，“0+1”意味着它能提供1的贡献值给下一个序列。

* 对于{-2,1,-3}来说，{-2,1}的最大贡献值为1，“1+(-3)”意味着它能提供-2的贡献值，同样的，不需要这个负贡献值，最大贡献值为0
* ......

显然，“最大贡献值”非常容易求！

所以，我们可以写递归函数了，参数是数组nums[0,n-1]，返回值除了最大子序和max之外，还需要有**最大贡献值**。代码如下，其中，递归函数getMaxandPre的参数int[] result用于保存max和最大贡献值。

``` java
class Solution {
    public int maxSubArray(int[] nums) {
        int[] result = new int[2];
        getMaxandPre(nums,nums.length,result);
        return result[0];
    }
    private void getMaxandPre(int[] nums,int length,int[] result){
        if(length == 1){
            result[0] = nums[0];
            if(nums[0]<=0){
                result[1] = 0;
            }else{
                result[1] = nums[0];
            }
        }else{
            int[] resulttemp = new int[2];
            getMaxandPre(nums,length-1,resulttemp);
            if(resulttemp[1] + nums[length-1] >= resulttemp[0]){
                result[0] = resulttemp[1] + nums[length-1];
            }else{
                result[0] = resulttemp[0];
            }
            if(resulttemp[1]+nums[length-1]<=0){
                result[1] = 0;
            }else {
                result[1] = resulttemp[1]+nums[length-1];
            }
        }
    }
}


```

* 执行用时 `2ms, 26.75%`

### 3 迭代-动态规划（继续2.2，自底而上思考）

由2.2可知，只需在DP表中保存每一个n号元素对应的nums[0,n]的max值和**最大贡献值**即可。

由于每次计算DP[n]只需要知道DP[n-1]，因此没有必要真的使用一个DP数组，只需两个变量分别保存上一个max和最大贡献值。代码如下。

``` Java
class Solution {
    public int maxSubArray(int[] nums) {
        int max = Integer.MIN_VALUE;
        int i = 0,j = 0;
        int addtionalPre = 0;
        for(i = 0;i < nums.length; i++){
            if(addtionalPre <= 0){
                addtionalPre = nums[i];
            }else{
                addtionalPre = addtionalPre + nums[i];
            }
            if(addtionalPre > max){
                max = addtionalPre;
            }
        }
        return max;
    }
}
```

* 时间复杂度 `O(n)`
* 空间复杂度`O(1)`
* 执行用时 `1ms, 99.98%`

### 4 递归-分而治之（自顶而下，划分子问题，分情况讨论）

将序列如下图从中间一分为二。

![image-20200111232340735.png](https://pic.leetcode-cn.com/32c197188668b1d6da6f2dff05c9ceaa9f95d44b43e894a8efc55dbdbfcbbabb-image-20200111232340735.png)

则最大子序列要么在序列1中（max1），要么在序列2中（max2），要么包含mid。

包含mid的最大子序列如何求呢？看看mid左边（序列1）的最大贡献，再看看mid右边（序列2）的最大贡献，求和即可。

``` Java
class Solution { 
    public int maxSubArray(int[] nums) {
        return getMax(nums,0,nums.length-1);
    }
    private int getMax(int[] nums,int start, int end){
        if(end - start == 0){
            return nums[end];
        }else if(end - start == 1){
            int a = nums[start],b = nums[end],c = nums[start]+nums[end];
            return maxthree(a,b,c);
        }else{
            int mid = (start + end) / 2;
            return maxthree(getMax(nums,start,mid-1),getMaxMid(nums,start,end,mid),getMax(nums,mid+1,end));
        }
    }
    private int getMaxMid(int[] nums,int start,int end,int mid){
        int i = 0,max1 = 0,max2 = 0;
        int temp = 0;
        for(i=mid-1;i>=start;i--){
            temp += nums[i];
            if(temp >= max1){
                max1 = temp;
            }
        }
        temp = 0;
        for(i=mid+1;i<=end;i++){
            temp += nums[i];
            if(temp >= max2){
                max2 = temp;
            }
        }
        return  max1+max2+nums[mid];
    }
    private int maxthree(int a,int b,int c){
        if(a <= b){
            a = b;
        }
        if(a<=c){
            return c;
        }else {
            return a;
        }
    }
}
```

* 执行用时`2ms, 26.75%`