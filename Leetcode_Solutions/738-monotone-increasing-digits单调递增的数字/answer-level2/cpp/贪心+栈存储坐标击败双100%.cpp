### 解题思路
我们通过观察66778811到66777999这组样例，发现本质是如果前后是等于关系，那么我们只需要存储第一次出现的那个坐标，如果是大于关系，我们存储大的那个的坐标，这样到最后只需要把最大的那个减1，之后的都变成9就可以了。

### 代码

```cpp
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string str = to_string(N);
        bool flag = true;
        stack<int> st;
        st.push(0);
        for(int i = 1 ; i < str.length() ; ++i)
        {
            if(str[i] < str[i - 1])
            {
                flag = false;
                break;
            }
            else if(str[i] > str[i - 1])
                st.push(i);
        }
        if(flag)
            return N;
        int pos = st.top();
        str[pos] -= 1;
        if(str[0] == '0')
        {
            str = str.substr(1);
            cout<<str<<endl;
            for(int i = 0 ; i < str.length() ; ++i)
                str[i] = '9';
        }
        else
        {
            for(int i = pos + 1 ; i < str.length() ; ++i)
                str[i] = '9';
        }
        return stoi(str);
    }
};
```