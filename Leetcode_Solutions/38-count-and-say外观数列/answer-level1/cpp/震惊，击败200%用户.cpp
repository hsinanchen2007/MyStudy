### 解题思路
代码如下，思路比较乱，三个循环本以为会超时，没想到啊我个浓眉大眼的也双百了

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string original="1";
        string re=original;
        if(n==1)return original;
        while(--n){
            original=re;
            re="";
            int len=original.size();

            int count=0;
            int i;int j=0;
            for(i=0;i<len;){
                while(i<len){
                    if(original[i]==original[j]){count++;i++;}
                    else break;
                }
                re+=char(count+48);
                re+=original[i-1];
                j=i;
                count=0;
            }
            
        }
        return re;
    }
};
```