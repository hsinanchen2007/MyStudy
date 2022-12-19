### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        //进阶也必须尝试。。。！！！
        int flag=0;
        int i=0;
        while(i<s.length()){
            if(!flag){
                if(s[i]== ' '){
                    s.erase(s.begin()+i);
                    continue;
                }
                else{
                    flag=1;
                }
            }
            else{
                if(s[i]==' ') flag=0;
            }
            i++;
        }

        i=s.length()-1;
        while(i>-1){
            if(s[i]==' ') s.erase(s.begin()+i);
            else break;
        }

        reverse(s.begin(),s.end());
        i=0;
        int j=1;
        while(j<s.length()){
            if(s[j]==' '){
                reverse(s.begin()+i,s.begin()+j);
                i=j+1;
                j=i+1;
            }
            else if(j==s.length()-1) {
                reverse(s.begin()+i,s.end());
                break;
            }
            else j++;            
        }
        return s;
    }
};
```