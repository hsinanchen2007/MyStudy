思路为遍历nums数组，数字后向之前每个结果vector进行插空，有vector.size()+1个空可以选择，将其他数再填入数组更新结果vector。
```
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> per;
        for(int i=0;i<nums.size();i++){
            if(i==0)
                per.push_back({nums[i]});
            else{
                vector<vector<int>> go;
                for(int j=0;j<per.size();j++){
                    for(int k=0;k<=per[j].size();k++){
                        vector<int>temp(per[j].size()+1);
                        for(int t=per[j].size();t>k;t--)
                            temp[t] = per[j][t-1];
                        temp[k]=nums[i];
                        for(int t=0;t<k;t++)
                            temp[t]=per[j][t];
                        go.push_back(temp);
                    }
                }
                per=go;
            }
        }
        sort(per.begin(),per.end());
        return per;
    }
};
```
