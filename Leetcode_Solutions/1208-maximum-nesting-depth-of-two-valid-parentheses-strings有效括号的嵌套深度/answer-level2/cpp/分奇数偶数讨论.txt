### 解题思路
此处撰写解题思路
这个题目看的我一头雾水，一脸懵逼，哈哈，看懂以后分析一下：
其实就是要让AB的括号深度差值最短，如何实现深度差值最短呢：
1-让连续的括号分开
2-让括号尽均匀放在AB（防止很多括号时，一个是空，另一个是1[（）（）（）（）]   这种情况）
那么就是分“（”和“）”讨论，奇数放入A，偶数放入B，即可同时解决上述问题~
### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        //vector<char> A,B;
        vector<int> ans;
        int flag1=0,flag2=0;//连续括号标记
        if(seq.size()==0) return ans;
        for(int i=0;i<seq.size();i++){
            if(flag1%2==0&&seq[i]=='('){
                ans.push_back(0);
                flag1+=1;
            }
            else if(flag1%2!=0&&seq[i]=='('){
                ans.push_back(1);
                flag1+=1;
            }
            else if(flag2%2==0&&seq[i]==')'){
                ans.push_back(0);
                flag2+=1;
            }else{
                ans.push_back(1);
                flag2+=1;
            }
        }
        return ans;
    }
};
```