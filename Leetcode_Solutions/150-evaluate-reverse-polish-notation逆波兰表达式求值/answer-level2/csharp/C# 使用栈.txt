### 解题思路
参考[逆波兰式](https://baike.baidu.com/item/%E9%80%86%E6%B3%A2%E5%85%B0%E5%BC%8F/128437)中的下面这段文字
```
下面以(a+b)*c为例子进行说明：
(a+b)*c的逆波兰式为ab+c*，假设计算机把ab+c*按从左到右的顺序压入栈中，并且按照遇到运算符就把栈顶两个元素出栈，执行运算，得到的结果再入栈的原则来进行处理，那么ab+c*的执行结果如下：
1）a入栈（0位置）
2）b入栈（1位置）
3）遇到运算符“+”，将a和b出栈，执行a+b的操作，得到结果d=a+b，再将d入栈（0位置）
4）c入栈（1位置）
5）遇到运算符“*”，将d和c出栈，执行d*c的操作，得到结果e，再将e入栈（0位置）
经过以上运算，计算机就可以得到(a+b)*c的运算结果e了。
```

### 代码

```csharp
public class Solution {
    public int EvalRPN(string[] tokens) {
        Stack<int> s = new Stack<int>();
        int i = 0;
        
        while(i<tokens.Length)
        {
            int tmp = 0;        
            if(int.TryParse(tokens[i], out tmp))
            {
                s.Push(tmp);
            }
            else
            {
                var v2 = s.Pop();
                var v1 = s.Pop();
                if(tokens[i] == "+")
                {
                    s.Push(v1+v2);
                }
                else if(tokens[i] == "/"){
                    s.Push(v1/v2);
                }
                else if(tokens[i] == "-")
                {
                    s.Push(v1-v2);
                }
                else if(tokens[i] == "*")
                {
                    s.Push(v1*v2);
                }
            }

            i++;
        }

        return s.Pop();
    }
}
```