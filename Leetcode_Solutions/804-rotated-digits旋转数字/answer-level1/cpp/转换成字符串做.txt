![image.png](https://pic.leetcode-cn.com/6c9fc8c8cc3fdfe9dc7a9a1545c4505e6f5372d2707e5ec93fcd67a27618464f-image.png)

```
class Solution {
public:
    bool match(int num)
    {
        string str = to_string(num);
        string  str1(str);//str1为str的副本

        for(int i =0; i<str1.size(); i++)
        {
            switch(str1[i])
            {

            case '0':
                str1[i]='0'; 
                break;
            
            case '1':
                str1[i]='1'; 
                break;
            
            case '2':
                str1[i]='5'; 
                break;
            
            case '5':
                str1[i]='2'; 
                break;
            
            case '6':
                str1[i]='9'; 
                break;
            
            case '8':
                str1[i]='8'; 
                break;
            
            case '9':
                str1[i]='6'; 
                break;
            default:
                str1[i]='#';//当是其他数字时,不是好数,赋值这个字符位'#',后面再判断
                break;
            }
        }
        if(str!=str1 && str1.find('#')==-1)//满足改变后的字符串和之前的不不相等,且不含#,则为true
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int rotatedDigits(int N) 
    {
        int count = 0;//count用来计数
        int num = 0;
        while(num<N+1)
        {
            if(match(num))
            {
                cout<<num<<" ,";
                count++;
            }
            num++;
        }
        return count;
    }
};
```
