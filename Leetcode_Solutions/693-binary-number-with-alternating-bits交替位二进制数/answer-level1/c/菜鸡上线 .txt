### 解题思路
找到左移位数再判断
![QQ图片20200326103529.png](https://pic.leetcode-cn.com/fc8576ec57ec21062b8431fc07b13f91f1bc56505e20b496153ae00a9e902822-QQ%E5%9B%BE%E7%89%8720200326103529.png)

### 代码

```c
bool hasAlternatingBits(int n)
{
    int i=1;
    int m=n;
    while(m/2)
    {
        m=m/2;
        i++;  
    }
    int t;
    int flag=-1;
    for(t=0;t<i;t++)
    {
        if(n&(1<<t))
        {
            if(flag==1)
            {
                return false;
            }
            else
            {
                flag=1; 
            }
           
        }
        else
        {
            if(flag==0)
            {
                return false;
            }
            else
            {
                flag=0;
            }
        }
    }
    return true;
}
```