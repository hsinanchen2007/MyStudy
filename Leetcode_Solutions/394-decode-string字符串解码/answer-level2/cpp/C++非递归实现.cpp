双栈实现比单栈实现更容易理解，也更简单，只是借助栈的性质，不以栈来循环，不需要判断栈空的情况，只需要遍历一次字符串就可以了
一个栈用于保存累加的数字，一个栈保存累加的字符串，而不是字符。

    
string decodeString(string s) {//保存字串
 	stack<string> codeStack;
	stack<int> numsStack; //保存数字
	string res = "";
	int num = 0;

	for (int i = 0; i < s.length(); i++)
	{
        //1。遇到[的时候，将前面数字压栈
        //2。遇到]的时候，将数字弹出，将收集到的字符串按数字累加，交上一轮的数字处理
        if(s[i] >='0'&&s[i]<='9') //是数字的时候，要记录累加是几位数字
        {
            num = num*10 +s[i] -'0';  //如果是连续的数字，要累加
        }
        else if((s[i] >= 'a'&& s[i] <= 'z') || (s[i] >='A' && s[i]<='Z')) //是字母的时候，累加入到res
        {
            res+=s[i];
        }
        else if(s[i] == '[')   //将前面的数字入栈，将收集到的字符串入栈
        {
            numsStack.push(num);
            num = 0;//清零，准备下一次记录
            codeStack.push(res);
            res="";
        }
        else if(s[i] == ']')//此时应该就是]了
        {
            int times = numsStack.top();
            numsStack.pop();
            for(int i = 0;i<times;i++)  //按数字累加收集到的字符串
            {
                codeStack.top()+=res;  ///栈顶元素这里可以直接相加。。。
            }
            res = codeStack.top();  //累加后的字符串取出来，下一轮循环，取数字再用
            codeStack.pop();
        }
        else
        {
            {
                //出错了，非法字符
                return "";
            }
        }       
	}
	return res;
    }