public class Solution {
    public int CalPoints(string[] ops) {
    //这里是需要长度可变，可删减结尾项的，栈，跟链表都可行。
       List<string> a=new List<string>();
    //存储结果值
        int sum=0;
    //没什么可说的，循环判断每一项的值。
        for(int i=0;i<ops.Length;i++)
        {
        //用多重if也行，但switch效率更好些。
            switch(ops[i])
            {
            //这样处理完毕后，里面的每一项都是有效分值（无效的已经RemoveAt出去了）
                case "C":a.RemoveAt(a.Count-1);break;
                case "D":a.Add((int.Parse(a[a.Count-1])*2).ToString());break;
                case "+":a.Add((int.Parse(a[a.Count-1])+int.Parse(a[a.Count-2])).ToString());break;
                default:a.Add(ops[i]);break;
            }
        }
    //将所有有效分值相加，即为最终得分
        for(int j=0;j<a.Count;j++)
        {
            sum+=int.Parse(a[j]);
        }
        return sum;
    }
}