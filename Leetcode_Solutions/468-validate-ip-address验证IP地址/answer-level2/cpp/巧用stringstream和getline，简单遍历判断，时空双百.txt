### 解题思路
其实题目要求的格式和真实有点区别。。按题目要求进行判断就好
题目本身没什么难度，就是边界条件有点麻烦。试过正则表达式，效率很低，所以还是直接遍历判断就好
时空复杂度：应该可以算O（1）吧。。不太懂，有错的话请大佬指点
### 代码

```cpp
class Solution {
public:
    int check(string& s, char a){
        int cnt = 0;
        if(a == '.'){// 这里是对ipv4判断的过程，cnt统计的是'.'出现的次数
            for(auto c: s){
                if(c == a) cnt++;
                // 如果在ipv4中出现既不是数字也不是'.'的说明无效
                // 直接清空cnt并退出判断
                if(c != a && !isdigit(c)){
                    cnt = 0;
                    break;
                }
            }
        }

        if(a == ':'){// cnt统计出现':'的次数
            for(auto c: s){
                if(c == a) cnt++;
                if(c != a){
                    // ipv6要对十六进制判断，允许的范围是0到F
                    if(!(isdigit(c) || (isalpha(c) && 'A' <= toupper(c) && toupper(c) < 'G'))){
                        cnt = 0;
                        break;
                    }
                }
            }
        }
        
        return cnt;
    }
    string validIPAddress(string IP) {
        if(IP.find(".") != string::npos) return judgeV4(IP);
        return judgeV6(IP);
    }
    string judgeV4(string ip){
        if(check(ip, '.') != 3) return "Neither";
        int cnt = 0;
        stringstream ss;
        ss << ip;
        string tmp;
        //getline 可以用指定的分隔符来分割流中的数据，判断条件很简单
        while(getline(ss, tmp, '.')){
            cnt++;
            // 防止测试数据出现"-0"这种诡异的用stoi判断不出来的东西
            if(tmp == "" || (tmp.size() > 1 && (tmp[0] < '1' || tmp[0] > '9')) || tmp.size() > 4) 
                return "Neither";
            int t = stoi(tmp);
            if(t < 0 || t > 255) return "Neither"; 
        }
        return cnt == 4? "IPv4": "Neither";        
    }

    string judgeV6(string ip){
        if(check(ip, ':') != 7) return "Neither";
        stringstream ss;
        ss << ip;
        int cnt = 0;
        string tmp;
        while(getline(ss, tmp, ':')){
            cnt++;
            if(tmp.size() > 4) return "Neither";
            if(tmp == "") return "Neither";
        }
        if(cnt != 8) return "Neither";
        return "IPv6";
    }

};
```
![图片.png](https://pic.leetcode-cn.com/e49383727a740e6140eeac5b7fe17b6a8b1902ce2275efd9b1543a1418b9358a-%E5%9B%BE%E7%89%87.png)
