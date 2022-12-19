### 解题思路
要先对abc排序，然后根据规律分三种情况
最大值max就是c-a-2

### 代码

```cpp
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> ans;
        int temp[3];
        temp[0]=a;
        temp[1]=b;
        temp[2]=c;
        sort(temp,temp+3);
        a=temp[0];
        b=temp[1];
        c=temp[2];
        int max=c-a-2;
        if(a+1==b&&b+1==c)
        {
        ans.push_back(0);
        ans.push_back(max);
        return ans;
        }
        if(a+1==b||a+2==b||b+1==c||b+2==c)
        {
         ans.push_back(1);
        ans.push_back(max);
        return ans;
        }
         ans.push_back(2);
        ans.push_back(max);
        return ans;
    }
};
```