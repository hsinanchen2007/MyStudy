### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
bool puanduan(int i)
{
    while(i)
    {
        if(i%10==0) return false;
        i/=10;
    }
    return true;
}
    vector<int> getNoZeroIntegers(int n) {
        vector<int>ans;
        int i=1,j=n-1;
        while(i<=j)
        {
            if(!puanduan(i)||!puanduan(j))
            {
                i++;
                j--;
            }
            else 
            {
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
        }
        return ans;
    }
};

```