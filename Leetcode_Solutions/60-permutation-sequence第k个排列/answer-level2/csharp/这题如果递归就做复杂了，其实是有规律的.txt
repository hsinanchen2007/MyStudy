假设n=5,k=35,
n为5的全排列就是首位为1-5的如下排列的所有
1_,_,_,_2_,_,_,_3_,_,_,_4_,_,_,_5_,_,_,_每个各有24个排列，组成12345的全排列
由于k=35<48,也就是说第35个肯定在首位为2的全排列里边,所以第一个取2。
接下来就是考虑剩下1345这四个数的全排列里边取第k=35-24=11个，
1_,_,_3_,_,_4_,_,_5_,_,_每个各有6个排列，组成1345的全排列，
由于k=11<12,也就是说第11个肯定在首位为3的全排列里边，所以第二个数取3
接下来就是考虑剩下145这三个数的全排列里边取第k=11-6=5个，
1_,_4_,_5_,_每个各有2个排列，组成145的全排列
由于k=5<6,也就是说第5个肯定在首位为5的全排列里边，所以第三个数取5
接下来就是考虑剩下14这两个数的排列里边取第k=5-4=1个
1_4_每个各有1个排列，组成14的排列，
由于k=1,所以第四个数取1
最后加上剩下的最后一个4，结果就是23514
结束。


C#:
private static int jiechen(int n)
        {
            if (n <= 1) return n;
            return n * jiechen(n - 1);
        }
        public static string GetPermutation(int n, int k)
        {
            List<int> leftlist = new List<int>();
            for (int i = 1; i <= n; i++)
                leftlist.Add(i);
            //leftlist剩余需要找的个数
            string forreturn = "";
            while (leftlist.Count> 1)
            {
                int jiechenval = jiechen(n-1);
                double shang = k * 1.0 / jiechenval;
                if(shang%1!=0)
                    shang = 1 + Math.Truncate(shang);
                int removeindex = (int)shang - 1;
                forreturn += leftlist[removeindex];
                leftlist.RemoveAt(removeindex);
                k = k - removeindex * jiechenval;
                n--;
            }
            forreturn += leftlist[0].ToString();
            return forreturn;
        }