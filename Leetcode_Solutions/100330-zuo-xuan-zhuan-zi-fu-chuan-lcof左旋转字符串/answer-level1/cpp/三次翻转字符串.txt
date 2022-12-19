### 解题思路


### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        
        int size = s.size();
        
        string ans;
        if(n > size) return  ans;
        reservestring(s,0,n - 1);
        reservestring(s,n,size - 1);
        reservestring(s,0,size - 1);

        return s;
    }

    void reservestring(string &str,int left,int right)
    {
        while(left < right)
        {
            swap(str[left++],str[right--]);
        }
    }

    
};
```