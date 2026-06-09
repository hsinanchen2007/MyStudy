## 解法一：基于长度奇偶分解的双指针解法
首先将回文情况分为长度为奇偶的情况，并分开考虑。

由于对象是回文，所以需要充分利用回文对称的性质。如果采用暴力破解法，会出现很多没必要的比较。
这里采用一点小技巧：如果之前已经确定了以之前位置中的字符为中心的回文长度中的最大值，那么实际上只需要先在当前位置中判断是否有比当前最大长度+2的回文更长的回文。并且这个判断的思路是利用一个对称指针，从外向内判断两个指针所指向字符是否一致，如果判断不一致，则进行下一个位置的判断，否则，则在当前位置的字符为中心的字符串中存在一个比之前找到的最大长度回文更长的回文。之后再往外拓展来更新更长的回文字符长度。

只需要将奇偶长度进行分开处理即可。

```c++
class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        int left=0, right=size-1; int flag=0;

        int odd_Max_Len = 1; int odd_interval = (odd_Max_Len-1)/2; int odd_Max_inx = 0;
        int even_Max_Len = 0; int even_interval = (even_Max_Len)/2; int even_Max_inx = 0;

        // odd traveling
        for(int i=0; i<size; i++){
            odd_interval = (odd_Max_Len-1)/2;
            left=i-odd_interval-1; right=i+odd_interval+1;
            flag = 0;
            if(left<0) continue;
            if(right>=size) break; // 因为index是递增的

            for(int j=0; j<odd_interval+1; j++){
                if(s[left+j]!=s[right-j]){
                    flag=1; break;
                }
            }
            if(flag) continue;  // 当前最大长度下不为回文
            else{   // 当前最大长度下为回文，此时此时可以更新最大长度
                odd_Max_Len+=2; left--; right++; odd_Max_inx=i;
                while(left>=0 && right<size){
                    if(s[left]!=s[right]) break;
                    odd_Max_Len+=2;
                    left--; right++;
                    //cout << left << right << odd_Max_inx << odd_Max_Len<< endl;
                }
            }
        }
        int Evenflag=0;
        for(int i=0; i<size; i++){
            if(s[i]==s[i+1]) {Evenflag=1; even_Max_Len=2; even_Max_inx=i; break;}
        }
        if(Evenflag){
            // even traveling
            for(int i=0; i<size-1; i++){
                if(s[i]!=s[i+1]) continue;  // 首先要满足两个相邻元素相等
                even_interval = (even_Max_Len-2)/2;
                left=i-even_interval-1; right=i+even_interval+2;
                flag = 0;
                if(left<0) continue;
                if(right>=size) break; // 因为index是递增的

                for(int j=0; j<even_interval+1; j++){
                    if(s[left+j]!=s[right-j]){
                        flag=1; break;
                    }
                }
                if(flag) continue;  // 当前最大长度下不为回文
                else{   // 当前最大长度下为回文，此时此时可以更新最大长度
                    even_Max_Len+=2; left--; right++; even_Max_inx=i;
                    while(left>=0 && right<size){
                        if(s[left]!=s[right]) break;
                        even_Max_Len+=2;
                        left--; right++;
                    }
                }
            }
        }
        //cout << odd_Max_Len << odd_Max_inx << endl;
        //cout << even_Max_Len << even_Max_inx << endl;
        string ans;
        if(odd_Max_Len>=even_Max_Len) {
            ans = getOddAnsString(s, odd_Max_inx, odd_Max_Len);
        }
        else ans = getEvenAnsString(s, even_Max_inx, even_Max_Len);
        
        return ans;
    }

    string getOddAnsString(string s, int index, int len){
        char ans[len+1]; ans[len] = '\0';
        int left=index - ((len-1)/2);
        for(int i=0; i<len; i++){
            ans[i] = s[left+i];
        }
        string Sans = string(ans);
        return Sans;
    }

    string getEvenAnsString(string s, int index, int len){
        char ans[len+1]; ans[len] = '\0';
        int left=index - len/2 + 1;
        for(int i=0; i<len; i++){
            ans[i] = s[left+i];
        }
        string Sans = string(ans);
        return Sans;
    }
};
```
## 动态规划解法
这一题可以理解为一个填表问题。维护一个bool 二维数组DP，DP[i][j]表示的是string s中的索引[1,j]区间内的字符串是否为回文。通过列出动态转移方程：
$$DP[i][j] = s[i]==s[j] && DP[i+1][j-1];$$
而动态规划最大的特点就是充分利用已有计算结果，避免冗余计算。所以有上述状态转移方程可知在求解DP[i][j]时希望存在DP[i+1][j-1]，所以如果将DP画成一个表，可发现，当DP[i+1][j-1]的位置处于DP[i][j]的左下角。所以希望填表的过程中，可以在填写当前单元格时，其左下角单元格已填写完毕。
同时可以确定base case: DP[i][i]=true; 
由上述分析可知，填表的顺序是至关重要的。由于希望填表的过程中，可以在填写当前单元格时，其左下角单元格已填写完毕，所以正确的填表顺序应该是沿着对角线方向，从主对角线出发，不断地向右上方填写。
