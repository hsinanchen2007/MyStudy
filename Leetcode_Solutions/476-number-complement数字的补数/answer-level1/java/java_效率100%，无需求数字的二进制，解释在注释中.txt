![image.png](https://pic.leetcode-cn.com/555340092ac7ddb5ab3d3229e0e0345deb4d10ed670ef6d8406951602a9db86d-image.png)
```
class Solution {
    public int findComplement(int num) {
        /*找到数字所在的区间[2^(i-1), 2^i]
          找到上区间，然后减一，取得是全一
          这样num与max-1异或后就是所需要的结果
          例子：5的补数为2，5^2=7，找到5的区间在[4,8],然后8-1=7，得到7
          所以5的补数2=5^7,同理任何数均可如此处理。
          注意：数字类型转换，浮点型和整型。
        */ 
        double max = 0;
        // 循环找到上限
        for(int index = 0; num >= max; index++) {
            max = Math.pow(2, index);
        }
        // 上限减一取的此区间2进制为全一的数
        int res = (int)(max - 1);
        return num ^ res;
    }
}
```

