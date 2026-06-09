### 解题思路

只有我一个人用的是字典序的思路吗23333

![Snipaste_2020-04-01_13-35-06.png](https://pic.leetcode-cn.com/ca427f4e6e897a4d5efa1b39418ad753841a3c4cad4af18a496d1a3de70d4677-Snipaste_2020-04-01_13-35-06.png)

这个结果还是不错的~

**字典序的定义**

n个元素{1，2，…， n }有n！个不同的排列。将这n！个排列按字典序排列，并编号为0，1，…，n！- 1。每个排列的编号为其字典序值。例如，当n=3时，6 个不同排列的字典序值如下：

`字典序值 0 1 2 3 4 5
排 列 123 132 213 231 312 321`

**物理含义**

6个数字从左到右依次增大的。

**字典序的实现**

字典序法是由当前序列直接生成下一个排列的算法：排列定义：P = P0，P1，P2，…，Pn-1

第一步：求满足关系式P(k-1)<P(k)的k的最大值，设为i，即

`i = max{k|P(k-1)<P(k)}`

第二步：求满足关系式P(i-1)<P(k)的k的最大值，设为j，即

`j = max{k|P(i-1)<P(k)}`

第三步：P(i-1)与P(j)互换。

第四步：把序列中P(i)P(i+1)```P(n-1)顺序逆转。

**字典序的实例**

`对于1243，可知 i = 2，j = 3 。P(1)与P(3)交换得1342，再将42逆转可得下一个排列1324 ；`

### 代码

```cpp
class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> vec;
        sort(begin(s),end(s));
        string end_str=s;
        reverse(end_str.begin(),end_str.end());
        while(s.compare(end_str)!=0){
            vec.push_back(s);
            s=next_permutation(s);
        }
        vec.push_back(s);
        return vec;
    }

    string next_permutation(string s){
        int i,j;
        //第一步
        for(int k=1;k<s.length();++k)
            if(s[k]>s[k-1])
                i=k;
        //第二步
        for(int k=i;k<s.length();++k)
            if(s[k]>s[i-1])
                j=k;
        //第三步
        char temp=s[i-1];
        s[i-1]=s[j];
        s[j]=temp;
        //第四步
        reverse_str(s,i,s.length()-1);
        return s;
    }

    void reverse_str(string &s,int start,int end){
        while(start<end){
            char temp=s[start];
            s[start]=s[end];
            s[end]=temp;
            start++;
            end--;
        }
        return;
    }
};
```