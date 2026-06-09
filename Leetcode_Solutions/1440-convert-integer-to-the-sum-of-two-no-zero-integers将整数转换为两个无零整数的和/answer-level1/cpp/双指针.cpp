### 解题思路
双指针走一遍都不怕。唯一需要处理的是不含0的数字，很明显地，这样的数字需要过滤掉。此处用到的是转换成字符串，然后利用string的性质查找包含0的数字，并过滤跳过。
![image.png](https://pic.leetcode-cn.com/8581b64462353f92e18307c35b695e3c2467ec0076943a9de74d82a5c8921144-image.png)


### 代码

```cpp
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int left = 1;
        int right = n;
        while(left <= right) {
            auto sum = left + right;
            if(to_string(left).find('0') != string::npos) {
                left++;
                continue;
            }
            if(to_string(right).find('0') != string::npos) {
                right--;
                continue;
            }
            if(sum == n) {
                 return {left, right};
            }
            if(sum < n) {
                left++;
            }
            if(sum > n) {
                right--;
            }
        }
        
        return {};
    }
};
```