### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> ret;
        //corner case invalid check
        if(num.size() <= 2)
            return ret;
        //first we need to sort the array because we need the non-descending order
        sort(num.begin(), num.end());
        for(int i = 0; i < num.size()-2; ++i){
            int j = i+1;
            int k = num.size()-1;
            while(j < k){
                //create a tmp vector to store each triplet which satisfy the solution.
                vector<int> curr;
                if(num[i]+num[j]+num[k] == 0){
                    curr.push_back(num[i]);
                    curr.push_back(num[j]);
                    curr.push_back(num[k]);
                    ret.push_back(curr);
                    ++j;
                    --k;
                //this two while loop is used to skip the duplication solution
                    while(j < k&&num[j-1] == num[j])
                        ++j;
                    while(j < k&&num[k+1] == num[k])
                        --k;
                }
                if (num[i]+num[j]+num[k] < 0){
                    ++j;
                }
                if (num[i]+num[j]+num[k] > 0){
                    --k;
                }
                //this while loop also is used to skip the duplication solution
                while(i < num.size()-1&&num[i] == num[i+1])
                    ++i;
            }
        }
        return ret;
    }
};
```