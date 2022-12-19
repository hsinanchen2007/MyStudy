1. 子数组和的最大值可以用典型的lcs。
2. 求删除一个元素后的子数组的最大和，可以用递推公式$ans = max(ans,left[i-1] + right[i+1])$
   ```left[i]```表示从左到右以第i个元素结尾的最大子数组和，```right[i]```代表从右到左以第i个元素为结尾的最大子数组和.

```c++ []
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        /*intial*/
        left[0] = arr[0];
        right[n-1] = arr[n-1];
        /*left*/
        ans = max(left[0],right[n-1]);
        for(int i = 1; i < n; ++i){
            left[i] = arr[i] + max(0,left[i-1]);
            ans = max(ans,left[i]);
        }
        /*right*/
        for(int i = n-2; i >= 0; --i){
            right[i] = arr[i] + max(0,right[i+1]);
            ans = max(ans,right[i]);
        }
        for(int i = 1; i <= n-2; ++i){
            ans = max(left[i-1]+right[i+1],ans);
        }
        return ans;
    }
};
```
```python []
class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        n = len(arr)
        left = [arr[0] for _ in range(n)]
        right = [arr[n-1] for _ in range(n)]
        ans = max(left[0],right[n-1])
        
        for i in range(1,n):
            left[i] = arr[i] + max(0,left[i-1])
            right[n-1-i] = arr[n-1-i] + max(0,right[n-i])
            ans = max(ans,left[i])
            ans = max(ans,right[n-1-i])
        
        for i in range(1,n-1):
            ans = max(ans,left[i-1]+right[i+1])
        
        return ans
```
```java []
class Solution {
    public int maximumSum(int[] arr) {
        int n = arr.length;
        int ans = 0;
        int[] left = new int[n];
        int[] right = new int[n];
        
        left[0] = arr[0];
        right[n-1] = arr[n-1];
        ans = Math.max(left[0],right[n-1]);
        
        for(int i = 1; i < n; ++i){
            left[i] = arr[i] + Math.max(0,left[i-1]);
            ans = Math.max(ans,left[i]);
        }
        for(int i = n-2; i >= 0; --i){
            right[i] = arr[i] + Math.max(0,right[i+1]);
            ans = Math.max(ans,right[i]);
        }
        for(int i = 1;i <= n-2; ++i){
            ans = Math.max(ans,left[i-1]+right[i+1]);
        }
        
        return ans;
    }
}
```