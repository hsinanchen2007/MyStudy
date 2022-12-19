### 解题思路
此处撰写解题思路

### 代码
cpp
```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int res=0;
        int flag=0;
        map<char,int>m;
        for(auto c : s)
            m[c]++;
        
        for(auto it : m){
            if(it.second%2 == 0)
                res += it.second;
            else{
                if(flag == 0){
                    res += it.second;
                    flag = 1;
                }
                else{
                    res += it.second-1;
                }
            }
        }
        return res;
    }
};
```


go
```go
func longestPalindrome(s string) int {
    res := 0
    flag := 0
    m := make(map[byte]int)
    
    for i := range s{
        m[s[i]]++
    }
    
    for _,num := range m{
        if num%2==0{
            res += num
        } else{
            if flag==0{
                res += num
                flag = 1;
            }else {
                res += num-1
            }
        }
    }
    return res
}
```
