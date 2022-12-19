### 解题思路
    因为find函数只能限制开始找的位置，并找到字符串尾部，所以双指针从后往前
    一个指针指向无重复字符串开始位置，一个指向结束位置
    一次向前读入一个字符，判断后面有无该字符并在不在双指针范围内

    找到并在范围内更新右指针指向重复字符的左边一个字符
    没找到或不在范围内更新字符串的长度
    
### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0) return 0;
        int end=n-1;
        int count=0;
        for(int i=n-2;i>=0;--i){
            int temp=s.find(s[i],i+1);
            if(temp<=end&&temp>0){
                end=temp-1;
            }else{
                count=count>end-i? count:end-i;
            }
        }
        return count+1;
    }
};
```