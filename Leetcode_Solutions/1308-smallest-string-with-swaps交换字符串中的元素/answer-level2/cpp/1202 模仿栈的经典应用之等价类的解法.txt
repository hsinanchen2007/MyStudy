### 解题思路
受到栈应用中的等价类题目的解法的启发，经典例题见书《数据结构算法和应用 C++描述》sartaj sahni中->栈->离线等价类问题，解出来之后发现这样的解法不好理解，出错了不容易找bug，还是分层几个独立的函数比较好。

### 代码

```cpp
//等价类题目
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int len_s = s.size();
        int len_pairs = pairs.size();
        if (len_pairs == 0)
            return s;
        
        stack<int> *list = new stack<int>[len_s];
        int first, second;
        for (int i=0; i<len_pairs; i++) {
            first = pairs[i][0];
            second = pairs[i][1];
            list[first].push(second);
            list[second].push(first);
        }

        //define unprocessedList and out.
        stack<int> unprocessedList;
        bool *out = new bool[len_s];
        for(int i=0; i<len_s; i++)
            out[i]=false;
        
        //找到等价类，调整字符串中的字符位置
        for(int i=0; i<len_s; i++){
            if(!out[i] && !list[i].empty()){
                out[i]=true;
                unprocessedList.push(i);
                
                int temp;
                vector<int> changeList; //存储字符串s中可交换的字符索引
                while(!unprocessedList.empty()){
                    temp=unprocessedList.top();
                    unprocessedList.pop();

                    while(!list[temp].empty()){
                        int j = list[temp].top();
                        list[temp].pop();
                        changeList.push_back(j);
                        if(!out[j]){
                            out[j]=true;
                            unprocessedList.push(j);
                        }                       
                    }
                }

                //将changeList中元素对应的字符取出存在changeValue中并从小到大排序
                //注意：changeList中可能有重复元素，重复元素只用一遍。
                sort(changeList.begin(), changeList.end());
                vector<char> changeValue; //char型
                int len_changeList=changeList.size();
                int temp_value=-1;
                for(int i=0; i<len_changeList; i++){
                    if(changeList[i] > temp_value){
                        temp_value=changeList[i];
                        changeValue.push_back(s[temp_value]);
                    }
                        
                }
                sort(changeValue.begin(), changeValue.end()); //sort可用于排序char型数据
                temp_value=-1;
                int flag=0;
                for(int i=0; i<len_changeList; i++){
                    if(changeList[i] > temp_value){
                        temp_value=changeList[i];
                        s[changeList[i]] = changeValue[flag];
                        flag++;
                    }
                        
                }
            }
        }
        return s;
    }
};
```