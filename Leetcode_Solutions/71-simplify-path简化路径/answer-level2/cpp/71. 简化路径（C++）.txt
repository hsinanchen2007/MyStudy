# 71. 简化路径

**思路：**
- 本题主要是将传入的路径字符串进行化简输出操作。
- 可以利用栈的先进先出原则，将每一步路径操作看为对于栈的操作，从而得到化简后的路径。
- 创建一个字符串栈存放单步路径信息`stack<string> m_stack;`
- 然后遵循以下规则：
    1. 首先需要将传入的字符串进行分割，依照"/"分割出子单步路径字符串。（由于C++好像没有split函数，需要遍历每个字符进行判断）；
    2. 获得单步路径字符串后需要对该字符串进行数值判断：
	`单步路径字符串 == "."`    不进行操作
	`单步路径字符串 == ""`   不进行操作
	`单步路径字符串 == ".."` 如果栈中为空，不进行操作。不为空时出栈一个元素。
	`其他情况`               将单步路径字符串入栈。

    3. 经过上一步，完成对于路径的逻辑判断和化简，只需要将栈中元素循环添加到结果字符串首部即可
    4. 返回结果字符串。

**完整代码：**

```
class Solution {
private:
	stack<string> m_stack;
public:
	//单步路径判断函数
	void substr2stack(string substr){
		if(substr == "."){
			return;
		}else if(substr == ".."){
			if(m_stack.empty()){ 
				return;
			}else{  
				m_stack.pop();
			}
		}else{
			m_stack.push(substr);
		}
		return;
	}
	
    string simplifyPath(string path) {
		string substr;	//保存path中分从'/'离出的字符串
        for(char item : path){
			if(item == '/'){
				if(!substr.empty()){
					substr2stack(substr);
					substr.clear();
				}
			}else{
				substr.push_back(item);
			}
		}
		if(!substr.empty()){
			substr2stack(substr);
			substr.clear();
		}
		
		string rst;
		if(!m_stack.empty()){
			while(!m_stack.empty()){
				rst.insert(0,m_stack.top());
				rst.insert(0,"/");
				m_stack.pop();
			}
		}else{
			rst = "/";
		}
		
		return rst;
    }
};
```
