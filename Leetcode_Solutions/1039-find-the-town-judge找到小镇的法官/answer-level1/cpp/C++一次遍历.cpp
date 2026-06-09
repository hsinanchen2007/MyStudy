### 解题思路
一次遍历，给分数。
信任其他人就给这个人减1分；
被别人信任就给这个人加1分；
得分为N-1的就是法官，否则不是。

### 代码

```cpp
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int arr[N+1] = {0};//记录分数，被信任加1，否则减1
        for(int i=0; i< trust.size(); ++i){
            --arr[trust[i][0]];
            ++arr[trust[i][1]];
        }
        for (int i=1;i<=N;++i){
            if(arr[i]==N-1) return i;//没有考虑到被N-1个人信任，但也不能信任任何人这一条件？？？
        }
        return -1;
    }
};
```