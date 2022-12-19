### 解题思路
利用辅助string来依次复制目标，遇到空格就添加“%20”
(ps:剑指offer上直接在原string上进行操作，这样string得扩容。。。手动狗头)


### 代码

**利用辅助string**

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        string s1;
        int i=0;
        while(i<s.size()){
            if(s[i]==' '){
                s1+="%20";
            }
            else{
                s1.push_back(s[i]);
            }
            i++;
        }
        return s1;
    }
};
```

**直接在原string上操作**
```
class Solution {
public:
    string replaceSpace(string s) {
        int count=0;
        int lenth=s.size();
        int i=0;
        while(i<lenth){
            if(s[i]==' '){
                count++;
                s=s+"  ";             //手动扩容。。。。
            }
            i++;
        }
        lenth=lenth-1;
        int endLenth=lenth+count*2;
        while(lenth>=0&&(lenth<endLenth)){
            if(s[lenth]==' '){
                s[endLenth--]='0';
                s[endLenth--]='2';
                s[endLenth--]='%';
            }
            else{
                s[endLenth--]=s[lenth];
            }
            lenth--;
        }
        return s;
    }
};
```
