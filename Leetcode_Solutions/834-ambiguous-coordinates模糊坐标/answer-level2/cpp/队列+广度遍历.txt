### 解题思路
1、将逗号加入字符串，并加入队列
2、从队列获取字符串，并进行如下操作：
1）字符串合法，加入集合
2）如果横坐标没有包含点号，加入点号，将合法字符串入队
3）如果纵坐标没有包含点号，加入点号，将合法字符串入队

### 代码

```cpp
class Solution {
public:
int isValid(string str){
    int len = str.size();
    if(str.size() > 1){
        if(str[0] == '0' && str[1] != '.')
            return 0;
        if(str[len - 1] == '0' && str.find(".") != str.npos)
            return 0;
    }

    return 1;
}


vector<string> ambiguousCoordinates(string S) {
    if(S.size() < 4)
        return {};

    S = S.substr(1, S.size() - 2);
    queue<string> que;
    set<string> strSet;
    for(int i = 1; i < S.size(); i++){
        string str = S;
        que.push(str.insert(i, 1, ','));
    }

    while(!que.empty()){
        string str = que.front();
        que.pop();
        int pos = str.find(",");
        string str1 = str.substr(0, pos);
        string str2 = str.substr(pos + 1);
        if(isValid(str1) & isValid(str2)){
            strSet.insert("(" + str1 + ", " + str2 + ")");
        }

        if(count(str1.begin(), str1.end(), '.') == 0){
            for(int i = 1; i < str1.size(); i++){
                string str = str1;
                str.insert(i, 1, '.');
                if(isValid(str))
                    que.push(str + "," + str2);
            }
        }

        if(count(str2.begin(), str2.end(), '.') == 0){
            for(int i = 1; i < str2.size(); i++){
                string str = str2;
                str.insert(i, 1, '.');
                if(isValid(str))
                    que.push(str1 + "," + str);
            }
        }
    }

    vector<string> vec(strSet.begin(), strSet.end());
    return vec;
}
};
```