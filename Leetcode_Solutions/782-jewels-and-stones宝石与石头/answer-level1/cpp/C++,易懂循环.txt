通过for循环在S(石头)中找到J中(是宝石)的字母

```
    int numJewelsInStones(string J, string S) {
        int s=0;
        for(int i=0;i<J.size();i++){//选择宝石种类
            for(int j=0;j<S.size();j++){//在石头中找该宝石,则+1
                if(J[i]==S[j])
                    s++;
            }
        }
        return s;;
    }
```
