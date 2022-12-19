### 解题思路
快乐贪心！
是我们熟悉的双指针没错了！
思路理解清楚，实现起来就不难：
    1、本解法中，我们维护的是头尾两指针中间的连续区间
    2、头尾两指针交替移动，如果头指针指向的数值小于等于尾指针，则移动头指针，否则移动尾指针
    3、头尾指针每次移动，都是向后移动到第一个“值”超过“当前值”的那个位置上
目前有对于第三步的证明：
    如果下一个移动到的位置上的“值”小于等于“当前值”，那么与另一指针围合的区域就会小于当前两指针围合的区域
但对于最为重要的第二部，目前还没有比较好的说明方法，只是在计算和实践中检验证明该方法可行。
如果有人能够论述证明它的准确性，欢迎补充。

![image.png](https://pic.leetcode-cn.com/ecb6bd06ea4511d381fbf950b1868132b09bb252cc12f7dc143748e039ec2fdc-image.png)

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        // st 为头指针，en 为尾指针
        int st = 0, en = height.size() - 1;
        // stlas 与 enlas 分别存储 st 与 en 指向的“当前值”
        int stlas, enlas;
        // ans 初始化
        int ans = min(height[st], height[en]) * (en - st);
        while(st < en)
        {
            // 外层 while 控制两指针交替移动
            while(height[st] <= height[en] && st < en)
            {
                stlas = height[st];
                st ++;
                // 内层 while 控制头指针寻找下一个 “值” 大于 “当前值 stlas” 的位置
                while(height[st] <= stlas && st < en) st ++;
                ans = max(ans, min(height[st], height[en]) * (en - st));
            }
            while(height[st] >= height[en] && st < en)
            {
                enlas = height[en];
                en --;
                // 内层 while 控制尾指针寻找下一个 “值” 大于 “当前值 enlas” 的位置
                while(height[en] <= enlas && st < en) en --;
                ans = max(ans, min(height[st], height[en]) * (en - st));
            }
        }
        return ans;
    }
};
```