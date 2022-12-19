### 解题思路
此处撰写解题思路
1.初始设定数量nCount = 0;
2.如果是数字加1,否则就减1,那么从0开始遍历,当nCount == 0时,数字和字母数量相同.
3.如果nCount!= 0 ,就要从前找下标a,使得0 - a  == 0 - b;那么a+1 - b 数字和字母是相同的;
### 代码

```cpp
class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        static auto speedup = [](){ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
 
        unordered_map<int, int> mmp;
        int begin = 0, end = 0,nCount = 0;

        for (int i = 0; i < array.size(); ++i){
            if (isdigit(array[i][0])) nCount++;
            else nCount--;

            if (nCount == 0) { begin = 0; end = i; }
            else  if(mmp.find(nCount) == mmp.end())
                mmp[nCount] = i; 
            else if (i - mmp[nCount] - 1 > end - begin)
            {
                begin = mmp[nCount] + 1;
                end = i;
            }
        }
        if (begin == end) return{};
        return vector<string>(array.begin() + begin, array.begin() + end + 1);
    }
};
```