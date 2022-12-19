![image.png](https://pic.leetcode-cn.com/324731913eb51360c386305f54c491ddd8e9fe5ad98dc924052605945e616af5-image.png)

双指针遍历

```
class Solution {
public:
    bool isStrobogrammatic(string num) {
        for(int i=0,j=num.size()-1;i<=j;i++,j--)
        {
            if(num[i]=='1'||num[i]=='0'||num[i]=='8')
            {
                if(num[i]!=num[j])
                    return false;
            }else if(num[i]=='6')
            {
                if(num[j]!='9')
                    return false;
            }else if(num[i]=='9')
            {
                if(num[j]!='6')
                    return false;
            }else{
                return false;
            }
        }
        return true;
    }
};
```
