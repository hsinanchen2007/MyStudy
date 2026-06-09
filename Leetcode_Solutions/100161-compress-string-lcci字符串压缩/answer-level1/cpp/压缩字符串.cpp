### 解题思路
此处撰写解题思路

### 代码
```和自己的代码比较
class Solution {
public:
    string compressString(string S) {
        if(S.empty()) {//判空的意识
            return S;
        }

        string ans = "";
        int cnt = 1;
        char ch = S[0];//记录，再比较
        for(int i = 1; i < S.size();i++) {
            if(ch == S[i]) {
                cnt++;//有记录就可以顺着遍历下去，不要在循环内判断，节省时间
            } else {
                ans += ch + to_string(cnt);
                cnt = 1;
                ch = S[i];
            }
        }

        ans += ch + to_string(cnt);//处理结尾
        return ans.size() >= S.size() ? S : ans;
    }
};
```


```cpp
class Solution {
public:
    string compressString(string S) {
string a;
    int l1 = S.size();int flag = 0;int i;
    for ( i= 0; i < l1 ; ++i) {//i必须遍历全部，一个不能留
        
        if (i<l1-1&&S[i + 1] == S[i]) {//i<l1-1用到这里来！！
            int j = 2;
            while (j < l1 - i ) {
                if (S[i + j ] != S[i]) break;
                j++;
            }
            a += S[i];
            a += to_string(j);
            i = i + j-1 ;
            flag = 1;
        }
        else {a += S[i];a+='1';}
        
    }
    return a.size()<S.size() ? a:S;
    }
};
```