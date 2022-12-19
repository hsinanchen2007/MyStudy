/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/20
 *
 * 解题思路: 进制转换基本都一样 注意0和负数，负数要加上-，然后按照正数来处理    连除存储余数，然后倒叙拼接起来
 *
 */
```
 public String convertToBase7(int num) {
    StringBuilder sb = new StringBuilder();
    int flag = num >= 0? 1:-1;
    num = Math.abs(num);

    if(num == 0){
        sb.append(0);
    }
    while(num != 0){
        sb.append(num%7);
        num = num / 7;
    }
    if(flag < 0){
        sb.append("-");
    }
    return sb.reverse().toString();
}
```