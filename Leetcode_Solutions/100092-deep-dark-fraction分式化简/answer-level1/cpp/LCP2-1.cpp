### 解题思路
![{CAB}0J3}\[W}X8{TLW``JR4.png](https://pic.leetcode-cn.com/1a99be9367964c04e24fd80b46431e7d2e3e1202a5905a3bdd52042046bfb5a8-%7BCAB%7D0J3%7D%5BW%7DX8%7BTLW%60%60JR4.png)

### 代码

```cpp
class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        int n = cont.size()-1;
        int FM = cont[n];
        int FZ = 1;
        for(int i = n;i>0;i--)
        {
            FZ += cont[i-1]*FM;
            swap(FM,FZ);
        }
        return {FM,FZ};
    }
};
```