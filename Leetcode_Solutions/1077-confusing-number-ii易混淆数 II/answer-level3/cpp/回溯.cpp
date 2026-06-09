### 解题思路

验证混淆数的函数一定要高效，不然在 N = 10E9 这个用例会超时。

### 代码

```cpp
class Solution {
private:
    unordered_map<int, int> dict = {{0, 0}, {1,1}, {6,9}, {8,8}, {9,6}};
    int res = 0;
    int up;
public:
    int confusingNumberII(int N) {
        int len = getWidth(N);
        up = N;
        dfs(0, 0, len);
        return res;
    }

    void dfs(long cur, int i, int n) {
        if(i > n || cur > up) {
            // 只在 i > n 的时候判断，否则还要去重
            if(cur > 0 && cur <=up && isValid(cur)) {
                res++;
            }
            return;
        }

        for(auto& p: dict) {
            dfs(cur*10+p.first, i+1, n);
        }
    }

    int getWidth(int N) {
        int l = 0;
        while(N) {
            N /= 10;
            l++;
        }
        return l;
    }

    bool isValid(int N) {
        int ans = 0;
        int t = N;
        
        if(N == 0){
            return false;
        }
        
        while(t){
            int carry = t % 10;
            if(dict.count(carry) == 0){
                return false;
            }else{
                ans = ans*10 + dict[carry];
            }
            t /= 10;
        }
    
        return ans != N;
    }
};
```