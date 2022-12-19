### 解题思路
桶排序: 时间复杂度$O(N)$, 空间复杂度$K*O(1)$
三路快排：时间复杂度$O(N)$, 空间复杂度$O(1)$

### 代码

```java []
class Solution {
    public void sortColors(int[] nums) {
        // 使用三路快排求解
        if(nums.length<=1)
            return;

        // 定位初始指向0段的指针
        int z_index = -1;
        // 定位初始指向2段的指针
        int t_index = nums.length;
        
        for(int i=0; i<t_index;){
            if(nums[i]==1)
                ++i;
            else if(nums[i]==2)
                swap(nums, i, --t_index);
            else{
                assert nums[i] == 0;
                swap(nums, i, ++z_index);
                ++i;
            }
        }
    }

    private void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp; 
    }
}
```
```python []
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # 使用三路快排实现
        if len(nums)<= 1:
            return

        z_index = -1
        t_index = len(nums)
        i = 0
        while i<t_index:
            if nums[i] == 1:
                i+=1
            elif nums[i] == 2:
                t_index-=1
                nums[i], nums[t_index] = nums[t_index], nums[i]
            else:
                assert nums[i] == 0, 'Error Number'
                z_index+=1
                nums[i], nums[z_index] = nums[z_index], nums[i]
                i+=1

```
```c++ []
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 三路快排
        // 时间复杂度O(n)
        // 空间复杂度O(1)
        if(nums.size()<=1)
            return;

        int z_index = -1;           // nums[0...zero] == 0
        int t_index = nums.size();  // nums[two...n-1] == 2

        for(int i=0; i<t_index;){
            if(nums[i]==1)
                ++i;
            else if(nums[i]==2)
                // 不需要移动i指针
                swap(nums[i], nums[--t_index]);
            else{
                assert(nums[i]==0);
                swap(nums[i++], nums[++z_index]);
            }
        }
    }
};
```
```c++ []
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 三路排序
        int N = nums.size();
        if(N == 0)
            return;
        
        int left = 0, right = N-1, i=0;
        while(i <= right){
            // 如果是0则放置到左侧
            if(nums[i] == 0){
                swap(nums[i++], nums[left++]);
            }
            // 如果是2则放置到右侧
            else if(nums[i] == 2){
                swap(nums[i], nums[right--]);
            }
            // 如果是1则跳过
            else{
                ++i;
            }
        }
    }
};
```
**桶排序**
```c++ []
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 桶排序
        int bucket[3] = {0};
        int index = 0;
        for(auto &num : nums){
            assert(num>=0 && num<=2);
            bucket[num]++;
        }
        for(int i=0; i<bucket[0]; ++i){
            nums[index++] = 0;
        }
        for(int i=0; i<bucket[1]; ++i){
            nums[index++] = 1;
        }
        for(int i=0; i<bucket[2]; ++i){
            nums[index++] = 2;
        }
    }
};
```
```c++ []
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 计数排序
        int N = nums.size();
        int *red = new int[N];
        memset(red, -1, N);
        int *white = new int[N];
        memset(white, -1, N);
        int *blue = new int[N];
        memset(blue, -1, N);

        int i=0, j=0, k=0;
        for(auto &n: nums){
            if(n == 0)
                red[i++] = n;
            else if(n == 1)
                white[j++] = n;
            else
                blue[k++] = n;
        }

        // merge
        int t=0, index =0;
        for(int t=0; t<i; ++t){
            nums[t] = red[t];
        }
        index = i;
        for(int t=0; t<j; ++t){
            nums[index+t] = white[t];
        }
        index = i+j;
        for(int t=0; t<k; ++t){
            nums[index+t] = blue[t];
        }
    }
};
```