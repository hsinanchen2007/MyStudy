### 解题思路
递归实现回溯逻辑：
1.搭架子：类似模板确认每次递归要要遍历的上下边界及满足条件后的处理逻辑
        for(j = 下界; j <= 上界; j=j+1)  // 枚举i所有可能的路径
        {
            if(fun(j))                 // 满足限界函数和约束条件，剪枝
              {
                 a[i] = j;
                  ...                         // 其他操作
                 try(i+1);
                 回溯前的清理工作（如a[i]置空值等）;
               }
          }

2.内部遍历逻辑(业务逻辑)处理：
    1）递归前后变量不依赖
    2）递归内部构造Ip字符串
    3）更新输出及理想终止条件

3.剪枝处理：
    1）剩余字符串个数及IP段数之间限制条件
    2）各段位值限制

### 代码

```cpp
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        rstIps.clear();
        string lastStr;
        string ipStr;
        recursionIpAddress(0, lastStr, ipStr, s, 0);
        return rstIps;
    }

    
    void recursionIpAddress(int ipN, string &lastStr, string &ipStr, string &s, int n) {
        if (ipN == 4 && n == s.size()) {
            rstIps.push_back(ipStr);
            ipStr.clear();
            return;
        }

        string ipTmpStr(ipStr);
        if (s.size() - n  < 4 - ipN  ||  3 * (4 - ipN) < s.size() - n) {
            return;
        }

        //char stmp[12];
        string strNum;
        string tmpStr;
        for(int j = 1; j <= 4; j=j+1) {
            tmpStr = s.substr(n, j);
            int ipNum = stoi(tmpStr);
            if (ipNum > 255) {
                continue;
            }

            //itoa(ipNum, stmp, 10);
            //strNum = stmp;
            strNum = std::to_string(ipNum);
            if (strNum.size() != j) {
                continue;
            }

            if (ipStr.empty()) {
                ipTmpStr += tmpStr;
            } else {
                ipTmpStr += ".";
                ipTmpStr += tmpStr;
            }
            recursionIpAddress(ipN+1, lastStr, ipTmpStr, s, n+j);
            ipTmpStr = ipStr;
        }
    }

private: vector<string> rstIps;
};
```