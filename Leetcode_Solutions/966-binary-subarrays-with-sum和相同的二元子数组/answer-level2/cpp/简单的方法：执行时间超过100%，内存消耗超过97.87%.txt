## 题解
```
A[1], A[2], ... , A[s], A[s+1], ... , A[e],...., A[l], ... , A[n]
S
```
   - s指开始位置start
   - e指第一个求和后等于S的位置equal，即A[s] + ...+A[e]=S
   - l指第一个求和后大于S的位置large，即A[s]+...+A[e]+...+A[l]>S
   - 
1、先确定第一个满足条件的序列，即A[s] + ...+A[e]=S。然后继续往后找到第一个使得A[s]+...+A[e]+...+A[l]>S。也就是A[e]后的第一个1。对于第i个往后的所有子数组数量就是l-e；

然后就可以开始遍历了。
2、i从s+1开始往后遍历。
>2.1如果A[i-1]==0,那么e和large的位置不用变，对于i-1这个位置的子数组数和之前的一样l-e

>2.2如果A[i-1]==1,那么e的位置就需要移到上一个l处，因为少了一个1，需要l处的1补上才等于S，此时的l就需要往后移动，这时再查找以后后面第一个1就好了。如果到结尾都没有，那么l=A.size()。然后子数组数量为l-e

每一次遍历把子数组数量和起来就行了。

```c++
void findEL(vector<int>& A,int S,int& start,int& equal,int& large);
int findL(vector<int>& A,int large);

class Solution {
public:
    int static numSubarraysWithSum(vector<int>& A, int S) {
        int start,equal=A.size(),large=A.size();
        findEL(A,S,start,equal,large);
        if(equal==A.size())
            return 0;
        
        int count=large-equal;
        
        for(int i=start+1;i<A.size();i++){
            if(A[i-1]!=0){
                if(equal==A.size())
                    break;
                equal=max(large,i);
                large=findL(A,large+1);
            }
            equal=max(equal,i);
            count+=(large-equal);
        }
        return count;
    }
};
//查找开始位置，“和”等于S的位置，“和”大于S的位置。
void findEL(vector<int>& A,int S,int& start,int& equal,int& large){
    bool flagStart=true;
    bool flagEqual=true;
    for(int i=0;i<A.size();i++){
        if(A[i]>S&&flagStart)
            continue;
        if(A[i]<=S && flagStart){
            start=i;
            flagStart=false;
        }
        S-=A[i];
        if(S==0 && flagEqual){
            equal=i;
            flagEqual=false;
        }
        else if(S<0){
            large=i;
            return;
        }
    }
    return;
}
//往后查找使得“和”大于S的位置
int findL(vector<int>& A,int large){
    while(large<A.size()){
        if(A[large]==1)
            return large;
        else
            large++;
    }
    return large<A.size()?large:A.size(); 
}
```