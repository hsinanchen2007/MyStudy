问题非常简单,只要不漏掉循环后进位产生新数组的情况就ok
```
if (digits==null || digits.Length==0)
        {
            return digits;
        }
        digits[digits.Length - 1]++;//加一操作
        int upgrade = 0;//进位
        for (int i = digits.Length-1; i >=0; i--)
        {
            digits[i] = digits[i] + upgrade;//加上进位 得到本次位上的数字
            //不满足进位 直接返回
            if (digits[i] < 10)
            {
                return digits;
            }
            else {
                upgrade = digits[i] / 10;//是否进位
                digits[i] = digits[i] % 10;//取余数
            }
        }
        //数组首位进位,产生了更长的数组
        if (upgrade != 0)
        {
            int[] result = new int[digits.Length + 1];//创建新数组
            result[0] = 1;//给首位赋值
            //将其余位的值复制到新数组上
            for (int i = 0; i < digits.Length; i++)
            {
                result[i + 1] = digits[i];
            }
            return result;
        }
        else {
            return digits;
        }
```