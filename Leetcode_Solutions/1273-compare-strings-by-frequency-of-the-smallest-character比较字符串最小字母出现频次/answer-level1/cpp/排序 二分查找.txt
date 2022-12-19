### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> wordsnum(words.size(),0);
        for(int i=0;i<words.size();i++){
            wordsnum[i] = fminum(words[i]);
        }
        sort(wordsnum.begin(),wordsnum.end(),greater<int>());
        vector<int> res(queries.size(),0);
        for(int i=0;i<queries.size();i++){
            int target = fminum(queries[i]);
            int low=0, high = wordsnum.size();
            while(low<high){
                int mid = low+(high-low)/2;
                if(wordsnum[mid] <= target){
                    high = mid;
                } else {
                    low = mid+1;
                }
            }
            res[i] = low;
        }
        return res;
    }

    int fminum(string word){
        char minc = 'z';
        int num = 0;
        for(auto &c:word){
            if(c<minc){
                minc = c;
                num = 1;
            } else if (c == minc){
                num++;
            }
        }
        return num;
    }
};
```