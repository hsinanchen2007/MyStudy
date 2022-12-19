```
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> curans;

    vector<vector<string>> solveNQueens(int n) {
        search(n, 0);
        return ans;
    }
    void search(int n, int depth)
    {
        //cout<<"in"<<endl;
        if(depth == n)
        {
            ans.push_back(curans);
            return;
        }

        string tmp(n,'.');
        for(int i = 0; i < n; i++)
        {
            tmp[i] = 'Q';
            //cout<<tmp<<endl;
            curans.push_back(tmp);
            if(is_valid(depth, i))
            {
                search(n, depth + 1);
            }
            else
            {
                
            }
            curans.pop_back();
            tmp[i] = '.';
        }
    }
    bool is_valid(int x, int y)
    {
        int i = 0;
        bool flag1 = false, flag2 = false, flag3 = false;
        while(true)
        {
            if(i < x)
            {
                if(curans[i][y] == 'Q')
                    return false;
                flag1 = false;
            }
            else
                flag1 = true;

            if(x - i - 1 >=0 && y - i - 1 >= 0)
            {
                flag2 = false;
                if(curans[x-i-1][y-i-1] == 'Q')
                    return false;
            }
            else
                flag2 = true;

            if(x - i - 1 >=0 && y + i + 1 < curans[0].size())
            {
                flag3 = false;
                if(curans[x-i-1][y+i+1] == 'Q')
                    return false;
            }
            else
                flag3 = true;

            if(flag1 && flag2 && flag3)
                break;
            i++;
        }
        return true;
    }
};
```
