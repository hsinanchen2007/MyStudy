本题使用滑动窗口和简单hash，复杂度为2n
```
//左窗口滑到谁就删掉，右窗口滑到谁就加进来并判断重复，更新左窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool In[128];
        int len = s.size();
        int ans = 0;
        int tempans = 0;
        memset(In,0,128);
        int l = 0;
        if(s[0]==' ') return 1;
        for(int r = 0;r<len;r++)
        {
            int tempchar = s[r]-' ';
            if(In[tempchar])
            {
                while(In[tempchar])
                {
                    int tempchar2 = s[l]-' ';
                    In[tempchar2] = false;
                    l++;
                }
            }
            In[tempchar] = true;
            tempans = r-l+1;
            ans = max(ans,tempans);

        }
        return ans;
    }
};
```
执行用时 :
12 ms, 在所有 C++ 提交中击败了87.77%的用户
内存消耗 :
9.2 MB, 在所有 C++ 提交中击败了87.40%的用户