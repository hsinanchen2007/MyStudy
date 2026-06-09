### 解题思路
很明显距离为左右位的较小值+1，然后……想了一会费脑子又费键盘，而且规模不大还是暴力解吧。然后效果其实还不错
![image.png](https://pic.leetcode-cn.com/d94d6edfbfce418296e9e201fe3d81a6aeb8ed768acb8cb52db0f4f3822e55e1-image.png)


### 代码

```cpp
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> ans(S.size(),0),mark;
        int p=0;
        for(int i=0;i<S.size();i++)if(S[i]==C)mark.push_back(i);
        for(int i=0;i<S.size();i++){
            int Min=INT_MAX;
            for(int j=p;j<mark.size();j++){
                int delta=abs(i-mark[j]);
                if(delta>=Min)break;
                else{
                    p=j;
                    Min=delta;
                }
            }
            ans[i]=Min;
        }
        return ans;
    }
};
```
