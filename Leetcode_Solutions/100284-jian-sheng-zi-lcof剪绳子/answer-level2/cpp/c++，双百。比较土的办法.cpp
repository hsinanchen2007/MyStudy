### 解题思路
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :7.9 MB, 在所有 C++ 提交中击败了100.00%的用户

没有什么特别的思路，脑子一想最大肯定是平均数，然后有余数的话在平均数分的加1就好了。比如10分三份，平均每份是3，余下的1随便加一个就好了。m是分成几份。偷懒排序用了vector数组，这个vector不是很会用，也许不用生成58个空间
### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        vector<int> num(58);
        
        for(int m=2;m<=n;m++)
        {
            int k=0;
            int y=0;
            k=n/m;
            y=n%m;
          
            num[m]=pow(k,m-y)*pow(k+1,y);


        }
        sort(num.begin(),num.end());
        return num[57];


    }
};
```