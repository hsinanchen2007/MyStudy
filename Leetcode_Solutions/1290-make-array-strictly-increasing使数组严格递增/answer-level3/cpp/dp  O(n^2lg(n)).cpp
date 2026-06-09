国际版上看到的解法,虽然不是最快的解法，但我认为是非常容易理解的解法：
[国际版解法参考](https://leetcode.com/problems/make-array-strictly-increasing/discuss/377680/Simple-Java-DP-Solution-%2B-TreeSet-with-Explanation-beats-100)

1. ```dp[i][j]```表示，将数组```arr1```的前```j```个元素通过```i```次替换后变为严格递增序列时，序列中最后一个元素的最小值,第```j```个元素的最小值。
2. 求```dp[i][j+1]```时，递推如下：当```arr[j+1] > dp[i][j] ```时，即前```j```个元素已经严格递增，这时```arr[j+1]```大于严格递增序列的最大值时，```arr[j+1]```,直接加在序列末尾，即这时的序列应该严格递增，且此时的序列进行替换的次数仍然为```i```次。
3. 另一种选择，或者选择将```arr[j+1]```进行元素替换，此时，我们应当在数组```arr2```中找到第一个比```dp[i-1][j]```大的数，```dp[i-1][j]```即前```j```个元素进行```i-1```替换后的序列的最大值，我们使用二分查找即可在```O(lgn)```时间复杂度内找到该值,此时我们仍然保证前```j+1```个元素进行了```i```次替换。
4. 递推公式如下: 
    $$ dp[i][j+1] = min\left\{
    \begin{array}{rcl}
    arr1[j+1] &  & {if \: arr1[j+1] > dp[i][j]} \\ 
              &  &   \\
    arr2.upperbound(dp[i-1][j]) &   &{if \: arr2.upperbound(dp[i-1][j]) \: \: exisit} \\
    \end{array} \right.$$

5. 我们只需要找到最小转换次数的```i```，能够使得满足前```n```个元素成为严格递增序列即可。

```c++ []
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        std::vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX));
        
        /*intial*/
        dp[0][0] = -1;
        sort(arr2.begin(),arr2.end());
        
        for(int i = 1; i <= n; ++i){
            for(int j = 0;j <= i; ++j){
                if(arr1[i-1] > dp[j][i-1]){
                    dp[j][i] = arr1[i-1];
                }
                
                if(j > 0){
                    auto it = upper_bound(arr2.begin(),arr2.end(),dp[j-1][i-1]);
                    if(it != arr2.end()){
                        dp[j][i] = min(dp[j][i],*it);
                    }
                }
                if( i == n && dp[j][i] != INT_MAX){
                    return j;
                }
            }
        }
        
        return -1;
    }
};
```
```python []
class Solution:
    def makeArrayIncreasing(self, arr1: List[int], arr2: List[int]) -> int:
        n = len(arr1)
        maxV = 1000000001
        dp = [[maxV for i in range(n+1)] for _ in range(n+1)]
        
        #initial
        arr2.sort()
        dp[0][0] = -1
        
        for i in range(1,n+1):
            for j in range(0,i+1):
                if arr1[i-1] > dp[j][i-1]:
                    dp[j][i] = arr1[i-1]
                    
                if j > 0:
                    loc = bisect.bisect_right(arr2,dp[j-1][i-1])
                    if loc < len(arr2):
                        dp[j][i] = min(dp[j][i],arr2[loc])
                        
                if i == n and dp[j][i] != maxV:
                    return j
            
        return -1
```
```java []
class Solution {
    public int makeArrayIncreasing(int[] arr1, int[] arr2) {
        if (arr1 == null || arr1.length == 0) return -1;
        if (arr1.length == 1) return 0;
        TreeSet<Integer> ts = new TreeSet<>();
        if (arr2 != null) {
            for (int i = 0; i < arr2.length; i++) ts.add(arr2[i]);
        }
        
        int[][] dp = new int[arr1.length + 1][arr1.length + 1];
        for (int i = 0; i < dp.length; i++) Arrays.fill(dp[i], Integer.MAX_VALUE);
        dp[0][0] = Integer.MIN_VALUE;
        
        for (int j = 1; j < dp.length; j++) {
            for (int i = 0; i <= j; i++) {
                if (arr1[j - 1] > dp[i][j - 1]) {
                    dp[i][j] = arr1[j - 1];
                }
                if (i > 0 && ts.higher(dp[i - 1][j - 1]) != null) {
                    dp[i][j] = Math.min(dp[i][j], ts.higher(dp[i - 1][j - 1]));
                }
                if (j == dp.length - 1 && dp[i][j] != Integer.MAX_VALUE) return i; 
            } 
        }
        return -1;
    }
}
```

