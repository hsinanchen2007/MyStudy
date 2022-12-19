### 解题思路
 转成字符串替换是代码量相对少的 并且大多语言有提供替换第一个指定字符的function 但c#没有 会全部替换 真的是蠢 而且数据类型的转换会增加时耗 -。-！！和增加内存消耗 我还是选择取出每一位的值然后再加回去

### 代码

```csharp
public class Solution {
    public int Maximum69Number (int num) {
    //    string str = num.ToString();
    //    char[] c = str.ToCharArray();
    //    int index = str.IndexOf("6");
    //    if(index != -1)
    //    {
    //        c[index] = '9';
    //        return int.Parse(c);
    //    }else return num;
       List<int> nums = new List<int>();
       int sum = 0;
       int mul = 1;
       while(num / mul > 0)
       {
           nums.Add(num / mul % 10);
           mul *= 10; 
       }
       bool first = true;
       for(int i = nums.Count - 1; i >= 0; i--)
       {
            mul /= 10;
            if(nums[i] == 6 && first)
            {
                sum += 9 * mul;
                first = false;
            }
            else
                sum += nums[i] * mul;
       }
       return sum;
    }
}
```