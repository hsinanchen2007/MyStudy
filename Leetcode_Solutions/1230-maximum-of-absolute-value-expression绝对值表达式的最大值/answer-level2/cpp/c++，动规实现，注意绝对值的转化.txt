# 1.思路
想要达到$O(N)$复杂度，肯定是动规实现。假设$n-1$规模问题的解是$res_{n-1}$,那么$n$规模的问题的解$res_{n}$，只有两种可能
第$n$个元素的加入并没有影响结果，$res_{n}=res_{n-1}$；
第$n$个元素的加入影响结果，此时$j=n$，$res_{n}=max_{i}(|arr1_i-arr1_n|+|arr2_i-arr2_n|+n-i)$...$(*1)$；
处理时选两种情况最大值。但是，此时发现递归式中对$i$没有固定结果，考虑处理绝对值将变量集中。
# 2.绝对值转化与带入
很简单的基础公式$|a|=max(a,-a)$，以下推导都用这个。
$|arr1_i-arr1_n|+|arr2_i-arr2_n|$为一下二式最大值：
$|(arr1_i-arr2_i)-(arr1_n-arr2_n)|$,
$|(arr1_i+arr2_i)-(arr1_n+arr2_n)|$。
可以看到若令$A[i]=arr1_i-arr2_i$,$B[i]=arr1_i+arr2_i$,
绝对值改写为
$|arr1_i-arr1_n|+|arr2_i-arr2_n|=max(|A[i]-A[n]|,|B[i]-B[n]|)$
带入$(*1)$
$(*1)=max_{i}(max(|A[i]-A[n]|,|B[i]-B[n]|)+n-i)$
$=n+max_{i}(max(|A[i]-A[n]|,|B[i]-B[n]|)-i)$（对i求与n无关）
$=n+max(max_{i}(A[i]-A[n]-i),max_{i}(-A[i]+A[n]-i),max_{i}(B[i]-B[n]-i),max_{i}(-B[i]+B[n]-i))$(绝对值展开)
$=n+max(-A[n]+max_{i}(A[i]-i),A[n]-min_{i}(A[i]+i),-B[n]+max_{i}(B[i]-i),B[n]-min_{i}(B[i]+i))$（max-=-min）
在这里可以看到，对res刷新的同时，需要四个变量进行刷新：
$max_{i}(A[i]-i)$，$min_{i}(A[i]+i)$，$max_{i}(B[i]-i)$，$min_{i}(B[i]+i)$，
最后归纳就可以得到结果了
# 3代码
```
class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int temp,n=arr1.size();
        for(int i=0;i<n;i++){
            temp=arr2[i]+arr1[i];
            arr2[i]-=arr1[i];
            arr1[i]=temp;
        }
        int record1min=min(arr1[0],arr1[1]+1);
        int record1max=max(arr1[0],arr1[1]-1);
        int record2min=min(arr2[0],arr2[1]+1);
        int record2max=max(arr2[0],arr2[1]-1);
        int res=1+max(abs(arr1[0]-arr1[1]),abs(arr2[0]-arr2[1]));
        
        for(int j=2;j<n;j++){
            res=max(res,j+max(max(arr1[j]-record1min,-arr1[j]+record1max),
            max(arr2[j]-record2min,-arr2[j]+record2max)));
            record1min=min(record1min,j+arr1[j]);
            record1max=max(record1max,arr1[j]-j);
            record2min=min(record2min,j+arr2[j]);
            record2max=max(record2max,arr2[j]-j);
        }
        return res;
    }
};
```
