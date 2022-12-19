### 解题思路
此处撰写解题思路
双指针向中间遍历，碰到元音交换，其他跳过。直到指针相遇。
### 代码

```cpp
class Solution {
public:
    bool isYuanYin(char a){
        bool f=false;
        switch(a){
            case 'a':
                f=true;
                break;
            case 'e':
                f=true;
                break;
            case 'i':
                f=true;
                break;
            case 'o':
                f=true;
                break;
            case 'u':
                f=true;
                break;
            case 'A':
                f=true;
                break;
            case 'E':
                f=true;
                break;
            case 'I':
                f=true;
                break;
            case 'O':
                f=true;
                break;
            case 'U':
                f=true;
                break;
        }
        return f;
    }
    string reverseVowels(string s) {
        int i=0;
        int j=s.length()-1;
        if(j==-1){
            return s;
        }
        while(i<=j){
            bool a=isYuanYin(s[i]);
            bool b=isYuanYin(s[j]);
            if(a==true && b==false){
                j--;
            }else if(a==false && b==true){
                i++;
            }else if(a==false && b==false){
                i++;j--;
            }else{
                swap(s[i],s[j]);
                i++;j--;
            }
        }
        return s;
    }
};
```