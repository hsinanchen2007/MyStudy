## 方法一：根据题意的常规做法
- 使用二分法模板3

![模板3.png](https://pic.leetcode-cn.com/464321d2d3685d7609479465e1b054bcd4f60e06faaa90b4ffdbc6db2b36ff8c-%E6%A8%A1%E6%9D%BF3.png)
- 先找到最靠近x得两个数
- 求与x得差，对比，小的放入数组
- 处理边界方法， 若l超出左边界，将索引l的值移到最右边，接下来会把索引r的值依次放入ans数组。
- 最后排序
```cpp
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans(k);
        int l = 0, r = arr.size() - 1;
        int i = 0;
        while(l + 1 < r){ //找到最靠近x的两个数
            int mid = l + (r - l) / 2;
            if(arr[mid] <= x) l = mid;
            else r = mid;
        }
        while(i < k){ // 两个数分别与x 相减，对比两个差，放进数组。
            int subl,subr;
            if(l < r){ // 用来处理超出边界的情况
                subl = x - arr[l];
                subr = arr[r] - x;
            }
            else{
                subl = arr[l] - x;
                subr = x - arr[r];
            }
            if(subl - subr <= 0){
                ans[i] = arr[l];
                -- l;
                if(l == -1) l = arr.size() -1;
            }
            else{
                ans[i] = arr[r];
                ++ r;
                if(r == arr.size()) r = 0;
            }
            ++ i;
        }
        sort(ans.begin(),ans.end()); //排序
        return ans;
    }
};
```

## 方法二：来自评论区的大佬。二分法加滑动窗口
- 题目所给的数组是排序好的数组，我们要的答案就是数组内长度为k的一段连续的部分数组。
- 寻找左端点，当l == r时，出循环，此时l是目标数组的第一个端点，只需将该端点及该端点右边的k个值（包括第一个端点）返回即可
```cpp
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(x - arr[mid] > arr[mid + k] - x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return vector<int>(arr.begin() + left, arr.begin() + k + left); // 返回左边界到距离左边界k个值得一段数组
    }
};
```

