时间344 击败16.67%
空间33.3 击败100%


效率一般直接说思路

思路：想要max最小的关键就是不要让同类型的括号产生嵌套 所以只需要在产生嵌套的时候改变括号类型即（01互换）
问题来了如何判断产生嵌套了呢？很简单，当一个'('连续出现的时候不就是产生嵌套了吗
举例来说：(())观察前两个字符 '('连续出现自然就产生了嵌套 而且按题目所说给定参数seq已经是有效括号了 所以不用再验证原字符串的有效性了
看到这里的小伙伴 可以自己去试试啦

```csharp
public class Solution {
    public int[] MaxDepthAfterSplit(string seq) {
        int count = 0;
        int[] ans = new int[seq.Length];
        for(int i = 0; i < seq.Length; i++){
            if(seq[i] == '('){
                count++;
                ans[i] = count % 2 == 0 ? 1 : 0;
            }else if(seq[i] == ')'){
                ans[i] = count % 2 == 0 ? 1 : 0;
                count--;
            }
        }
        return ans;
    }
}
```