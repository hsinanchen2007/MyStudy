### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
    //法1：直接转化，注意判断溢出
    deque<int> deq;
    int result=0;
    if(x<0){
        if(x-1>0)
        return 0;
        while(x/10){
            int a=-(x%10);
            deq.push_back(a);
            x/=10;
        }
        deq.push_back(-x);
        if(deq.front()==0)
            deq.pop_front();
        int n=deq.size();
        for(int i=0;i<n;++i)
            result+=deq[i]*pow(10,n-i-1);
        result=-result;
        if(result-1>0)//判断负数是否溢出
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
        if(result+1<0)//判断正数是否溢出
            return 0;
        else
            return result;
    }
    //方法1,转换为long long 
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