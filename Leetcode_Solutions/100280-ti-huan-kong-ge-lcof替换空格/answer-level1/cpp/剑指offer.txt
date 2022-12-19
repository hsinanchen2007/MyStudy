### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        if(s.empty() || s.size()<=0){
            return "";
        }

        int oldLen = 0;
        int bank = 0;
        int i = 0;
        while(s[i]!='\0'){
            oldLen ++;
            if(s[i] == ' '){
                bank++;
            }
            i++;
        }
        //因为s是数组，需要扩大s的长度
        for(int i=0; i<bank*2;i++){
            s += ' ';
        }

        int newLen = oldLen + bank*2;
        int indexOld = oldLen-1;
        int indexNew = newLen-1;
        while(indexNew!=indexOld){
            if(s[indexOld] == ' '){
                s[indexNew--] = '0';
                s[indexNew--] = '2';
                s[indexNew--] = '%';
            }
            else{
                s[indexNew--] = s[indexOld];
            }
            indexOld--;
        }
        return s;
    }
};
```