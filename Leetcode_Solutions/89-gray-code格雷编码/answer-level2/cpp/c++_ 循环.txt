### 解题思路
此处撰写解题思路
n+1位的格雷码可以通过  前缀（0）+n位的格雷码的正序 和 前缀（1）+n位格雷码的逆序 
### 代码

```cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        
        vector<int> tmp_result;
        vector<int> final_result;

        tmp_result.push_back(0);
        int tmp;
        for (int i=0;i<n;i++){
            
            for (int j=0;j<tmp_result.size();j++){
                tmp=0<<i;
                final_result.push_back(tmp+tmp_result[j]);
            }
            for (int j=tmp_result.size()-1;j>=0;j--){
                tmp=1<<i;
                final_result.push_back(tmp+tmp_result[j]);
            }
            tmp_result=final_result;
            final_result.clear();
        }

        return tmp_result;

    }
};
```