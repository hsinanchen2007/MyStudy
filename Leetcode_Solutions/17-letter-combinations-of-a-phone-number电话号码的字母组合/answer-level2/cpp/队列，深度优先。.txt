### 解题思路
使用队列相当于广度优先搜索，利用队列先进先出的思想。 保存数据，
··先把第一个数字代表的字符存入队列中。
··在依次遍历后续的数字，把队列中的第一个元素和新的字符拼接，并放在队列后面。遍历完一个数字后把队列的第一个值弹出。



深度优先算法还没有搞懂，还使用了数学的方法计算字符，
··首先遍历到最后一位数字，通过for循环拿到最后一个数字代表的字符保存在ret中，
··依次来到倒数第二位数，继续通过for循环，在倒数第二位数代表的字符后面拼接上一步ret中的值。
pos < 3 + (digits[0] - '0' == 9 || digits[0] - '0' == 7  当数字为7,9时字符个数加1.
(digits[0] - '2') * 3 + pos + (digits[0] - '0' > 7) + 'a'  妙啊

### 代码

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> letter = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        vector<string> res;
        queue<string> deq;
        for(int i = 0;i<letter[digits[0]].size();++i){
            string s;
            s.push_back(letter[digits[0]][i]);//把string转化为char。letter[digits[0]][i]取出来的是char不能直接等于string
            deq.push(s);//存入队列中.
        }
        string temp;
        for(int j = 1;j<digits.size();++j){
            int length = deq.size();
            while(length--){ //注意这里必须是length--
                for(int i= 0;i<letter[digits[j]].size();++i){
                    temp=deq.front();
                    temp = temp + letter[digits[j]][i];
                    deq.push(temp);
                }
                deq.pop();
            }
            
        }
        while(!deq.empty()){
            res.push_back(deq.front());
            deq.pop();
        }
        return res;
    }
      


// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗 :6.8 MB, 在所有 C++ 提交中击败了100.00%的用户
    	vector<string> letterCombinations(string digits) {
		if (digits.empty())
			return{};
		vector<string> ret = letterCombinations(digits.substr(1)); //递归到最后一位
		vector<string> ans;
		for (int pos = 0; pos < 3 + (digits[0] - '0' == 9 || digits[0] - '0' == 7); pos++){
			string this_str(1, (digits[0] - '2') * 3 + pos + (digits[0] - '0' > 7) + 'a'); //字符查找
			if (!ret.empty()){
				for (auto str : ret)
					ans.push_back(this_str + str);
			} else{
				ans.push_back(this_str);
            }
		}
		return ans;

	}

};
