### 解题思路
类似三数之和, 构造双指针移动区间, 判断两边之和是否大于第三边

### 代码

```c++ []
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int cnt = 0;
        int N = nums.size();
        if(N < 3)
            return cnt;
        sort(nums.begin(), nums.end());
        for(int i=2; i<N; ++i){
            int j = 0;
            int k = i-1;
            while(j < k){
                if(nums[j]+nums[k] > nums[i]){
                    cnt += (k-j);
                    k--;
                }
                else if(nums[j]+nums[k] <= nums[i]){
                    ++j;
                }
            }
        }

        return cnt;
    }
};
```
```java []
class Solution {
    public int triangleNumber(int[] nums) {
        int N = nums.length;
        int cnt = 0;
        if(N < 3)
            return cnt;

        Arrays.sort(nums);
        for(int i=2; i<N; ++i){
            int j = 0;
            int k = i-1;
            while(j<k){
                if(nums[j]+nums[k] > nums[i]){
                    cnt += k-j;
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return cnt;
    }
}
```
```python []
class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        cnt, N = 0, len(nums)
        if N < 3:
            return cnt

        nums.sort(key = lambda x: x)

        for i in range(2, N):
            j, k = 0, i-1
            while j<k:
                if nums[k]+nums[j] > nums[i]:
                    cnt += (k-j)
                    k-=1
                else:
                    j+=1
        return cnt
```