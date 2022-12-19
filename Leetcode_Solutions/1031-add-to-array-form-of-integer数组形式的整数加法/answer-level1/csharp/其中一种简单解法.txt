最正常的思路就是先确认哪一个是长数组，哪一个是断数组，确认完之后开始相加
```
 IList<int> result = new List<int>();

            char[] one = K.ToString().ToCharArray();
            char[] another = new char[A.Length];
            for (int i = 0; i < A.Length; i++)
            {
                another[i] =(char)( A[i] + '0');
            }
           


            int Max = one.Length > another.Length ? one.Length : another.Length;
            char[] MaxOne = Max == one.Length ? one : another;
            char[] MinOne = Max != one.Length ? one : another;
            int carry = 0;

            for (int i = Max-1; i>=0;i--)
            {
                int  temp = i < MaxOne.Length - MinOne.Length ? 0 : MinOne[i - Max + MinOne.Length] - '0';
                temp+= (MaxOne[i] - '0');
                if (temp >= 10)
                {
                    MaxOne[i] = (char)(temp-10 + '0');
                    carry = 1;
                }
                else
                {
                    MaxOne[i] = (char)(temp + '0');
                    carry = 0;
                }

            }

            if (carry == 1)
            {
                result.Add(1);
            }

            foreach (var item in MaxOne) result.Add(item-'0');



            foreach (var item in result)
            {
                Console.WriteLine(item);
            }
```
