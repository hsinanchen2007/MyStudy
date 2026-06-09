### 思路
刚开始理解的过于简单了，想成了简单的进制转换，没有关注到不同点，这个不同点就是，十进制中的10写作10，而26进制中的26写作Z，这就需要做出两点对应的改变：
    1，取余值为0时，将余数由0改为26；
    2，同时，为了保证上一位-1，比如26的高位数应该是0而不是1，可以借助n--实现。
详见 [windiang](https://leetcode-cn.com/problems/excel-sheet-column-title/solution/xiang-xi-tong-su-de-si-lu-fen-xi-by-windliang-2/) 的解题
### 代码
```
class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while(n>0){
            char insert='A'+n%26-1;
            if(n%26==0) insert='Z', n--; //这句话很重要，因为没有0，这里的26相当于0，所以要单独拿出来判断
                                        //另外，n--理解透 
            ans.insert(0, 1, insert);
            n=n/26;         
        }
        return ans;
    }
};
```
