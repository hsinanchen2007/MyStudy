先进行异或，转换成二进制形式的字符串，然后得出字符串中'1'出现的个数就可以了


public int HammingDistance(int x, int y)
        {
            return Convert.ToString(x ^ y, 2).Split(new char[] { '1' }).Length-1;
        }