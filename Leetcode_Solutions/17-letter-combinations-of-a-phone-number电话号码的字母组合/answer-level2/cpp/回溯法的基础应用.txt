### 解题思路
回溯法，关键是要建立递归思想：
    递归三要素：

            1.递归信心：虽然还没有写出具体的函数执行过程，但要相信此函数能解决子问题。
                       不必太过纠结递归具体执行的出栈入栈过程。
                       如首先定义并且相信generateStringsByDFS函数能生成字符串从下标start开始的子串。

            2.递归出口：当下标start等于字符串长度时，递归结束并将字符串放进Vector中。

            3.递归项：将要解决的问题拆分为本次函数执行的操作和相同的子问题。
                     本题中即为先向myString尾部添加相应字符再调用generateStringsByDFS通过剩余digits部分
                     生成子串。

            ps. 回溯法在循环体递归调用时注意要还原与后续操作有关的变量：
                本题中generateStringsByDFS函数myString为引用变量，
                递归调用后会改变myString的值，在进行下一次循环时要先进行还原。
                     

### 代码

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        std::vector<string> ans;
        if(digits.empty()) return ans;
        string myString="";
        generateStringsByDFS(digits,0,digits.size(),ans,myString);
        return ans;
    }

    void generateStringsByDFS(string digits,int start,int length,vector<string>& myVector,string& myString){
        if(start==length){
            myVector.push_back(myString);
            return;
        }
        else{
            int i,n;
            char myChar=digits.at(start);
            string save=myString;
            if(myChar>=55&&myChar!='8')n=4;
            else n=3;
            for(i=0;i<n;i++){
                if(n==3&&myChar<55) myString+=string(1,char(myChar*3-53+i));
                else if(myChar=='7') myString+=string(1,char(112+i));
                else if(myChar=='8') myString+=string(1,char(116+i));
                else myString+=string(1,char(119+i));
                generateStringsByDFS(digits,start+1,length,myVector,myString);
                myString=save;
            }
        }
        return;

    }
};
```