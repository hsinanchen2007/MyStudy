
### 代码

```cpp
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if(a.empty()) return {};
        
        vector<int> output;
        //用help1记录a[i]左边所有项的乘积（a[0]左边的项的乘积为1）
        //用help2记录a[i]右边所有项的乘积（a.back()右边的项的乘积为1）
        vector<int> help1,help2;

        help1.push_back(1);
        int sum=1;
        for(int i=0;i<a.size()-1;i++)
            help1.push_back(sum*=a[i]);
        sum=1;
        for(int i=a.size()-1;i>0;i--)
            help2.push_back(sum*=a[i]);
        reverse(help2.begin(),help2.end());
        help2.push_back(1);

        //output[i]为a[i]左右所有项的乘积
        for(int i=0;i<a.size();i++)
            output.push_back(help1[i]*help2[i]);
        
        return output;
    }
};
```