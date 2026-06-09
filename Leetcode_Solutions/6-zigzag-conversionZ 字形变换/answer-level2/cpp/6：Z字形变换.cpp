- **思路分析**
1. 观察规律发现，每个Z字形是按照T=（numRows！=1）？（numRows-1）*2 : 1的规律变化。
2. 希望能够按照行的思路来处理，所以加入一个代表行数的中间变量orderInt
    0     0+T
    1  3  1+T ...
    2     2+T
3. 根据行数依次填入该行应该存放的所有字符

- **复杂度**
    两重循环实现对字符的长度n的一次遍历，时间复杂度：θ（n）
    执行时间为12ms


- **代码实现**
```
class Solution {
public:
    string convert(string s, int numRows) {
        const int T = (numRows==1)? 1:(numRows-1) * 2;//周期数，递归式，注意行数为0时的周期
        string str;
        for(int orderInT = 0; orderInT <= T/2; ++orderInT)//以周期数往前迭代
            for(int i = 0; i+orderInT<s.length(); i=i+T){//插入每一行的元素
                str += s[i+orderInT];
                if(orderInT != T/2 && orderInT%T !=0 &&  (i+T-orderInT)<s.length() )//插入每一周期内的另一个元素，同时注意对最底下元素不要重复了，比如题目中的EDHN
                    str += s[i+T-orderInT];
            }
        return str;
    }
};
```

