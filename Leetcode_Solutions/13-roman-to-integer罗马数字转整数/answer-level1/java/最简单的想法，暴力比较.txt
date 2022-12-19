### 解题思路
从字符串s中依次取2个字符一组比较，2个发现没有，就单个比较，说明不特殊。
非常暴力，非常好想。
### 代码

```java
class Solution {
    public int romanToInt(String s) {
        
        int[] num = new int[] {1000,900,500,400,100,90,50,40,10,9,5,4,1};
		String[] roman = new String[] {"M", "CM", "D", "CD", "C", 
				"XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        int ans = 0;
        int i ,j;
        for(i = 0; i < s.length() ; )
        {
            if(i < s.length() - 1) 
            {
            	for(j = 0 ;j < 13; j++)
                {
                    if(s.substring(i,i+2).intern() == roman[j])
                    {
                        ans = ans + num[j];
                        i = i + 2;
                        break;
                    }
                    
                } 
                if(j == 13)
                {
                    for(j = 0;j < 13; j++)
                    {
                         if(s.substring(i,i+1).intern() == roman[j])
                         {
                             ans = ans + num[j];
                             i = i + 1;
                             break; 
                         }
                    }
                }
            }
            else
            {
            	for(j = 0;j < 13; j++)
                { 
         
            		if(s.substring(i,i+1).intern() == roman[j])
                     {
                         ans = ans + num[j];
                         i = i + 1;
                         break; 
                     }
          
                }
            }
            
        }
        
        return ans;
    }
}
```