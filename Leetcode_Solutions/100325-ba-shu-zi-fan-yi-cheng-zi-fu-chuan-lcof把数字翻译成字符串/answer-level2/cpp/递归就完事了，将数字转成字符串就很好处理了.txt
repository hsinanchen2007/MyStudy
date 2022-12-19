![image.png](https://pic.leetcode-cn.com/379fd87e11f283a50740c4e8505db28047d586ee6786cf73b268538febc366bc-image.png) 

```c++
class Solution {
public:
    int res,n;
    int translateNum(int nums) {
        string num = to_string(nums);
        n = num.size();
        dfs(num,0);
        return res;
    }
    void dfs(string &s, int pos){
        if(pos == n){
            res++;
            return;
        }
        int a = s[pos] - '0';
        dfs(s, pos+1);  //处理一位数
        if(pos<n-1){    
            int b = 10 * a + s[pos + 1] - '0';
            if(10<=b && b<=25)dfs(s, pos+2);    //能组成两位数
        }
    }
};
```
下面的代码打印了了所有方案
```c++
class Solution {
public:
    int res,n;
    unordered_map<int,char>hash;
    int translateNum(int nums) {
        string num = to_string(nums);
        n = num.size();
        for(int i=0;i<26;i++)hash[i] = 'a' + i;
        dfs(num,"",0);
        return res;
    }
    void dfs(string &s,string current ,int pos){
        if(pos == n){
            cout<<current<<endl;
            res++;
            return;
        }
        int a = s[pos] - '0';
        dfs(s,current+hash[a],pos+1);
        if(pos<n-1){
            int b = 10 * a + s[pos + 1] - '0';
            if(10<=b && b<=25)dfs(s,current + hash[b], pos+2);
        }
    }
};
```