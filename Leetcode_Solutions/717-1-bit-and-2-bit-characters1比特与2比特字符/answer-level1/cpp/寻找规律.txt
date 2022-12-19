### 解题思路
此处撰写解题思路
因为以0终止的字符串必定可以被表示，所以可以看倒数第二个0和最后一个0之间差了多少个1，偶数个1即可以
如果只有最后一个0，则看一共有多少个1，偶数个即可以
### 代码

```cpp
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int l = bits.size()-1;
        int n;
        int flag = 0;
        for(int i = l-1;i>=0;i--)
        {
            n = i;
            if(bits[i]==0)
            {
                flag = 1;
                break;
            }
        }
        if(flag==1)
        {
            int num = l-n-1;
            if(num%2==0)
                return true;
            else
                return false;
        }
        else
        {
            if(l%2==0) return true;
            else return false;
        }
    }
};
```