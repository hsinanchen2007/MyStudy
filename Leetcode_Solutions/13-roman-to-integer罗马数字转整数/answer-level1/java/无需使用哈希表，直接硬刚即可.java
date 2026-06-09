### 解题思路
仍然无需使用哈希表，只要搞清楚计算规则就可以了，就是要处理什么时候百分位、千分位的左侧是需要减的
关键是从后向前遍历，然后逐个增加值

### 代码

```java
class Solution {
    public int romanToInt(String s) {
        // 本题是intToRoman的逆运算
        // 因为不超过3999，所以可以使用一些截断的解题技巧
        // 比如循环到1-3999，哪个字符串相等就用哪个，这是一种变态的解题方法，但是可行，在复杂度3999的情况下是一个不错的选择
        // 但是更好的方法是逆运算就是拆解字符串
        if(s.equals("")){
            return 0;
        }
        int result = 0;
        for(int i=s.length()-1;i>=0;){
            char c = s.charAt(i);
            if(c == 'I'){
                result += 1;
                i--;
            }else if(c == 'V'){
                result += 5;
                while((--i)>=0 && (c=s.charAt(i)) == 'I'){
                    result--;
                }
            }else if(c == 'X'){
                result += 10;
                if((--i)>=0 && (c=s.charAt(i)) == 'I'){
                    result--;
                    i--;
                }
            }else if(c == 'L'){
                result += 50;
                if((--i)>=0 && (c=s.charAt(i)) == 'X'){
                    result -= 10;
                    i--;
                }
            }else if(c == 'C'){
                result += 100;
                if((--i)>=0 && (c=s.charAt(i)) == 'X'){
                    result -= 10;
                    i--;
                }
            }else if(c == 'D'){
                result += 500;
                if((--i)>=0 && (c=s.charAt(i)) == 'C'){
                    result -= 100;
                    i--;
                }
            }else if(c == 'M'){
                result += 1000;
                if((--i)>=0 && (c=s.charAt(i)) == 'C'){
                    result -= 100;
                    i--;
                }
            }
        }
        return result;
    }
}
```