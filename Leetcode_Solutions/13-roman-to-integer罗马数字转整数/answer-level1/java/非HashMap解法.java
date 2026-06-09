### 解题思路
可能水平有限，我不知道如何用HashMap,Map<char, Integer>不合法，不知道用什么类包装char基本数据类型，自己琢磨出另一种方法。
1.getValue(char c)得到字符c的值
2.字符串转换成字符数组，如果字符小于后一位字符值，两次一并计算（i++），防止越界加上i < nums.length-1

### 代码

```java
class Solution {
    public int romanToInt(String s) {
        char[] nums = s.toCharArray();   //字符串转换成字符数组
        int sum = 0;          
        for(int i = 0; i < nums.length; i ++){
            if(i < nums.length - 1 && getValue(nums[i]) < getValue(nums[i+1])) 
            //&&前：条件防止数组越界
            //&&后：字符和后一位比较是否较小
            {
                sum += getValue(nums[i+1]) - getValue(nums[i]);                            
                i ++;       //两个字符一起运算，多移一位
            }else{
                sum += getValue(nums[i]);
            }    
        }
        return sum;
    }

    private static int getValue(char c){
        switch(c){
            case 'I': return 1; 
            case 'V': return 5; 
            case 'X': return 10; 
            case 'L': return 50; 
            case 'C': return 100; 
            case 'D': return 500; 
            case 'M': return 1000; 
            default: return 0;  
         //一定加上default，值随便写，不然报错，我也不知道为啥，可能是语法吧(┬＿┬)
        }
    }
}
```