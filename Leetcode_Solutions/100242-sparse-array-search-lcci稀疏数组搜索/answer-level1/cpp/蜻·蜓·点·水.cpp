### 绩效
执行用时 :4 ms, 在所有 C++ 提交中击败了99.69%的用户
内存消耗 :12.9 MB, 在所有 C++ 提交中击败了100.00%的用户

### 解题思路
二分法，指针`mid`就是那只蜻蜓，连续的空字符串就是水，蜻蜓一点水，这一滩水就都不考虑了。
![蜻蜓点水图解.png](https://pic.leetcode-cn.com/62d7831cb511e358ad309bd61b08430386b921d11493dacbdd7431163c942251-%E8%9C%BB%E8%9C%932.png)
点完水之后，和这摊水右边界的那株水草比较一下，以此决定留左边这半还是留右边那半。

### 代码

```cpp
class Solution {
public:
    int findString(vector<string>& v, string s) {
        int len = v.size();
        if(!len)
            return -1;
        int left = 0;
        while(left<len && v[left].size()==0)
            left++;
        int right = len-1;
        while(right>=0 && v[right].size()==0)
            right--;
        while(true) {
            if(left>right) // 为了continue能走判断所以扔到这里
                break;
            int mid = (left+right)/2;
            int mid_r = mid;
            int mid_l = mid;
            while(mid_r<=right && v[mid_r].size()==0)
                mid_r++;
            while(mid_l>=left && v[mid_l].size()==0)
                mid_l--;
            if(mid_r<=right) {
                string& val = v[mid_r];
                if(val<s) {
                    left = mid_r+1;
                    continue;
                } else if(val>s) {
                    right = min(mid_l, mid_r-1);
                    continue;
                } else {
                    return mid_r;
                }
            }
        }
        return -1;
    }
};
```
还可以更快，程序中寻找`mid_l`的过程可以优化到第28行的`else-if`里，但是为了对称美就不优化了。牺牲这点性能，换取艺术。