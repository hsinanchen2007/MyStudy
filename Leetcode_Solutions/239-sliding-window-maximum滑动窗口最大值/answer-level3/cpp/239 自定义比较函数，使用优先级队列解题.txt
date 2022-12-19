### 解题思路
优先级队列中存储的是nums的索引值，通过比较nums[i]大小来获取优先级队列，这就需要自定义比较函数  
在定义比较函数cmp的时候，由于函数中比较的部分要求是全局变量，而nums是局部变量，所以通过设置静态变量将局部变量nums转化为全局变量array。  
注意，在leetcode中，使用静态变量要十分小心，每次使用前尽量重新赋值，避免出错，具体原因如下  
  
![image.png](https://pic.leetcode-cn.com/e37972602ea6365eb2de3fcb99d562b191aead0d1d9b1dc3d587d70761976a9a-image.png)



### 代码

```cpp

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> res;
        if (size == 0)
            return res;
        static vector<int> array; //cmp中不能使用局部变量，只能通过这步将nums转换为全局变量。
        array.swap(nums); //leetcode测试规则要求每次使用静态变量都要重新赋值，不然容易得出错误答案。
        struct cmp {
            bool operator () (int a, int b) {
                return array[a] < array[b];
            }
        };
        priority_queue<int, vector<int>, cmp> window;
        for (int i=0; i<k; i++)
            window.push(i);
        res.push_back(array[window.top()]);
        for (int i=k; i<size; i++) {
            window.push(i);
            while (window.top() <= i-k)
                window.pop();
            res.push_back(array[window.top()]);
        }
        return res;
    }
};
```