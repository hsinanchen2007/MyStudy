### 解题思路
执行用时:8 ms, 在所有 C++ 提交中击败了 85.79% 的用户
内存消耗:8.9 MB, 在所有 C++ 提交中击败了 100.00% 的用户

### 代码

```cpp
class Solution {
public:
    void swap(char* p, char* q){
        char temp;
        while(p < q){
            temp = *p;
            *p = *q;
            *q = temp;
            p++;
            q--;
        }
    }
    string reverseWords(string s) {
        string res;
        int cnt=0, flag = 0;
        char a[10000005];
        s.erase(0,s.find_first_not_of(" "));  //去除首尾空格
        s.erase(s.find_last_not_of(" ") + 1);
        for(int i=0; i<s.length(); i++){
            if(!flag && s[i]==' '){  //标记法-只保留单词间的一个空格
                flag = 1;
                a[cnt++] = s[i];
            }
            if(s[i] != ' '){
                a[cnt++] = s[i];
                flag = 0;
            }
        }
        a[cnt] = '\0';
        char *p = a;
        char *q = p;
        while(*q != '\0'){
            if(*q == ' '){
                swap(p, q-1);
                q++;
                flag = 1;
                p = q;
            }
            else  q++;
        }
        swap(p, q-1);
        swap(a, q-1);
        res = a;
        return res;
    }
};
```