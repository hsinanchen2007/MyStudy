
![1.PNG](https://pic.leetcode-cn.com/ca3d5911ba79f79a5cba72b3808cc92209efdf7278c194e43afcc606e6f57e7a-1.PNG)
```c++
class Solution {
public:
    int judge(int N,unordered_set<int> & dic)
    {
        int ret=0,tmp;
        while(N>0)
        {
            tmp=N%10;
            if(dic.find(tmp)==dic.end())
                return -1;
            if(tmp==6)
                tmp=9;
            else if(tmp==9)
                tmp=6;
            ret=10*ret+tmp;
            N/=10;

        }
        return ret;
    }

    bool confusingNumber(int N) {
        unordered_set<int>  dic={0,1,9,8,6};
        int ret=judge(N,dic);
        if(ret==-1)
            return false;
        else if(ret == N)
            return false;
        else
            return true;
        
    }
};
```