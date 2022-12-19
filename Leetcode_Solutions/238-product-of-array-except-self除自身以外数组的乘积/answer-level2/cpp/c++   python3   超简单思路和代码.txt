其实这道题我首先想到的就是全乘起来然后用除法，0的情况写一个if语句就可以解决，结果一看题目描述的说明不让用除法emmmmmm
所以只能用左右的乘积相乘的思路了。
# 思路
`除本身外其余各元素的乘积 = 左侧所有的乘积  *  右侧所有的乘积`
这个就不用解释了吧，超级好理解，就是可能不太容易想到，所以我愿称之为脑筋急转弯......

那么具体该怎么实现呢？
可以定义两个数组**left**,**right**.
left[i]存储第i个位置左边所有的乘积， right[i]存储第i个位置右边所有的乘积。
left[0]和right[n-1]可以定义为1,因为第0个位置的最左边和最后一个位置的最右边没有元素了。
# 举一个例子瞬间明白
nums[] = {1,2,3,4}  
**从动态规划的角度考虑**   （建议手动模拟一下）
计算left:
从左到右遍历，i==0时, **left[i] = 1**;      i>0时, **left[i] = left[i-1] * nums[i-1]**
计算right:
从右到左遍历, i==n-1时， **right[i] = 1**;      i<n-1时,  **right[i] = right[i+1] * nums[i+1]**
最后按照上面思路的公式，将**left**和**right**里的元素依次相乘，即可
# 代码
```cpp []
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        //左侧数组
        left[0] = 1;    
        for(int i=1; i<n; i++)
            left[i] = left[i-1] * nums[i-1];
        //右侧数组
        right[n-1] = 1;
        for(int i=n-2; i>=0; i--) {
            right[i] = right[i+1] * nums[i+1];
        }
        //把左侧数组作为结果数组
        for(int i=0; i<n; i++) 
            left[i] *= right[i];
        return left;
    }
};
```
```python3 []
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        #左侧数组
        left = [1]*n
        for i in range(1, n):
            left[i] = left[i-1] * nums[i-1]
        #右侧数组
        right = [1]*n
        for i in range(n-2, -1, -1) :
            right[i] = right[i+1] * nums[i+1]
        #把左侧数组作为结果数组
        for i in range(0, n):
            left[i] *= right[i]
        return left
```
*时间复杂度O(n)
空间复杂度O(n)*

# 进阶
根据题目进阶的要求，我们多了一个right数组，因此空间复杂度上升为O(n)，如果把right数组去掉，或者换成一个变量，那么按照题目所述，空间复杂度就变为O(1)了，岂不美哉？
仔细观察上面代码，发现这是可以做到的。
*计算右侧数组和计算结果数组这两步（也就是两个循环）， 可以合并在一起。*
*有人说，计算右侧数组是从右向左遍历，计算结果数组是从左向右遍历，怎么可能合并在一起呢？*
*仔细想想，计算结果数组，从左向右遍历，和从右向左遍历，其实是完全一样的，对结果没有丝毫影响！*
所以我们可以把这两步合成一步，也就是算出right[i]后，接着做left[i] *= right[i]的运算，直接得到结果。
# 代码
```cpp []
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        left[0] = 1;
        //左侧数组
        for(int i=1; i<n; i++)
            left[i] = left[i-1] * nums[i-1];
        //右侧right,两步合并为一步，从右向左遍历
        int right = 1;
        for(int i=n-1; i>=0; i--) {
            left[i] *= right;
            right *= nums[i];
        }
        return left;
    }
};
```
```python3 []
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        #左侧数组
        left = [1]*n
        for i in range(1, n):
            left[i] = left[i-1] * nums[i-1]
        #右侧right，两步合并为一步，从右向左遍历
        right = 1
        for i in range(n-1, -1, -1) :
            left[i] *= right 
            right *= nums[i]
        return left
```
*时间复杂度O(n)
空间复杂度O(1)*


