### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<string> ans;
    //和别人互为对称
    unordered_map<char,char> half={{'6','9'},{'9','6'}};
    //自己和自己对称
    unordered_map<char,char> complete={{'0','0'},{'1','1'},{'8','8'}};
    int len;
    vector<string> findStrobogrammatic(int n) {
        len=n;
        dfs(n,"","");
        return ans;
    }

    void dfs(int n,string l,string r){//n代表还没填充的空位的数量,l代表左边的串,r代表右边的串
        //cout<<n<<":"<<l<<" "<<r<<endl;
        if(n==0){
            //左右拼凑起来并且加入vector
            ans.push_back(l+r);
            return;
        }
        else if(n==1){
            unordered_map<char,char>::iterator it;
            for(it=complete.begin();it!=complete.end();it++){
                string s=l+it->first+r;
                ans.push_back(s);
            }
            return;
        }

        unordered_map<char,char>::iterator it;
        for(it=half.begin();it!=half.end();it++){
            dfs(n-2,l+it->first,it->second+r);
        }
        for(it=complete.begin();it!=complete.end();it++){
            if(n==len&&it->first=='0') continue;
            dfs(n-2,l+it->first,it->second+r);
        }
    }

};
```