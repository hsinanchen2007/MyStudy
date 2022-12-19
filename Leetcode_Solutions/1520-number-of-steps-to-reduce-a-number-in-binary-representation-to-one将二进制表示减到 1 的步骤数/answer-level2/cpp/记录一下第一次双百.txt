### 解题思路
就直接按照题目的意思的进行操作了 还是小白 不要嫌弃我~_~

### 代码

```cpp
class Solution {
public:
    int numSteps(string s) {
        int ret = 0;    //步骤的次数
        while(true){
            if(s=="1")      //当结果为1时，结束循环
                break;

             //获取最末尾，根据二进制的最末尾判断是奇数还是偶数
            char rear = s[s.size()-1]; 
            //当偶数时，将二进制向右移一位（相当于除以2），也就是删除最末位
            if(rear=='0'){
                s.erase(s.end()-1);     
            }else{
                //当为奇数时（末位为1），进行+1操作
                int carry = 1;
                for(int i=s.size()-1;i>=0;i--){
                    s[i] += carry--;
                    if(s[i]=='2'){
                        s[i] = '0';
                        carry = 1;
                    }else{
                        //当不再进位时，即可停止
                        break;
                    }
                }
                //当到最高位时，如果还有进位，需添1
                if(carry==1){
                    s = '1'+s;
                }
            }
            ret++;
        }
        return ret;
    }
};
```