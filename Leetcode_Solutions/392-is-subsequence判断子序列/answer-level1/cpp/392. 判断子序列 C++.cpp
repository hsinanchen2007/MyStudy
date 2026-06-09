### 解题思路
1.双指针，a指针遍历s字符串，b指针用于获取每次在t字符串找到字符位置。
2.每次直到查找b指针后的t的子字符串符合题意，一旦没找到字符则返回false，全部遍历成功则返回true。

### 代码

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int a = 0, b = 0;
        for (a = 0; a < s.size(); a++){
            b = t.find(s[a], b);
            if(b == -1){
                return false;
            }
            else{
                b++;
            }
        }
        return true;
    }
};
```