### 解题思路
![1.png](https://pic.leetcode-cn.com/e5607e49e886a721d4b580461d6b279741edcfbaa32f32d16829e4939774d143-1.png)
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string num = to_string(N);
        int t = num.size();
        for(int i=num.size()-1;i>=1;i--){
            if(num[i]<num[i-1]){
                t=i;
                num[i-1]--;
            }
        }
        while(t<num.size())
            num[t++]='9';
        stringstream s(num);
        int res = 0;
        s>>res;
        return res;
    }
};
```