![image.png](https://pic.leetcode-cn.com/7f5dfcdd742f26b635915ef844ac3e031e780d5701993e0f17b3e9ab01197d91-image.png)

```
class Solution {
public:
    string countOfAtoms(string formula) {
        int L = formula.length();
        // "" / H / Mg / H2
        if(L<=2) return formula;
        
        map<string,int> myMap;
        stack<int> timeS;       //存储当前倍数
        string tempName = "";
        string tempNum = "";
        
        //逆向搜索 - 便于计算倍数
        for(int i=L-1;i>=0;i--){
            //遇到'('释放一个倍数
            if(formula[i]=='('){
                if(!timeS.empty())
                    timeS.pop();
            //遇到')'记录倍数
            }else if(formula[i]==')'){
                if(tempNum != ""){
                    // 若不为空，则当前倍数 = 前一项倍数 * 当前数字
                    if(!timeS.empty()){
                        int time = timeS.top();
                        timeS.push(time * stoi(tempNum));
                    }else{
                        timeS.push(stoi(tempNum));
                    } 
                    tempNum = "";
                }
            }else if(isdigit(formula[i])){
                tempNum = formula[i] + tempNum;
            }else{
                // 遇到字母，先记录近当前名字
                tempName = formula[i] + tempName;
                // 若为大写，则记录原子信息
                if(formula[i]>='A' && formula[i]<='Z'){
                    if(myMap.find(tempName) == myMap.end())
                        myMap.insert(make_pair(tempName,0));
                    
                    // 计算当前原子的增加数量
                    int num = tempNum == "" ? 1:stoi(tempNum);
                    if(!timeS.empty())
                        num *= timeS.top();
                    myMap[tempName] += num;
                    
                    // 初始化当前名字 & 当前数量
                    tempName = "";
                    tempNum = "";
                }
            }
        }
        
        // output result
        string res = "";
        for (auto &item : myMap) {
			res += item.first;
			if (item.second > 1) {
				res += to_string(item.second);
			}
		}
        
        return res;
    }
};
```

最终运行结果：
![image.png](https://pic.leetcode-cn.com/a773f1ebcf3b6e00da253bad1311d0f60c8c39d94d75a295f6a76130bd1d9c08-image.png)

