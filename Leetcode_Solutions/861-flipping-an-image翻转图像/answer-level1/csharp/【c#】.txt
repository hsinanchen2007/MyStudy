解决思路：
翻转和反转同步执行：
首先遍历交错数组中的每一个数组
然后遍历数组中的每一个数，在遍历时采用倒序遍历，储存进数组时采用正序这样就实现了翻转
将数字传入分支传入1则反转为0，传入0则反转为1

public class Solution 
{
    public int[][] FlipAndInvertImage(int[][] A) 
    {
        //创建交错数组储存对象，用于储存翻转及反转后的图片数组
        int[][] imageReversal = new int[A.GetLength(0)][];
        /*
        根据题目意思首先应该翻转图片
        遍历每一数组逐行替换然后传递入imageReversal数组中
        */
        int allNum = 0;//储存到第几个数组
            
        //遍历每一个数组
        foreach (int[] intArray in A)
        {
            //创建数组储存对象用于储存翻转及反转后的数组
            int[] numberArrat = new int[intArray.Length];
            //数组中的数索引
            int num = 0;
            //倒序遍历数组中的每一个数实现翻转
            for (int i = intArray.Count() - 1; i >= 0; i--)
            {
                switch (intArray[i])
                {
                    case 0://如果为0则反转为1
                        numberArrat[num] = 1;
                    break;
                    case 1://如果为1反转为0
                        numberArrat[num] = 0;
                    break;
                }
                num++;
            }
            imageReversal[allNum] = numberArrat;
            allNum++;
        }
        return imageReversal;
    }
}

（ps：互相交流，共同进步，有不对的请指出，有更好的解决方法方便的话也请说明，谢谢）