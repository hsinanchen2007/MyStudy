### 解题思路
此处撰写解题思路，参考了评论重写了一遍，执行用时 :4 ms
, 在所有 C++ 提交中击败了76.90%的用户内存消耗 :7.6 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
    long long int res=0;    //long long
    while(x!=0){
        res=res*10+x%10;    //反转，此操作可以自然避免反转后首项为0；
        x/=10;
    }
    return (res<INT_MIN||res>INT_MAX)? 0:static_cast<int>(res);
/*    if(res<0){
        if(res<INT_MIN)
            return 0;
        else
            return static_cast<int>(res);
    }
    else{
        if(res>INT_MAX)
            return 0;
        else
            return static_cast<int>(res);
    }
*/
    /*
    deque<int> deq;
    int result=0;
    if(x<0){
        if(x-1>0)
        return 0;
        while(x/10){
            deq.push_back(-(x%10));
            x/=10;
        }
        deq.push_back(-x);
        if(deq.front()==0)
            deq.pop_front();
        int n=deq.size();
        for(int i=0;i<n;++i)
            result+=deq[i]*pow(10,n-i-1);
        result=-result;
        if(result-1>0)
            return 0;
        else
            return result;
    }
    else{
        while(x/10){
            deq.push_back(x%10);
            x/=10;
        }
        deq.push_back(x);
        if(deq.front()==0)
            deq.pop_front();
        int n=deq.size();
        for(int i=0;i<n;++i)
            result+=deq[i]*pow(10,n-i-1);
        if(result+1<0)
            return 0;
        else
            return result;
    }
    */
    //方法2:直接转换成long long
/*
    deque<long long> deq;
    long long tmp=x;
    long long result=0;
    int res=0;
    long long MIN=-pow(2,31),MAX=pow(2,31)-1;
    if(tmp<0){
        tmp=-tmp;
        while(tmp/10){
            deq.push_back(tmp%10);
            tmp/=10;
        }
        deq.push_back(tmp);
        if(deq.front()==0)
            deq.pop_front();
        int n=deq.size();
        for(int i=0;i<n;++i){
            result+=deq[i]*pow(10,n-i-1);
        }
        if(-result<MIN)
            return 0;
        else{
            res=-result;
            return res;
        }

    }
    else{
        while(tmp/10){
            deq.push_back(tmp%10);
            tmp/=10;
        }
        deq.push_back(tmp);
        if(deq.front()==0)
            deq.pop_front();
        int n=deq.size();
        for(int i=0;i<n;++i)
            result+=deq[i]*pow(10,n-i-1);
        if(result>MAX)
            return 0;
        else{
            res=result;
            return res;
        }
    }
*/

    }
};
```