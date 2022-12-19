### 解题思路
暴搜+位运算解法：搜索所有组合需要O(n*2^n)的时间，判断字符是否出现过使用位运算需要O(L)的时间，
故总的时间复杂度为O(L*n*2^n)
s表示当前组合比如arr=["un","iq","ue"]则s=101(二进制表示)表示出现"un"和"ue"的组合。v用来判
断当前组合是否合法。若合法，则按可行解的长度跟新答案。
v&-v表示取其二进制表示中的从右往左的第一个1。

### 代码

```cpp
class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size(),res=0;
        for(int s=1;s<(1<<n);s++){ //所有状态
            int v=0;
            bool flag = 1;
            for(int i=0;i<n;i++){
                if((s>>i)&1){  
                    for(char c : arr[i]){
                        if((v>>(c - 'a')) & 1){
                            flag = 0;
                            break;
                        }
                        v += 1<<(c - 'a');
                    }
                }
            }
            if(flag){
                int t=0;
                for(;v;v-=v&-v)t++;
                res = max(res,t);
            }
        }
        return res;
    }
};
```