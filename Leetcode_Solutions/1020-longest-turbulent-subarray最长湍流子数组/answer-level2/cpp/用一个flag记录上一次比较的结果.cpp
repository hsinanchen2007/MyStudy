88ms，13MB都击败90%
```
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        if(A.size()<=1)return A.size();
        int maxl=1;//最长子数组长度
        int temp=1;//当前子数组长度
        int flag=0;//上一次比较结果，0对应相等，1对应递减，-1对应递增
        for(int i=0;i<A.size()-1;i++){
            if(A[i]>A[i+1]){
                if(flag==1)
                    temp++;//上一次为递减且此次为递增，则增加长度
                else
                    temp=2;//不符合湍流，重置长度
                flag=-1；//更新状态
                if(temp>maxl)maxl=temp;
            }else if(A[i]<A[i+1]){//与上面类似
                if(flag==-1)
                    temp++;
                else
                    temp=2;
                flag=1;
                if(temp>maxl)maxl=temp;
            }else{
                flag=0;
                temp=1;//两个元素相等长度从1开始
            }          
        }
        return maxl;
    }
};
```
