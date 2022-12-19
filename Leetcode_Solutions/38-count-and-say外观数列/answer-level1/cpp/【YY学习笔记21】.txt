### 解题思路
如题所描述，当n=2,字符串更新了1次；n=3,字符串更新了2次；n=4，字符串更新了3次。
双重循环暴力求解：外层循环表示更新的次数，内层表示一次更新后的结果。
### 知识点
**1.string的插入函数**
·······str.push_back('A')或str.push_back(65)——在str末尾添加一个字符  'A' ，参数必须是字符形式。（65是'A'的ASCII码）
·······str.append("ABC")——在str末尾添加一个字符串 "ABC"，参数必须是字符串形式。
### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        //后一项为对前一项的描述:n=2,更新了1次；n=3,更新了2次；n=4，更新了3次。
        if(n==1) return "1";//错误点1：返回一个字符串而不是'1'。
        string a1;
        string a2;
        string tmp;
        int i=0,j=0;
        a1.push_back('1');//错误点2：对于a1.push_back('A');
        //一、总循环次数
        for(i=1;i<n;++i){
            int num=1;
            j=0;//错误点3：忘记置0。
            //二、单次循环
            while(j<a1.size()-1){
                 if(a1[j]==a1[j+1]){
                     num++;
                     j++;
                 }
                 else{
                     //压入新的vector
                     a2.push_back(num+'0');//错误点4：忘记+'0'。
                     a2.push_back(a1[j]);

                     num=1;
                     j++;
                 }
            }
            //把结尾的元素压入新的vector。
            a2.push_back(num+'0');
            a2.push_back(a1[j]);

            a1=a2;
            a2.clear();  
        }
        return a1;
    }
};
```