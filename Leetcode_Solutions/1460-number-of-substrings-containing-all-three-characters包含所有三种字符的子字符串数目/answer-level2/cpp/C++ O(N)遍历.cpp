### 解题思路
分别使用`next_a[N], next_b[N], next_c[N]`记录当前位置下一个`a/b/c`的位置；
则以当前位置为起点的所有同时包含`abc`的子串的数目为`N - max(next_a[i], next_b[i], next_c[i])`

### 代码

```cpp
class Solution {
public:
    int numberOfSubstrings(string s) {
        int N = s.size();
        vector<int> next_a(N, 0), next_b(N, 0), next_c(N, 0);
        int last_a = N, last_b = N, last_c = N;
        int cnt = N-1;
        int counter = 0;
        while(cnt >= 0){
            if(s[cnt] == 'a') last_a = cnt;
            else if(s[cnt] == 'b') last_b = cnt;
            else last_c = cnt;
            next_a[cnt] = last_a;
            next_b[cnt] = last_b;
            next_c[cnt] = last_c;
            cnt--;
        }
        for(int i = 0; i < N; i++){
            if(next_a[i] == N || next_b[i] == N || next_c[i] == N) break;
            int remote_index = max(next_a[i], max(next_b[i], next_c[i]));
            counter += (N - remote_index);
        }
        return counter;
    }
};
```