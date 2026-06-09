找到第一个6换成9

```c++
class Solution {
public:
    int fun(vector<int> &v)
    {
        int num=0;
        int x = 1;
        for(int j = 0;j<v.size();j++)
        {
            num += v[j]*x;
            x = x*10;
        }
        return num;
    }
    int maximum69Number (int num) {
        int res = num;
        vector<int> v;
        while(res>0)
        {
            v.push_back(res%10);//9 6 6 9
            res = res/10;
        }
        for(int i =0 ;i<v.size();i++)
        {
            cout<<v[i]<<endl;
        }
        int max_num = num;
        vector<int> tmp;
        int flag=0;
        for(int i = v.size()-1;i>=0;i--)
        {
            tmp.assign(v.begin(),v.end());
            if(tmp[i] == 6)
            {
                flag = 1;
                tmp[i] = 9;
            }
            int ans = fun(tmp);
            cout<<ans<<endl;
            max_num = max(max_num ,ans);
            if(flag ==1)
            {
                break;
            }
        }

        return max_num;
        
    }
};
```
