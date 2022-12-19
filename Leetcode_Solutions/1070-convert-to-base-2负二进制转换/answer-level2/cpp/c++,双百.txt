### 解题思路
![image.png](https://pic.leetcode-cn.com/b89da16981385a478b56abe7ad981ec1505cdc3c6c0d77b85a38504b5805c7fd-image.png)
先化为二进制，然后再化为负二进制。
主要思想是，负二进制的奇数位和二进制相同，二进制偶数位为1，负二进制的该为和后一位为1.
如1111（二进制）=(1000+0100+0010+0001)二进制=（11000+0100+0110+0001）负二进制
然后负二进制相加，进位规则见代码

### 代码

```cpp
class Solution {
public:
    string baseNeg2(int N) {
        vector<bool> vec;
        string str;
        do{
          vec.push_back(N%2);
          N/=2;  
        }while(N);
        int flag=0;
        for(int i=0;i<vec.size();i++){
            str+=(flag+vec[i])%2+'0';
            if(flag&&vec[i])flag=1;
            else flag=(flag+vec[i])*(i%2);
        }
        if(flag){
            if(vec.size()%2)str+="11";
            else str+='1';
        }
        reverse(str.begin(),str.end());
        return str;
    }
};
```