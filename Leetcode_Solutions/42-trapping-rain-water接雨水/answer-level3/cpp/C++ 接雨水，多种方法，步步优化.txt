### 方法1. 层层遍历

```cpp
class Solution {
public:
	int trap(vector<int>& height) {
        if(height.size() < 3) return 0;
        // 找到最大值
        auto max_iter = max_element(height.begin(), height.end());
        int max_floor = *max_iter;
        int ret = 0;
        // 从第一层开始到最高层max_floor, 逐层遍历
        for(int i = 0; i<max_floor; ++i){
            ret += helper(height, i);
        }
        return ret;
    }
private:
    int helper(vector<int>& height, int floor){
        int ret = 0, left = 0, right = height.size() - 1;
        // 去掉前驱0
        while(left<height.size() && height[left]<=floor){
            left++;
        }
        // 去掉后驱0
        while(right>=0 && height[right]<=floor){
            right--;
        }
        while(left < right){
            if(height[left++]<=floor) ret++;
        }
        return ret;
    }
}; 
```

### 方法2. 按列遍历

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_max(n);
        vector<int> right_max(n);
        // 记录每一个 i 左右的最大值
        for(int i = 1; i<n; ++i){
            left_max[i] = max(left_max[i-1], height[i-1]);
        }
        for(int i = n-2; i>=0; --i){
            right_max[i] = max(right_max[i+1], height[i+1]);
        }
        int ret = 0;
        for(int i = 1; i<n-1; ++i){
            int min_h = min(left_max[i], right_max[i]);
            ret += max(0, min_h - height[i]);
        }
        return ret;
    }
};
```

### 方法3. 方法2的优化, 简化使用空间

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        // 3. 方法3. 方法2的优化, 左右向最高点遍历, 记录出现过的最大值
        auto max_iter = max_element(height.begin(), height.end());
        int ret = 0;
        int tmp = height[0];  // 保存历史最大值
        // 从左向右爬坡
        for(auto it = height.begin(); it!=max_iter; ++it){
            if(tmp <= *it) tmp = *it;
            else ret += (tmp - *it);
        }
        tmp = height.back();
        // 从右向左爬坡
        for(auto it = height.end() - 1; it!=max_iter; --it){
            if(tmp <= *it) tmp = *it;
            else ret += (tmp - *it);
        }
        return ret;
    }
};
```

### 方法四. 方法3的优化 -> 双指针
```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3) return 0;

        int ret = 0, left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        while(left < right){
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);
            if(left_max < right_max){
                ret += left_max - height[left++];
            }else{
                ret += right_max - height[right--];
            }
        }
        return ret;
    }
};
```

### 方法5. 学自甜姨的单调栈
```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3) return 0;

        stack<int> st;
        int ret = 0;
        for(int i = 0; i<height.size(); ++i){
            while(!st.empty() && height[st.top()] < height[i]){
                int cur = st.top(); st.pop();
                // 相同高度的直接出栈
                while(!st.empty() && height[st.top()] == height[cur]){
                    cur = st.top(); st.pop();
                }
                if(!st.empty()){
                    ret += (min(height[st.top()], height[i]) - height[cur]) * (i - st.top() - 1);
                }
            }
            st.push(i);
        }
        return ret;
    }
}; 
```