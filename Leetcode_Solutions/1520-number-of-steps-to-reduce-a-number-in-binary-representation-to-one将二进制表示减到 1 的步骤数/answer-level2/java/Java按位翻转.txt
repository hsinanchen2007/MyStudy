### 解题思路
题目的来源是数学的角谷猜想。角谷猜想是指对于任意一个正整数，如果是奇数，则乘3加1，如果是偶数，则除以2，得到的结果再按照上述规则重复处理，最终总能够得到1。例如，假定初始整数为5，计算过程分别为16、8、4、2、1。 官方进行了简化，奇数仅加1，降低了难度，但是操作从整数变成了字符串形式。

看到题目第一个想到的就是二进制转为十进制，然后进行运算。瞅了一眼题目提示，s.length<=500，转换出来的数据太大了，于是直接放弃了这一想法。

仔细思考了一会后觉得可以用按位翻转的思想进行模拟。最后一位是1，加1之后就变成0，同时进位；如果倒数第二位也是1，加上进位的1也变成0，再进位。这就相当于将每一位上的1翻转为0，层层向上翻转，遇到第一个0将其翻转为1即完成了整个进位过程。

对于用例“11111”来说，全部翻转为0之后前面应该还有个1才能保证值不变，我在字符串前面添加一个‘0’。

这里有一个特殊情况：“10”。对于“10”来说舍去“0”已经变成“1”了，只需要处理一次就行，这个时候对“01”进行特判输出即可。

我的csdn博客是 https://blog.csdn.net/qq_42582489/article/details/105325407

### 代码

```java
class Solution {
    public int numSteps(String s) {
        int len=s.length();
        if(len==1){
            return 0;
        }
        else
        {
            int num=0;
            StringBuilder str=new StringBuilder("0");
            str.append(s);
            while(true)
            {
                len=str.length();
                if(len==1||(len==2&&str.charAt(0)=='0'&&str.charAt(1)=='1')){
                    break;
                }
                else{
                    if(str.charAt(len-1)=='1')
                    {
                        for(int i=len-1;i>=0;i--)
                        {
                            if(str.charAt(i)=='0')
                            {
                                str.setCharAt(i,'1');
                                num++;
                                break;
                            }
                            else
                            {
                                str.setCharAt(i,'0');
                            }
                        }
                    }
                    else
                    {
                        str.deleteCharAt(len-1);
                        num++;
                    }
                }
            }
            return num;
        }
    }
}
```