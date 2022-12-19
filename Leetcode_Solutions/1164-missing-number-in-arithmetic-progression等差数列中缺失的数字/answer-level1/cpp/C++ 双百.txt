- 由于题目告知不删除头和尾，可以通过arr[1]-arr[0]  与 arr[arr.size()-1]-arr[arr.size()-2] 的大小比较来求出等差数列的值
```
- class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int l=arr.size()-1;
        int jianju=0;
        if((arr[l]-arr[l-1])==(arr[1]-arr[0]) && l==1){return arr[0]+(arr[l]-arr[l-1])/2;}
        bool flag=0;
        if((arr[l]-arr[l-1])>0){flag=1;}
        if(flag==1){
            jianju=(arr[l]-arr[l-1])<(arr[1]-arr[0])?(arr[l]-arr[l-1]):(arr[1]-arr[0]);
        }
        else{
             jianju=(arr[l]-arr[l-1])>(arr[1]-arr[0])?(arr[l]-arr[l-1]):(arr[1]-arr[0]);
        }
        for(int i=0;i<l;i++){
            if((arr[i+1]-arr[i])!=jianju){
                return arr[i]+jianju;
            }
        }
        return 0;
    }
};
```
