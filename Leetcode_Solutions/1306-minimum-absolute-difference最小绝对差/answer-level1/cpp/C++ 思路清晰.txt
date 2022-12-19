一开始用map，并不需要，只能是相邻的两个，直接比较就可以了

```
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> res;
        map<int,int> m;
        int min=INT_MAX;
        for(int i=0;i<arr.size()-1;i++){ //找出最小的差
            int now=arr[i+1]-arr[i]; 
            if(now<min) min=now;
        }     
        for(int i=0;i<arr.size()-1;i++){ //遍历数组，如果这个数+最小差存在就把它们返回
            vector<int> temp(2);
            if(arr[i+1]-arr[i]==min) {
                temp[0]=arr[i];
                temp[1]=arr[i+1];
                res.push_back(temp);
            }
        } 
        return res;
    }
};

```

原方法：
```
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> res;
        map<int,int> m;
        int min=INT_MAX;
        for(int i=0;i<arr.size()-1;i++){ //找出最小的差
            int now=arr[i+1]-arr[i]; 
            if(now<min) min=now;
        } 
        for(int i=0;i<arr.size();i++){ //对所有数据做一个map
            if(m.count(arr[i])) m[arr[i]]++;
            else m[arr[i]]=1;
        }     
        for(int i=0;i<arr.size()-1;i++){ //遍历数组，如果这个数+最小差存在就把它们返回
            int sum=arr[i]+min;
            vector<int> temp(2);
            if(m[sum]>0) {
                temp[0]=arr[i];
                temp[1]=sum;
                res.push_back(temp);
            }
        } 
        return res;
    }
};
```
