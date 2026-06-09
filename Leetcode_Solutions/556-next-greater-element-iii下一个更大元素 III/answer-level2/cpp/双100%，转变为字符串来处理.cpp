### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int le = s.size();
        int i = le-1;
        while(i>0 &&s[i-1]>=s[i]) //从后往前寻找
        {
            i--;
        }
        if(i == 0)
        {
            return -1;//如果数字是非增的，说明最大了
        }
        reverse(s.begin()+i,s.end());
        int left = i;
        int right = le-1;
        while(left<=right)//找到以一个大于s[i-1]的数
        {
            int mid = left + (right-left)/2;
            if(s[mid]<=s[i-1])
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        swap(s[i-1],s[left]);
        long res = stol(s);
        return res>INT_MAX?-1:res;
    }
};
```