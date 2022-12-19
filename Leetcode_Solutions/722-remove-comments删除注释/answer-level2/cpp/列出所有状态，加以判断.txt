
![image.png](https://pic.leetcode-cn.com/fb4fb70ea5151300f280ce8d7bde8faf46d0408b65040ef4dbcecef4edc71696-image.png)

### 解题思路
#### 注释大概分如下几类：

```cpp
// 注释一

/* 注释二 */

a = b + c; // 注释三

/* .........
...注释四...
...........*/

a = b + c; /* .....
.......注释五.。.....
....*/ if (b == c)

```

### 代码

```cpp
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> result; // 用来存储最后的返回结果
        vector<string> temp; // 用来存储每一行处理后的结果
        string del = "false"; // 标记一下是否处于注释block中
        string head; // 考虑到上述注释五的情况，所以这个变量用于拼接
        for (auto s: source){ // 遍历每一行
            temp = check(s, del); // 执行检查函数，返回向量，向量[0]是del标记， 向量[1]是处理好的代码字段
            if (temp[1] != ""){  // 如果返回不是空字符串
                if (del == "true" && result.size() > 0){ // 判断一下，是否是注释五的情况，是的话
                    temp[1] = result[result.size()-1] + temp[1]; // 进行字符串拼接
                    result[result.size()-1] = temp[1]; // 更新result向量
                } else { // 否则
                    result.push_back(temp[1]); //直接加到result向量后
                }
                head = temp[1]; // 更新一下下一次需要拼接的字符串
            }
            del = temp[0]; // 更新注释block标记
        }   
        return result;
    }
private:
    // 检查函数，列出所有情况，直接判断逻辑，即可（其实大体只有两种，// 和/*） 
    vector<string> check(string st, string del){
        string _del = del;
        vector<string> ret;
        string result = "";
        
        for (int i=0; i<st.size(); i++){
            if (_del == "true") { 
                if (st[i] == '*' && st[i+1] == '/'){
                    _del = "false"; i++;
                }
            } else if (st[i] == '/' && st[i+1] == '/'){
                    ret.push_back(_del);
                    ret.push_back(result);
                    return ret;
            } else if (st[i] == '/' && st[i+1] == '*'){
                    _del = "true"; i++;
            }else {
                 result += st[i];
            }
        }
        ret.push_back(_del);
        ret.push_back(result);
        
        
        return ret;
    }
};
```