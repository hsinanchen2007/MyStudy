虽然写了两层循环，但实际上它们一共的复杂度是O(last.size())的（两层一块把i每次加一直到last.size()）。
然后巧妙利用了一下C++字符本质为一字节数的特性……就不用什么toString()了（当然也是看了答案不会出现两位数个连续数字）
```
class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        string res; string last=countAndSay(n-1);
        char times;
        for(int i=0; i<last.size();++i){
            times='1';
            while(last[i]==last[i+1]){
                ++times;
                ++i;
            }
            res+=times;
            res+=last[i];
        }
        return res;
    }
};
```
