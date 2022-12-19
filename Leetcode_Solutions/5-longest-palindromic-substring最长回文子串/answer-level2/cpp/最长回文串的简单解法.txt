### 解题思路
思路：这题暴力解法思路就是从头往后遍历数组，因为回文数组会存在奇数个和偶数个的差别，所以定义一个double类型的i值，用i来计数，count和count1分别是用来存储当前回文的个数和最大回文个数。

难点：double类型和int类型的转换，偶数个和奇数个回文的判断

部分细节：每次i增加0.5可以解决奇数或偶数个判断的问题
         二次循环有个很麻烦的地方就是x和y在内层循环结束后比你想象的会小一或大一，这是for的一个比较
麻烦的地方，不过解决不算太难，值得注意。

效率：时间复杂度O(n^2),空间复杂度（1），时间复杂度我觉得要是不算太极端的情况达到（c*n)是没问题的

### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
         int x1=0;
         int count=0;
         int count1=0;
         if(s.length()<2)return s;
         else if(s.length()==2&&s[0]==s[1])return s;
         else{
             for( double mid=0.5;mid<=s.length()-1;mid+=0.5){
                  int x=mid-0.5;
                  count=mid-x;//此处确保count的值符合奇偶数不同的情况
                  int y=mid+1;
                 for(;x>=0&&y<s.length();x--,y++){
                   if(s[x]!=s[y])break; 
                   else  count+=2;
                 }
                 x++;
                 y--;
                 if(count>count1){
                       x1=x;
                       count1=count;
                   }
             }
         }
         return s.substr(x1,count1);
    }
};
```