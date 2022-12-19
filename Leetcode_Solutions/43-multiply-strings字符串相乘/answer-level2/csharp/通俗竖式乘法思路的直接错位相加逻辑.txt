999*219的乘法错位相加如下：
  8991
  999
1998
-------
218781

乘法就是第二个数的每一个数字与第一个数相乘，然后把这些乘积相加
关于相加的第一个思路是后面的乘积补足0，然后调用415字符串相加的算法循环相加就可以了。
这里只写不补0，不用415字符串相加，直接错位相加的逻辑。
private static string cuowei(string[] numbers)
        {
            string forreturn = "";
            int[] zhizhen = new int[numbers.Length]; //定义乘积的指针，用来相加取数字用
            for(int i=0;i<zhizhen.Length;i++)
            {
                zhizhen[i] = numbers[i].Length - 1;//初始状态，从最后一个位置累加
            }
            int count = 1;//用来判断选数的flag
            int k = 0;//进位用
            while (zhizhen[zhizhen.Length - 1] >= 0)//最后一个乘积的指针到-1的时候整个相加就结束了，因为被乘数是固定的，所以不可能出现最后一个指针到-1，上面的指针还没到-1的情况。
            {
                int forinsert = 0;//用来累加每一竖列的数
                for (int i = 0; i < numbers.Length; i++)
                {
                    if ( i< count)//count做完一列加一次
                    {        
                            //第一次，count为1，所以第一列只选第一个乘积的指针选取的值，其实就是后面补0的意思
                            //第二次，count为2，所以第二列只选第一个和第二个乘积的指针选取的值，也就是后面补一个0的意思
                            //第三次，count为3，选第一二三的乘积指针选取的值，不用补0了
                        if (zhizhen[i] >= 0)
                            forinsert += Convert.ToInt32(numbers[i][zhizhen[i]].ToString());
                        if (zhizhen[i] >= 0) 
                            zhizhen[i]--;
                    }
                }
                forinsert += k;//一列进一次
                if(zhizhen[zhizhen.Length-1]>=0)
                {
                    k = forinsert / 10;
                    forinsert = forinsert % 10;
                }
                forreturn= forreturn.Insert(0, forinsert.ToString());
                count++;
            }
            return forreturn;
        }
