### 解题思路
末尾为0 时， 操作加1 做除相当于长度-1
末尾为1时，操作加1，位数加1，相当于离末尾最近的一个0变成1，其后都为0.这里操作次数为加1的一步，以及将末尾几个0做除结束，并把长度减去0的个数。
若没有找到0，说明加1前全为1，加完后，长度多1，并且剩余原长度个数的0，操作分辨加1 再加把其后0除掉的次数即可。

### 代码

```cpp
class Solution {
public:
    int numSteps(string s) {
        int k=0; //统计次数
        
        // 偶数/2 相当于 右移一位  ,奇数+1 变偶数
        
        
        int len =s.size();
        
        
        while(len>1)
        {
            int i=len-1; //指向尾字符
            if(s[i]=='0')  // 偶数结尾
            {
                k++;
                len--;
            }

            else if(s[i]=='1')  // 寻找之前哪位为0
            {
                
                int before =1;
                while(i-before>=0)
                {
                    if(s[i-before]=='0') // 找到0位置
                    {
                        k++;
                        s[i-before]='1';
                        k+=before;   // 做除2 去掉进位后的0. before个0
                        len-=before;
                        
                        break;
                    }
                    
                    before++;
                }
                if(i-before==-1) //进位后多一位1最前面，后面全是0；
                {
                    k++;  // 加一后 总长加1，后全为0
                    k+=before;  //将位数0全部除尽
                    len=1;
                }
                
            }
        }
        
        return k;
        
        

    }
};
```