### 解题思路
找规律找出来的，没有开辟空间，直接在原字符串上添加有规律的下标。对于第一行和最后一行来说，添加下标一定是,
                            ret+=s[k]; (i=0或者s.size()-1)
                            k=k+2*(numRows-1);
其中k是对原字符串的索引。
对于中间行来说，由于Z型变换在k和k+2x(numRows-1)之间还存在一个字符，这个字符也是有规律的。经过Z型变换后第i行的中间字符在原字符的（k-2xi)位置，因此对于中间行字符的添加顺序是
                            ret+=s[k-2*i];
                            ret+=s[k];(索引下标k<s.size()时有效)
### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        int n=s.size();
        string ret;
        for(int i=0;i<numRows;i++){
            ret+=s[i];
            int k = i+2*(numRows-1);
            if(i==0||i==numRows-1){
                while(k<n){
                    ret+=s[k];
                    k = k+2*(numRows-1);
                }
            }
            else {
                while(k<n||(k-2*i)<n){
                    ret+=s[k-2*i];
                    if(k<n)
                    ret+=s[k];
                    k=k+2*(numRows-1);
                }
            }
        }
        return ret;

    }
};
```