![image.png](https://pic.leetcode-cn.com/2b739033087375174925d6d8077f345ae084482b3b459d463991bd7fca363293-image.png)

```
class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
        return "1";     
        //递归描述序列
        string res="";
        string str=countAndSay(n-1);
        int i=0,j=0;//双指针判断前后字符是否相同
        while(str[i])
        {
             if(str[i]==str[j])
             {
               ++j;            
             }
             else
              {     
               res+=(j-i+48);//描述中的个数
               res+=str[i];//描述中的数字
               i=j;
               ++j;              
             }         
        }             
        return res;     
    }

};
```
