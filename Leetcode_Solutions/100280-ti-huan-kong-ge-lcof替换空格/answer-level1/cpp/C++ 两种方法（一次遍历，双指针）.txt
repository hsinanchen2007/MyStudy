### 解题思路
![1581482989(1).png](https://pic.leetcode-cn.com/cbbd4287b365a833f2e0a85d01c7574d8e3a8ba7820bbd8621b14439920e8aa7-1581482989\(1\).png)


### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        //方法1
         string res="";
         for(int i=0;i<s.size();i++){
             if(s[i]==' ')res+="%20";
             else res+=s[i];
         }
         return res;

        //方法2：双指针，两次循环第一次计算空格数量
        int num=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ')num++;
        }
        int newlength=s.size()+2*num;
        string res(newlength,'0');
        int p1=s.size()-1;
        int p2=res.size()-1;
        while(p1>=0){
            if(s[p1]!=' '){
                res[p2--]=s[p1];
            }
            else{
                res[p2--]='0';
                res[p2--]='2';
                res[p2--]='%';
            }
            p1--;
        }
        return res;
    }
};
```