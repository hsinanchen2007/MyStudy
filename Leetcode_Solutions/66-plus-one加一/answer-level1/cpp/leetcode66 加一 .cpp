### 解题思路
此处撰写解题思路
代码里写的蛮清楚，我一开始的思路是把当前数字先求出来，先用int，然后爆掉了，又用longlong还是爆掉了，这个时候我才意识到这个题不能这么做，特判即可
### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len=digits.size();
        // 先判断最后一位是不是9
        if(digits[len-1]!=9){
            // 如果不是9，直接最后一位+1输入即可
            digits[len-1]+=1;
        }else{
            // 如果最后一位是9，数一下整个数组中最后有多少个连续的9
            int n=9;
            int cnt=0;
            int p=len-1;
            while(n==9){     
                if(p<0) break;
                n=digits[p];
                if(n==9) cnt++;
                p=p-1;
            }
            //如果连续的9的个数和数组长度相等，也就是说这个数字中每一位都是9
            if(cnt==len){
                //那么这个数字就会变成1000...000的形势
                digits.push_back(0);
                for(int i=0;i<len+1;i++){
                    if(i==0) digits[i]=1;
                    else digits[i]=0;
                }
            }else{
                //不然的话，只需要把连续的9全变成0，然后从最后数第一个不是9个数字加一即可
                int c=0;
                int p1=len-1;
                while(c<cnt){
                    c++;
                    digits[p1]=0;
                    p1--;
                }
                digits[p1]+=1;
            }
        }     
        return digits;
    }
};
```