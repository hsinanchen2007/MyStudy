1.先判断数组是否符合要求否则直接return false
2.然后求出sum 判断sum是否可以被三等分 否则returnfalse
3.开始双指针过程将左边初始化为A[0] 右边初始化为A[A.size()-1] 然后向中间合并
4.最后判断一下是否符合要求
```
typedef long long LL;


class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        if(A.size()<3)
            return false;
        
        LL sum=0;
        
        for(auto x:A)
            sum+=x;
        
        if(sum/3*3==sum)
        {
            LL x=sum/3;
            
            int head=-1,tail=A.size();
            
            int prex=A[++head],postx=A[--tail];
        
            
            
            while(prex!=x)
            {
                prex+=A[++head];
                if(head>=tail-1)
                    return false;
                
            }
                
            while(postx!=x)
            {        
                postx+=A[--tail];
                if(tail<=head+1)
                    return false;
                    
            }
                
            if(head<tail&&prex==x&&postx==x)
                return true;
            else
                return false;
            
        }
        else 
            return false;
        
    }
};
```
