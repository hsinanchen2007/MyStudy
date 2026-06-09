先按照暴力破解方法，写一下过程，再翻译成dfs就好了
```
public class TargetSum {
    public static void main(String[] args) {
        int[] arr={1, 1, 1, 1, 1};
        System.out.println(findTargetSumWays(arr,3));
    }
    private static int cnt,n;
    public static int findTargetSumWays(int[] nums, int S) {
        if(nums==null || nums.length==0)
            return -1;
        n=nums.length;
        dfs(nums,0,S,0);
        return cnt;
    }
    private static void dfs(int[] arr, int sum, int target, int index){
        if(index>n)
            return;
        if(target==sum && index==n){
            cnt++;
            return;
        }
        if (index<n){
            dfs(arr, sum + arr[index], target, index + 1);
            dfs(arr, sum - arr[index], target, index + 1);
        }else return;
    }
}
时间复杂度很高，试试能不能做优化
```
![image.png](https://pic.leetcode-cn.com/0745679721f9c6b755eb2233a423b60de6eb7996c293be97ed1c27b25e7d3d93-image.png)


做了剪枝优化竟然变得更慢了，搞不懂了
![image.png](https://pic.leetcode-cn.com/ecd821ed0668647206f881b6c10d930878d7b56fefd1b4f9904d53230fbcdf91-image.png)
```
public class TargetSum {
    public static void main(String[] args) {
        int[] arr={1, 1, 1, 1, 1};
        System.out.println(findTargetSumWays(arr,3));
    }
    private static int cnt,n,arrSum=0;//arrSum做剪枝的条件用
    public static int findTargetSumWays(int[] nums, int S) {
        if(nums==null || nums.length==0)
            return -1;
        n=nums.length;
        for (int num:nums)
            arrSum+=num;
        dfs(nums,0,S,0);
        return cnt;
    }
    private static void dfs(int[] arr, int sum, int target, int index){
        if(index>n)
            return;
        if(target==sum && index==n){
            cnt++;
            return;
        }
        if (sum+arrSum<0 || sum-arrSum>0)//剪枝：如果当前的sum非常小，
            // 就算加上数组中全部数的和还是小于0，则剔除；如果当前的sum非常大同理
            return;
        if (index<n){
            dfs(arr, sum + arr[index], target, index + 1);
            dfs(arr, sum - arr[index], target, index + 1);
        }else return;
    }
}

```
