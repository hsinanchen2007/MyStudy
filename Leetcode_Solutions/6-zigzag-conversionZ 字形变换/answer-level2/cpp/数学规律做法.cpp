### 解题思路
根据图上我们可以看到，实际上可以把图像不当做‘Z’来看待，可以看作是很多个没有重叠元素的斜体的‘V’组成，这样的话就可以利用v的相似性做题啦！
整体上按行把每个字符填到字符串后面，对numRows为1的情况可以不用做，直接返回原字符串即可。
其他情况下，可以发现，每个‘V’除了第一行和最后一行是一个元素以外，其它行都是两个元素，而对于两个元素的行，我们可以发现实际上当前的情况也是一个‘V’，与最大的‘V’完全相似，只是边的比例不同，可以以与大‘V’相同的规律求的相隔元素数目。

### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
    if(numRows == 1)
        return s;
    int vnum = numRows*2-2,tmpvnum;
    string res;
    int ind = 0;
    for(int i = numRows;i>0;i--){
        ind = numRows-i;
        tmpvnum = 2*i-2;
        while(ind<s.size()){
            res+=s[ind];
            if(i!=1&&i!=numRows&&ind+tmpvnum<s.size())
                res+=s[ind+tmpvnum];
            ind+=vnum;
        }
    }
    return res;
}
};
```