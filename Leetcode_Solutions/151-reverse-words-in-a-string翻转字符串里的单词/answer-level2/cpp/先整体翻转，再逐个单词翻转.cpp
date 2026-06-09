1. 整体翻转
2. 将翻转后的字符串按空格分割，分割的字符串存在vector中
3. 逐个从vector中取出每个单词再次翻转，并将单词连起来
```
string reverseWords(string s) {
    string rev; 
    reverse(s.begin(), s.end());
    vector<char*> S; //存按空格分割的字符串

    char* tempS = new char[s.size() + 1];
    strcpy(tempS, s.c_str());  //分割时为char*,在此需要转一下
    
    //按空格分割并存储
    char* ptr = strtok(tempS, " ");
    while(ptr != nullptr){
    	S.push_back(ptr);
    	ptr = strtok(nullptr, " ");
    }

    for(int i = 0; i < S.size(); i++){
    	string temp = S[i];
    	reverse(temp.begin(), temp.end());
    	if(i > 0) rev += ' ';
        rev += temp;
    }
	
    return rev;
}
```
![151.翻转字符串里的单词.png](https://pic.leetcode-cn.com/1c874f93cf907340c3dfae852691f37a99e019f39d4a1b3d42df0a7ac82d958a-151.%E7%BF%BB%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2%E9%87%8C%E7%9A%84%E5%8D%95%E8%AF%8D.png)
