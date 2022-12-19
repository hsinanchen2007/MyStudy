

### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        long long int ans=0;
        int flag=0;
        for(int i=0;i<str.size();i++){
            if((flag&1) == 0 && str[i]==' ')
                continue;
            flag|=1;
            if((flag&14)==0 && (str[i]=='+' || str[i]=='-')){
                flag|=(str[i]=='-'?2:4);
                continue;
            }
            if(str[i]>='0' && str[i]<='9'){
                flag|=8;
                ans=10*ans+str[i]-'0';
                if(ans>(long long)INT_MAX)
                    return (flag&2)==2?INT_MIN:INT_MAX;
                continue;
            }
            break;
        }
        return (flag&2)==2?-ans:ans;
    }
};
```