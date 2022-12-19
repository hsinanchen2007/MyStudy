### 解题思路
根据列出的罗马字符及其对应的数值，进行分情况讨论。
1.首先将字符串转化为字符数组，对字符数组遍历
2.因为题目中有解释说，当I在V和X的左边时，X在L和C的左边时，C在D和M的左边时，会有累加和的效果，所以我想到对字符的下一位进行判定，在判定使，要考虑到该字符是否为最后一位，如果是最后一位，则不会出现上面所描述的累加和的现象。
3.当出现左右可以累加的时候，字符数组的索引i (这里我定义的字符数组索引为i) 要加1，跳过下一个字符，继续进行后面字符的判定。

今天第一次用LeetCode，感觉挺好，第一次写题解，继续加油！

### 代码

```java
class Solution {
    public int romanToInt(String s) {
        int strLength = s.length();
        char[] ch = new char[strLength];
        int num = 0;
        ch = s.toCharArray();
        for(int i=0;i<ch.length;i++){
            if(ch[i] == 'I'){
                if(i+1<ch.length&&ch[i+1] == 'V'){
                    num += 4;
                    i++;
                    continue;
                }else if(i+1<ch.length&&ch[i+1] == 'X'){
                    num += 9;
                    i++;
                    continue;
                }
                else{
                    num+=1;
                    continue;
                }
            }else if(ch[i] == 'V'){
                num +=5;
            }else if(ch[i] == 'X'){
                if(i+1<ch.length&&ch[i+1] == 'L'){
                    num +=40;
                    i++;
                    continue;
                }else if(i+1<ch.length&&ch[i+1] == 'C'){
                    num +=90;
                    i++;
                    continue;
                }else {
                    num +=10;
                    continue;
                }
            }else if(ch[i] == 'L'){
                num += 50;
            }else if(ch[i] == 'C'){
                if(i+1<ch.length&&ch[i+1] == 'D'){
                    num +=400;
                    i++;
                    continue;
                }else if(i+1<ch.length&&ch[i+1] == 'M'){
                    num +=900;
                    i++;
                    continue;
                }else {
                    num += 100;
                    continue;
                }
            }else if(ch[i] == 'D'){
                num += 500;
                continue;
            }else if(ch[i] == 'M'){
                num += 1000;
                continue;
            }
        }
        return num;
    }
}
```