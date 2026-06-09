### 解题思路
执行用时 :4 ms, 在所有 C++ 提交中击败了96.85%的用户
内存消耗 :8 MB, 在所有 C++ 提交中击败了100.00%的用户

首先把字母转换为数字，并保证相等数量的字母相加所得之和唯一。
（例如abc的值和任意其他3个字母的值的和不能相等）
这里使用的是斐波那契数列。

然后递归的对字符串进行分解，通过索引来记录当前进行分解的子串（可能用迭代器更好？），以避免多次取得子串时消耗的时间。
一旦得到正确结果将不再对剩余其他的可能性进行分解。

### 代码

```cpp
class Solution {
public:
    string ss1;
    string ss2;
    vector<int> mm={1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10936,17701,28637,46338,74975,121313,196288};
    bool isScramble(string s1, string s2) {
        if(ss1.length()!=ss2.length())return false;
        ss1=s1;
        ss2=s2;
        return check(0,0,ss1.length());
    }
    bool check(int starter1,int starter2,int len){
        if(len==1 && ss1[starter1] == ss2[starter2])return true;
        int sum1=0;
        int sum21=0;
        int sum22=0;
        for(int i=0;i<len-1;++i){
            sum1 +=mm[ss1[starter1+i]-'a'];
            sum21+=mm[ss2[starter2+i]-'a'];
            sum22+=mm[ss2[starter2+len-1-i]-'a'];
            if(sum1==sum21 || sum1==sum22){
                if(sum1==sum21){
                    if(check(starter1,starter2,i+1) && check(starter1+i+1,starter2+i+1,len-1-i))return true;
                }
                if(sum1==sum22){
                    if(check(starter1,starter2+len-1-i,i+1) && check(starter1+i+1,starter2,len-1-i))return true;
                }
            }
        }
        return false;
    }
};
```