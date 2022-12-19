```
class Solution {
public:
//通常的做法是在i位置，然后判断i位置吧左边上升序列个数，i位置右边下降位置的个数
    int longestMountain(vector<int>& A) {
        int n=A.size();
        vector<int>left(n,1),right(n,1);//left[i]表示的是i位置左边最大的上升序列长度，right[i]表示的是i位置右边最大的下降序列
        for(int i=0;i<n;i++){
            if(i>0&&A[i-1]<A[i])left[i]=left[i-1]+1;
        }
        for(int i=n-1;i>=0;i--){
            if(i<n-1&&A[i]>A[i+1])right[i]=right[i+1]+1;
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(left[i]==1||right[i]==1)continue;
            res=max(res,left[i]+right[i]-1);
        }
        return res;
    }
};
```
