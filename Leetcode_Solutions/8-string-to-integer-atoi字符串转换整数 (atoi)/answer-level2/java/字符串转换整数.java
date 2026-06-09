### 解题思路
#### 主要是判别越界的边界问题

### 代码

```java
class Solution {
    public int myAtoi(String str) {
        //判断越界：字符串转整数 ans=ans*10+digit,越界即出现ans*10+digit>Interger.Max_Value,所以(ans>interger.amx_value-digit)/10就是越界
        // int flag=1;
        // int ans=0;
        // int index=0;//遍历字符串的指针
        // char[] schar=str.toCharArray();
        // int n=schar.length;
        
        // while(index<n&&schar[index]==' '){
        //     index++;//去掉前空格
        // }
        // if(index==n){return 0;}//提前结束
        // if(schar[index]=='-'){
        //     flag=-1;//确定首字符的正负号
        //     index++;
        // }
        // else if(schar[index]=='+'){//遇到正号
        //     index++;
        // }

        // while(index<n&&schar[index]>='0'&&schar[index]<='9'){//是连续数据
        //        int digit=schar[index]-'0';
        //        if(ans>(Integer.MAX_VALUE-digit)/10){ //越界
        //            return flag==1?Integer.MAX_VALUE:Integer.MIN_VALUE;
        //        }
        //        ans=ans*10+digit;
        //        index++;
        // }
        // return flag*ans;
     //方法2：可以使用系统判别是否是数字函数
        boolean negflag=false;//负号存在标志
        int ans=0;
        int index=0;//遍历字符串的指针
        char[] schar=str.toCharArray();
        int n=schar.length;
        
        while(index<n&&schar[index]==' '){
            index++;//去掉前空格
        }
        if(index==n){return 0;}//提前结束
        if(schar[index]=='-'){
            negflag=true;//确定首字符的正负号
            index++;
        }
        else if(schar[index]=='+'){//遇到正号
            index++;
        }

        while(index<n&&Character.isDigit(schar[index])){//是连续数据
               int digit=schar[index]-'0';
               if(ans>(Integer.MAX_VALUE-digit)/10){ //越界
                   return negflag? Integer.MIN_VALUE:Integer.MAX_VALUE;
               }
               ans=ans*10+digit;
               index++;
        }
        return negflag? -ans:ans;
    }
   

}
```