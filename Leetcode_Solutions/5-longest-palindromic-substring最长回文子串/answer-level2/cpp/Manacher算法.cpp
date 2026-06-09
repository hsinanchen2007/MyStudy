### 解题思路
先将字符串加‘#’处理，以统一奇偶判定问题，设置最大回文半径数组pArr，最大回文右边界pR，以及最大回文右边界对应的中心对称点index，根据i与L...index...R的相对位置关系分类，实际上加速了对比扩展的过程。

### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(len == 0) return "";
        string sexp = "";
        int index = 0;
        for(int i = 0; i < 2*len + 1; i++){
            sexp += (i&1)==0 ? '#' : s[index++]; 
        }
        int lenexp = 2*len + 1;
        //pArr[i]代表以i为中心，扩出去的最大回文半径值
        int* pArr = new int[lenexp];
        //pR代表之前遍历的所有回文半径中，最右即将到达的位置
        int pR = -1;
        for(int i = 0; i < lenexp; i++){
            //i在pR外时，半径先置为1，然后需要继续往两边扩
            //i在pR内时，首先找到i关于index的对称点i',i'==2*index-i,分为三种情况：
            //  1.i'的回文半径在L...index...R内部，即没超过L，此时pArr[i] == pArr[i']
            //  2.i'的回文半径在L...index...R外部，即超过了L，此时pArr[i] == pR - i，因为再往外扩就不再是i'的回文范围了
            //  3.i'的回文半径正好压在边界上，即正好在L上，此时因为L外和R外的字符并未考察过，所以pArr[i]至少是pArr[i']，但仍             //  需往外扩
            //  综合2和3，pArr[i]需要取pArr[i']和pR-i的最小值，然后继续往外扩
            pArr[i] = pR > i ? min(pArr[2*index-i], pR-i) : 1;
            //往外扩
            while(i+pArr[i] < lenexp && i-pArr[i] > -1){//不越界
                if(sexp[i+pArr[i]] == sexp[i-pArr[i]]){
                    pArr[i]++;
                }else{
                    break;//对于1和2来说，第一次就break了，所以这样写为了方便统一
                }
            }
            if(i+pArr[i] > pR){
                pR = i + pArr[i];
                index = i;
            }
        }
        //找到pArr中的最大值，以及最大值对应的坐标
        int maxVal = INT_MIN; 
        int maxIndex = 0;
        for(int i = 0; i < lenexp; i++){
            if(maxVal < pArr[i]){
                maxVal = pArr[i];
                maxIndex = i;
            }
        }
        string res = "";
        for(int i = maxIndex-maxVal+1; i <= maxIndex+maxVal-1; i++){
            if(sexp[i] != '#'){
                res += sexp[i];
            }
        }
        return res;
    }
};
```