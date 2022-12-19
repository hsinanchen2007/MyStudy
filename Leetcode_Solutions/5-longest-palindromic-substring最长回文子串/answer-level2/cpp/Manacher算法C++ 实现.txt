### 解题思路
Manacher算法核心思想：
1. 扩展插入字符，这不不需要真实做，因为扩展后偶数位都是对称的。用一个扩展后大小的数组保存每一位的对称半径即可。
2. 确定当前回文最右边际mx,和中心ID
3. 获得对称的半径长度和里mx距离的较小者，再向两边扩散
### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<=1){
            return s;
        }
        int len = s.length();
        vector<int> p(len*2+1, 1);
        int size = p.size();
        
        int maxlen = 0;
        int maxi = 0;
        
        int id = 0;
        int mx = 1;

        for(int i= 1; i<size; i++){
            p[i] = i<mx ? min(p[2*id-i], mx-i):1;
            while((i-p[i])>=0 &&(i+p[i])<size ){
                if((i-p[i])%2!=0 && s[(i-p[i])/2]!=s[(i+p[i])/2]){
                  break;
                }              
                 p[i]++;
            }
            if(p[i]+i > mx){
                mx = p[i] + i;
                id = i;
            }
            if(p[i]>maxlen){
                maxlen = p[i];
                maxi = i;
            }
        }
        maxlen -= 1;
        int start = (maxi-maxlen)/2;
        return s.substr(start, maxlen);
    }
};
```