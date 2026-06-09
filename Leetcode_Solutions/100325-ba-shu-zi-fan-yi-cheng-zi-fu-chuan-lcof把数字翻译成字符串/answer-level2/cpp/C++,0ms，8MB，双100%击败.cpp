### 解题思路
先把数字转为string，然后简单的迭代即可算出。
有点像之前做过的爬楼梯问题。

### 代码

```cpp
class Solution {
public:
    int total(string n){
        if(n.size()<=1)
        return 1;
        if(n[0]=='1'||n[0]=='2'&&n[1]<'6')
        return total(n.substr(1))+total(n.substr(2));
        return total(n.substr(1));
    }
    int translateNum(int num) {
       string n=to_string(num);
       return total(n);
    }
};
```