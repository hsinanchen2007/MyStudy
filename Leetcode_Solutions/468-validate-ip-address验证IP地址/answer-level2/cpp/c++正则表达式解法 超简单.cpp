### 解题思路
此处撰写解题思路
这里分享一个正则字符串解法吧，因为本人确实刚刚入手正则表达式没多久，原本是为ccf准备的，今天刷力扣字符串处理的题突然感觉可以用正则表达式试一下，mark一下吧。正则表达式虽然慢，但是的确非常强大呀
### 代码

```cpp
class Solution {
public:
    string validIPAddress(string IP) {
       smatch result;
       string ans;
       //首先检查是否是ipv4的地址
       if(regex_match(IP,result,regex("([0-9]+)\\.([0-9]+)\\.([0-9]+)\\.([0-9]+)")))
       {
           for(int i=1;i<=4;i++)
           {
               string temp=result.str(i);
               //首先判断是否<256;
               if(temp.size()>3||stoi(temp)>255||(temp.size()>1&&temp[0]=='0'))
               {
                   ans="Neither";
                   return ans;
               }
           }
           ans="IPv4";
           return ans;
       }
       if(regex_match(IP,result,regex("([0-9a-fA-F]+):([0-9a-fA-F]+):([0-9a-fA-F]+):([0-9a-fA-F]+):([0-9a-fA-F]+):([0-9a-fA-F]+):([0-9a-fA-F]+):([0-9a-fA-F]+)")))
       {
           for(int i=1;i<=8;i++)
           {
               string temp=result.str(i);
               if(temp.size()>4)
               {
                   ans="Neither";
                   return ans;
               }
           }
           ans="IPv6";
           return ans;
       }
        ans="Neither";
       return ans;
    }
};
```