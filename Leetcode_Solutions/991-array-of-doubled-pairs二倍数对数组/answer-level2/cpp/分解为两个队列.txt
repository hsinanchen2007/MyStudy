思路：先升序排列，再按照正负性分别进入d1和d2队列。
以负数队列d1为例，若当前整数为队头的1/2，则队头出队；否则，将当前整数压入队列。
若最后d1和d2为空，则表示A符合题解。
```
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) 
    {
        if (A.size()%2)
        return false;
        sort(A.begin(),A.end());
        queue<int> d1,d2;
        for(auto x:A)
        {
            if(x<0)
            {
                if(!d1.empty() && 2*x==d1.front())
                d1.pop();
                else
                d1.push(x);
            }
            else
            {
                if(!d2.empty() && x==2*d2.front())
                d2.pop();
                else
                d2.push(x);
            }
        }
        if(d1.empty() && d2.empty())
        return true;
        else
        return false;

    }
};
```
时间复杂度O（n），空间复杂度O（n）.
