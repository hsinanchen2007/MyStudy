```
string removeDuplicateLetters(string s) {
        unordered_map<char, int> tag; //记录字符出现次数
        unordered_map<char, bool> visited; //记录字符是否被访问

        //初始化tag和visited
        for(char ch : s){
            if(tag.find(ch) != tag.end()){
                tag[ch]++;
            }else{
                tag.insert(make_pair(ch,1));
                visited.insert(make_pair(ch, false));
            }
        }

        string result = "0"; //初始化方便处理 否则操作result.back()需要讨论result为空的情形
        for(char ch : s){
            tag[ch]--; //更新剩余子串字符ch出现次数
            if(visited[ch]) continue;
            while(result.back() > ch && tag[result.back()]){ //字符串不满足字典序
                visited[result.back()] = false;
                result.pop_back();
            }
            result += ch; //贪心算法的体现——尽可能多吃下字符
            visited[ch] = true; 
        }
        return result.substr(1); //和初始化时，填充了1位字符对应
    }
```