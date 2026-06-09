### 解题思路
此处撰写解题思路
将每找到一对相同的字符，长度加2，在最后遍历整个数组，有多的一个字符则长度加1然后跳出循环。
### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(58,0);
        int sum=0;
        for(char ss:s){
            count[ss-'A']++;
            if(count[ss-'A']%2==0){
                sum+=2;
                count[ss-'A']=0;
            }
        }
        for(int i=0;i<count.size();i++){
            if(count[i]==1){
                sum++;
                break;
            }
        }
        return sum;
    }
};
```