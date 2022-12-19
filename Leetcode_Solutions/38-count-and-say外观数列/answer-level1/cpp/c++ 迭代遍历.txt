### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        if(n < 1) return "";
        string pre = "1";
        for(int cnt = 1; cnt < n; cnt++){
            int left = 0, right = 0;
            string temp = "";
            while(right < pre.size()){
                while(right < pre.size() && pre[left] == pre[right]) right++;
                temp.push_back(right-left+'0');
                temp.push_back(pre[left]);
                left = right;
            }
            pre = temp;
        }
        return pre;
    }
};
```