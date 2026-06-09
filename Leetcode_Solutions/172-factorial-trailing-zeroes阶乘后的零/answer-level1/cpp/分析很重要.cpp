### 解题思路
思路比代码更重要啊，将所有数分解为最小的质数，发现只有2和5相乘得到10
问题也就成为统计1—n中所有数中包含2和5的个数
明显2比5多，最终成为统计5的个数

### 代码

```cpp
class Solution {
public:
    int trailingZeroes(int n) {
        int ret=0;
        int i=1;
        while(true)
        {
            int count=n/pow(5,i);
            i++;
            ret+=count;
            if(count==0)break;
        } 
        return ret;
    }
};
```