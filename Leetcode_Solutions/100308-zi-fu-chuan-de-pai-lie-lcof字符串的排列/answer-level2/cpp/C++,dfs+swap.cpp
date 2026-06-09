

### 代码

```cpp
class Solution {
public:
    vector<string> res;
    vector<string> permutation(string s) {
        sort(s.begin(),s.end());
        dfs(s,0);
        return res;
    }
    void dfs(string s, int start){
        if(start==s.size()-1){
            res.push_back(s);
            return;
        }
        for(int i=start;i<s.size();i++){
            int k;
            //检查要交换的这个,在已经交换过的里面,有没有相同的,有就不交换了
            for(k=i-1;k>=start;k--)
                if(s[k]==s[i])
                    break;
            if(k!=start-1)//查重没通过,跳过这个数
                continue;
            //正常交换递归
            swap(s[i],s[start]);
            dfs(s,start+1);
            //swap(s[i],s[start]);//换回来？
        }

    }
};
```