### 解题思路
核心思路：第一次遍历计算字符串所含空格数，第二次遍历从后向前插入结果字符串
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :7.7 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        int countb=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ')countb++;
        }
        string result(s.size()+2*countb,' ');
        for(int i=result.size()-1,j=s.size()-1;j>=0;j--){
            if(s[j]!=' '){
                result[i]=s[j];
                i--;
            }
            else{
                result[i--]='0';
                result[i--]='2';
                result[i--]='%';
            }
        }
        return result;
    }
};
```