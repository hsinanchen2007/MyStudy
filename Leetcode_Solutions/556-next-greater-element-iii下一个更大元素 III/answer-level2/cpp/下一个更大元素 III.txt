
思路：
（1）预期结果是每个个位数字从右到左的升序排列；
（2）从右到左扫描，当不满足升序时，将不满足的那个数字替换为右部比它大的数中最小的那个；
（3）右部从左到右升序排列（原右部逆序）；
（4）左部正常拼接。

注意：
（1）32位整数的显示条件，要以MAX_INT作限制（0x7fffffff）；
（2）int string的相互转换，此处用到stringstream的ss<<int;  int = ss.str,转回来也类似
                          也可以用to_string(n);  long val = stol(str);互转


```C++
#include <sstream>
class Solution {
public:
    int nextGreaterElement(int n) {
        //从右到左（低位到高位）
        //第i位的值要大于前i-1的任意一位，然后加到末尾
        //若不满足，则选取前面中只大一点的填上，剩下的按最小序列排列（大的在低位，小的在高位）

        //实现上：一边遍历就一边生成这样一个序列
        //若找到，则将序列拼接后输出，否则输出-1

        //未考虑到的边界条件，交换后不是32位正整数的情况

        vector<char> small2BigVec;

        //int 2 string
        stringstream ss1;
        ss1 << n;
        string inputStr;
        inputStr = ss1.str();
        ss1.str("");

        small2BigVec.push_back(* inputStr.rbegin());
        string presidentStr;
        bool isFound = false;
        for(int i = inputStr.size()-2; i>=0 ;i-- ){
            if(inputStr[i] >= *small2BigVec.rbegin()){
                small2BigVec.push_back(inputStr[i]);
            }
            else{
                isFound = true;
                //step1:把该位换得稍大一点
                char presidentChar;
                for(int j = 0; j < small2BigVec.size(); j++){
                    if(small2BigVec[j] > inputStr[i]){
                        presidentChar = small2BigVec[j];
                        small2BigVec[j] = inputStr[i];
                        break;
                    }
                }

                //step2:把剩余的低位重排
                    //small2BigVec逆序即可

                //step3:拼接
                presidentStr.append(inputStr,0, i);
                presidentStr += presidentChar;
                for(int j = 0; j < small2BigVec.size(); j++){
                    presidentStr += small2BigVec[j];
                }
                break;
            }
        }

        if(isFound){
            //stringstream ss2;
            ss1.clear();
            ss1 << presidentStr;
            unsigned int resInt;
            ss1 >> resInt;
            ss1.str("");
            if(resInt >= 0x7fffffff){
                return -1;
            }else{
                return resInt;
            }
        }
        else{
            return -1;
        }


    }
};
```








