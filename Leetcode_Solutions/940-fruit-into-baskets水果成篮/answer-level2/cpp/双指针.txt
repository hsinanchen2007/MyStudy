### 解题思路
![image.png](https://pic.leetcode-cn.com/02a57a3ec5589f704aacfcf8976b05030ca6a980878d75ee7c7ffd1d7f4150f2-image.png)
本题可以利用双指针思想解决。left、mid和right，right指向首次出现的第三种“树”，用right-left的作为ans，然后mid记录right的位置，right继续向右寻找新的“树”。

### 代码

```cpp
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int left = 0, mid = 0, right = 0, ans = 0, len = tree.size();
        if(len < 2)  //数组长度小于2，直接输出数组长度
        return len;
        for(; right < len - 1; right ++)  //找到第二种“树”
        if(tree[right] != tree[right + 1])
        break;
        mid = ++ right;
        for(; right < len; right ++)
        {
            if(tree[right] != tree[mid] && tree[right] != tree[left])  //找到第三种“树”
            {
                 ans = max(ans, right - left);  //更新ans
                 mid = right;
                 left = right - 1;
                 while(tree[left] == tree[left - 1])  //易错点：left向前寻找此种树第一次出现的位置
                 left --;
            }
        }
        right --;  //否则数组会越界
        if(left == 0)
        return len;  //表示“树”的种类小于三种
        if(tree[right] == tree[mid] || tree[right] == tree[left]) //如果数组最后一位不是新的“树”，要进行ans的更新，不然会出错
        return max(ans, right - left + 1);
        return ans;
    }
};
```