最近上了学校开设的“数字逻辑与数字系统”课程，知道了格雷码这个概念，就想着应该可以做出这题来。

对于n位二进制序列的格雷码，生成的方法：
首先对前2^n / 2个来编码，从0开始，假设n=3，那么0 = 000，1 = 001等等，
000和它右移一位的结果作异或就可以得到格雷码0000，
1：001 | 000 = 001
2：010 | 001 = 011
3：011 | 001 = 010
前半部分的格雷码为：000 001 011 010
后半部分的格雷码只需要把上面的序列倒个个，再把最高位改成1即可：
110 111 101 100

这道题只需要这样做即可：
1、从0开始生成对应的格雷码
2、找到开始位置
3、变成数组循环移位的问题，可以用3次反转函数来做
```cpp
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        int len = (int)pow(2, n - 1);
        int num = len << 1;
        vector<int> arr;
        for(int i = 0; i < len; i++)  //生成前半部分
            arr.push_back(i ^ (i >> 1));
        for(int i = len - 1; i >= 0; i--)  //生成后半部分
            arr.push_back(arr[i] | len);
        vector<int>::iterator it = find(arr.begin(), arr.end(), start);
        reverse(arr.begin(), it);
        reverse(it, arr.end());
        reverse(arr.begin(), arr.end());
        return arr;
    } 
};
```
只是提供解法，但效率不高。
