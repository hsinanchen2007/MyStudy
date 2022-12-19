### 解题思路

给爷整蒙了，开始完全想不到怎么写。
主要分成两个步骤。
1.往栈或者list里加数据。这里只加字母，遇到..就把之前的字母弹出来。，
2.把栈或者list里的数据拿出来放到res里。  栈需要反转。list不用。

用的时间是差不多的。


### 代码

```cpp
class Solution {
public:
    // 执行用时 :12 ms, 在所有 C++ 提交中击败了53.73% 的用户
    // 内存消耗 :8.1 MB, 在所有 C++ 提交中击败了100.00%的用户
    string simplifyPath(string path) {
        string res;
        if(path.size()==0) return res;
        stack<string> temp;
        string str;
        path += '/';//必须要加一个'/'表示结束符
        for(auto p: path){
            if(p=='/'){//'/'表示一个结束符
                if(str==".."&&!temp.empty()){//若str里记录的值为..就把temp中的值弹出。
                    temp.pop();
                }
                if(str!=".."&&str!="."&&!str.empty()){//若str里记录有值且不为..和.
                    temp.push(str);
                }
                str.clear();//把str清空
            }
            else{//p为字母就把它放到str中
                str += p;
            }
        }
        while(!temp.empty()){//现在开始弹出。
            auto s = temp.top();
            res += string(s.rbegin(), s.rend()) + '/';//这里要把弹出的string反着放到res中。因为先弹出来的是最后的
            temp.pop();
        }
        reverse(res.begin(), res.end());//因为弹出的字符串顺序是反的，所以要转回来，
        if(res.empty()) return "/";//如果res里没有值。就要返回一个/
        return res;

    }



    // 执行用时 :12 ms, 在所有 C++ 提交中击败了53.73% 的用户
    // 内存消耗 :8 MB, 在所有 C++ 提交中击败了100.00%的用户
    string simplifyPath(string path) {
        string res;
        if(path.size()==0) return res;
        list<string> temp;
        string str;
        path += '/';//必须要加一个'/'表示结束符
        for(auto p: path){
            if(p=='/'){//'/'表示一个结束符
                if(str==".."&&!temp.empty()){//若str里记录的值为..就把temp中的值弹出。
                    temp.pop_back();
                }
                if(str!=".."&&str!="."&&!str.empty()){//若str里记录有值且不为..和.
                    temp.push_back(str);
                }
                str.clear();//把str清空
            }
            else{//p为字母就把它放到str中
                str += p;
            }
        }
        while(!temp.empty()){//现在开始弹出。
            auto s = temp.front();
            res += '/' + s;
            temp.erase(temp.begin());
        }
        
        if(res.empty()) return "/";//如果res里没有值。就要返回一个/
        return res;
    }

};
```