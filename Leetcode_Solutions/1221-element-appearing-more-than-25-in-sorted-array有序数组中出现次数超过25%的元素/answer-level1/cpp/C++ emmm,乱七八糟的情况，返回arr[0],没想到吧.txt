```
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int len=arr.size();
        int flag=len/4;
        int count=1;
        for(int i=1;i<len;i++){
            if(arr[i]==arr[i-1]) count++;
            else count=1;
            if(count>flag) return arr[i-1];
        }
        return arr[0];
    }
};
```
