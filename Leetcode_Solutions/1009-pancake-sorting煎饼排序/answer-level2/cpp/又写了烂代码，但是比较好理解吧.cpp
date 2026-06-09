```
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> RESULT;
        int LENTH = A.size(); 
        for(int i = 0; i < LENTH; ++i){
            help(A, RESULT);
        }
        return RESULT;
    }
    void help(vector<int>& B, vector<int> &C) {  
        auto maxelement = max_element(B.begin(),B.end());
        int insertlocation = maxelement - B.begin() + 1;
        reverse(B.begin(), B.begin() + insertlocation);
        reverse(B.begin(),B.end());
        B.erase(B.end() - 1);
        C.push_back(insertlocation);
        C.push_back(B.size() + 1);
        cout << endl;
    }
};
```
![image.png](https://pic.leetcode-cn.com/030ad0b31beeada6d843e97c219880b3db0b0a4a123d30abc9f017b6c1188a6f-image.png)
