### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int countLargestGroup(int n) {
        int a[40] = {0};
        int max = 0;
        for(int i = 1;i<=n;i++){
            int t = sum(i);
            a[t]++;
            max = ++a[t] > max? a[t]:max;
        }
        int ans = 0;
        for(int i=1;i<40;i++){
            if(max == a[i])
                ans++;
        }
        return ans;
    }

    int sum(int n){
        int ans = 0;
        while(n){
            ans += n%10;
            n /= 10;
        }
        return ans;
    }
};
```