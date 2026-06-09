### 解题思路


### 代码

```cpp
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int num = 0;
        init(26);
        for(auto str : equations)
        {
            if(str[1] == '=')
                Union(str[0] - 'a', str[3] - 'a');
        }
        bool flag = true;
        for(auto str : equations)
        {
            if(str[1] == '!')
            {
                int x = findFather(str[0] - 'a');
                int y = findFather(str[3] - 'a');
                cout<<x<<" "<<y<<endl;
                if(x == y)
                {
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }
    void init(int n)
    {
        for(int i = 0 ; i < n ; ++i)
            father[i] = i;
    }
    int findFather(int x)
    {
        if(father[x] == x)
            return father[x];
        int y = findFather(father[x]);
        father[x] = y;
        return y;
    }
    void Union(int x, int y)
    {
        int fa = findFather(x);
        int fb = findFather(y);
        if(fa != fb)
            father[fa] = fb;
    }
private:
    int father[26] = {0};
};
```