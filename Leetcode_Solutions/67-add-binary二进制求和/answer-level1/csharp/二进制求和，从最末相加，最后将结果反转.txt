自己写的比较麻烦，参考别人的方法写了一个

执行用时 :104 ms, 在所有 csharp 提交中击败了90.15%的用户
内存消耗 :24 MB, 在所有 csharp 提交中击败了9.80%的用户
```
public class Solution {
    public string AddBinary(string a, string b) {
        StringBuilder str = new StringBuilder();//记录相加后的字符串
        int carry = 0;//是否有进位，0表示没有进位，1表示有进位
        //判断两个字符串相加结果，从最末一个字符相加，位数不够补零
        for(int i = a.Length - 1,j = b.Length - 1;i >= 0 || j >= 0;i--,j--){
            int sum = carry;//记录两个数的和，如果前面两数相加有进位，默认是1，否则默认是0
            sum += (i >= 0 ? a[i] - '0' : 0);//如果i大于0，获取a中第i个元素，加到sum里，否则加0
            sum += (j >= 0 ? b[j] - '0' : 0);//如果j大于0，获取b中第i个元素，加到sum里，否则加0
            str.Append(sum % 2);//对2取模，将获取的值添加到str中
            carry = sum / 2;//对2取整，判断是否有进位，
        }
        if(carry == 1){
            str.Append(1));//判断最后是否有进位，有进位把1拼接进去
        }
        //字符串反转
        char[] charArr = str.ToString().ToCharArray();
        Array.Reverse(charArr);
        return new String(charArr);
        
    }
}
```