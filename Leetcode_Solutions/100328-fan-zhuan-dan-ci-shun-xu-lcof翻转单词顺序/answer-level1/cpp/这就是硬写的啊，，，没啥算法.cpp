### 解题思路
熟悉了string的函数
首尾空格挺费劲。。

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        int i=0,j=0,k=0;
        int len = s.size();
        stack<char>  sta;

        //倒序并且压栈，去除了多余空格
        for(i=0;i<len;i=k){
            j=i;
            while(s[j]==' '){
                j++;
            }
            for( k = j;s[k]!=' '&&k<len;k++){   //k<len 保证不越界
                sta.push(s[k]);
            }
            sta.push(' ');
        }
       
        //清空s后，出栈
        s.erase(0,len);
        while(sta.size()){            
            s.push_back(sta.top()); 
            sta.pop();
        }
 
        //字是反的，eulb si yks eht ，所以再翻过来，j是记录了要插入的新位置
        string ss;
        for(i=0;i<s.size();i++){
            
            if(s[i]==' '){
                j=i;
            }
            ss.insert(ss.begin()+j,s[i]);
        }
        
        //去掉首尾空格
        if(ss[0]==' '){
            ss.erase(0,1);
            }
        if(ss[ss.size()-1]==' '){
            ss.pop_back();
        }
                

        return ss;
    }
};
```