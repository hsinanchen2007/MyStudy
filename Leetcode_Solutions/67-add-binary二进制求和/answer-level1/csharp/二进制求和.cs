**思路1：** 从两个字符串的尾数开始向前计算，详情在代码注释中（代码有点冗长，思路2优化了下，思路1记录用可以不看...）。
```
public class AddBinary_67
    {
        public string AddBinary(string a, string b)
        {
            //保证a字符串的长度不小于b的长度，为方便后面的计算
            if (b.Length > a.Length)
            {
                string temp = a;
                a = b;
                b = temp;
            }
            //声明一个长度位a.Length+1长度的list
            //因为结果的长度最大就是a.Length+1(例如："11" + "1")
            List<char> result = new List<char>(a.Length + 1);

            //carry为每次位相加运算的进位
            int carry = 0;
            int i = a.Length - 1;
            int j = b.Length - 1;
            //从短字符串的尾数开始加，一直到短字符串的头部
            for (; j >= 0; i--, j--)
            {
                int aElement = int.Parse(a[i].ToString());
                int bElement = int.Parse(b[j].ToString());

                int tempResult = carry + aElement + bElement;

                //计算进位，并将当前位计算结果更新到result中
                carry = GetCarryAndUpdateResult(result, tempResult);
            }
            //如果短字符串的头部加运算没有进位就可以结束运算了
            if (carry == 0)
            {
                //因为list是从尾数倒者放的，需要反转list元素
                result.Reverse();
                return a.Substring(0, i + 1) + new string(result.ToArray<char>());
            }
            //存在进位，需要继续在长字符串a剩下的数中继续加法运算
            else
            {
                for (; i >= 0; i--)
                {
                    int aElement = int.Parse(a[i].ToString());
                    int tempResult = carry + aElement;

                    carry = GetCarryAndUpdateResult(result, tempResult);
                }
                //如果有进位，直接在结果第一位加1
                if (carry != 0)
                {
                    result.Add('1');
                }

            }
            result.Reverse();
            return new string(result.ToArray<char>());
        }

        private int GetCarryAndUpdateResult(List<char> result, int tempResult)
        {
            //carry为进位
            int carry = 0;

            switch (tempResult)
            {
                case 0:
                    carry = 0;
                    result.Add('0');
                    break;
                case 1:
                    carry = 0;
                    result.Add('1');
                    break;
                case 2:
                    carry = 1;
                    result.Add('0');
                    break;
                case 3:
                    carry = 1;
                    result.Add('1');
                    break;
            }

            return carry;
        }
    }
```

**思路2：** 思路1有多个并列的循环看的人有点难受，其实可以直接一遍遍历就可以，具体见如下代码
```
public class AddBinary_67
    {
        public string AddBinary(string a, string b)
        {
            //声明一个长度位a.Length+1长度的list
            //因为结果的长度最大就是a.Length+1(例如："11" + "1")
            List<char> result = new List<char>(a.Length + 1);

            //carry为每次位相加运算的进位
            int carry = 0;

            for (int i = a.Length - 1, j = b.Length - 1; i >= 0 || j >= 0; i--, j--)
            {
                int aElement = i >= 0 ? int.Parse(a[i].ToString()) : 0;
                int bElement = j >= 0 ? int.Parse(b[j].ToString()) : 0;
                int tempResult = carry + aElement + bElement;

                //计算进位，并将当前位计算结果更新到result中
                carry = GetCarryAndUpdateResult(result, tempResult);
            }
            //如果最后一次运算有进位，需要添加一个"1"
            if (carry == 1)
            {
                result.Add('1');
            }

            //因为list是从尾数倒着添加的，需要反转list元素
            result.Reverse();
            return new string(result.ToArray<char>());
        }

        private int GetCarryAndUpdateResult(List<char> result, int tempResult)
        {
            //carry为进位
            int carry = 0;

            switch (tempResult)
            {
                case 0:
                    carry = 0;
                    result.Add('0');
                    break;
                case 1:
                    carry = 0;
                    result.Add('1');
                    break;
                case 2:
                    carry = 1;
                    result.Add('0');
                    break;
                case 3:
                    carry = 1;
                    result.Add('1');
                    break;
            }

            return carry;
        }
    }
```

