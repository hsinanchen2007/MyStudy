C++解题 **模拟栈+swicth+ascII**
符号(+, -, *, /)前面必有俩数，通过toTop指针把俩个数运算赋值给第一个数，最后第一个数为返回值。
使用if elseif else嵌套效率没有swicth高。 


~~~C++
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> toNums(tokens.size(), 0);
        int toTop = -1;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                int n = atoi(tokens[i].c_str());
                toTop++;
                toNums[toTop] = n;
            }else{
                toTop++;
                //char to = tokens[i][0];
                char *to = (char*)tokens[i].c_str();
                switch(*to){
                    case 43 :
                        toNums[toTop-2] = toNums[toTop-2] + toNums[toTop-1];
                        toTop -= 2;
                        break;
                    
                    case 45 :
                        toNums[toTop-2] = toNums[toTop-2] - toNums[toTop-1];
                        toTop -= 2;
                        break;
                    
                    case 42 :
                        toNums[toTop-2] = toNums[toTop-2] * toNums[toTop-1];
                        toTop -= 2;
                        break;
                    
                    case 47 :
                        toNums[toTop-2] = toNums[toTop-2] / toNums[toTop-1];
                        toTop -= 2;
                        break;

                }
            }
        }
        return toNums[0];
    }
};
~~~