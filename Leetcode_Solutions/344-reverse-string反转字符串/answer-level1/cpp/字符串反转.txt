### 解题思路
两种方式：
双指针++循环
递归，先交换，在向里递归，反之也可以。堆栈空间消耗o(n/2)

### 代码

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0,j=s.size()-1;
        char temp;
        while(i<j){
            temp=s[i];
            s[i]=s[j];
            s[j]=temp;
            ++i;
            --j;
        }
        return;
    }
};


class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0,j=s.size()-1;
        char temp;
        res(s,i,j,temp);
        return;
    }
    void res(vector<char> &s,int i,int j,char &temp){
        if(i>=j) return;
        temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        ++i;
        --j;
        res(s,i,j,temp);
        return;
    }
};
```